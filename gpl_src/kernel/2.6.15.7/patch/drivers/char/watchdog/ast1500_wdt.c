/*
 * linux/drivers/char/watdog/umvp2500_wdt.c
 * modified from drivers/char/watchdog/wdt.c
 *
 * Driver for GUC-UMVP2500 Watch Dog IP
 *
 * Copyright 1999 ARM Limited
 * Copyright (C) 2000 Deep Blue Solutions Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */                      
#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/poll.h>
#include <linux/interrupt.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/miscdevice.h>
#include <linux/watchdog.h>
#include <linux/fs.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/init.h>
#include <asm/hardware.h>
#include <asm/semaphore.h>
#include <asm/uaccess.h>
#include <asm/arch/platform.h>
#include <asm/arch/vic.h>
#if 1
#include <linux/platform_device.h>
#endif
#include <asm/arch/drivers/board_def.h> //For patch code

typedef unsigned char bool_T;

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

#define TRUE	1
#define FALSE	0


#define WDT_BASE_VA		ASPEED_WDT_VA_BASE

#define WDT_CntSts              (WDT_BASE_VA+0x00)
#define WDT_Reload              (WDT_BASE_VA+0x04)
#define WDT_Restart             (WDT_BASE_VA+0x08)
#define WDT_Ctrl                (WDT_BASE_VA+0x0C)
#define WDT_TimeOut             (WDT_BASE_VA+0x10)
#define WDT_Clr                 (WDT_BASE_VA+0x14)
#define WDT_RstWd               (WDT_BASE_VA+0x18)

#define SCU_BASE_VA (IO_ADDRESS(ASPEED_SCU_BASE))


#define UMVP_READ_REG(r)		(*((volatile unsigned int *) (r)))
#define UMVP_WRITE_REG(r,v)		(*((volatile unsigned int *) (r)) = ((unsigned int)   (v)))


#define WDT_CLK_SRC_EXT		0
#define WDT_CLK_SRC_PCLK	1

//Global Variables
#if 0
#define WD_TIMO 6			/* Default heartbeat = 6 seconds */
#else
//Intialize timeout to 30 seconds to catch system intialization errors.
//If everything is going well, link manager will tickle watchdog in time.
//After that, timeout can be set to other value which is best fit to current system state. 
#define WD_TIMO 40
#endif

static int heartbeat = WD_TIMO;
module_param(heartbeat, int, 0);
MODULE_PARM_DESC(heartbeat, "Watchdog heartbeat in seconds. (0<heartbeat<65536, default=" __MODULE_STRING(WD_TIMO) ")");

static int nowayout = WATCHDOG_NOWAYOUT;
module_param(nowayout, int, 0);
MODULE_PARM_DESC(nowayout, "Watchdog cannot be stopped once started (default=CONFIG_WATCHDOG_NOWAYOUT)");

static unsigned long wdt_is_open;
#if 0
static char expect_close;
#endif

//Function Declaration
int __init wdt_init(void);

#if 0
static irqreturn_t wdt_isr(int irq, void *devid, struct pt_regs *regs)
{
	/* clear timeout */
	UMVP_WRITE_REG(WDT_Clr, 1);

	vic_clear_intr(irq);

	return (IRQ_HANDLED);
}
#endif

void wdt_disable(void)
{
    register unsigned int regVal;
                                                                                     
    /* reset WDT_Ctrl[0] as 0 */
    regVal = UMVP_READ_REG(WDT_Ctrl);
    regVal &= 0xFFFFFFFE;
    UMVP_WRITE_REG(WDT_Ctrl, regVal);
}

void wdt_sel_clk_src(unsigned char sourceClk)
{
    register unsigned int regVal;
                                                                                     
    regVal = UMVP_READ_REG(WDT_Ctrl);
    if (sourceClk == WDT_CLK_SRC_PCLK)
    {
        /* reset WDT_Ctrl[4] as 0 */
        regVal &= 0xFFFFFFEF;
    }
    else
    {
        /* set WDT_Ctrl[4] as 1 */
        regVal |= 0x00000010;
    }
    UMVP_WRITE_REG(WDT_Ctrl, regVal);
}

void wdt_set_timeout_action(bool_T bResetOut, bool_T bIntrSys, bool_T bResetSys)
{
	register unsigned int regVal;

	regVal = UMVP_READ_REG(WDT_Ctrl);

	if (bResetOut)
	{
		/* set WDT_Ctrl[3] = 1 */
		regVal |= 0x00000008;
	}
	else
	{
		/* reset WDT_Ctrl[3] = 0 */
		regVal &= 0xFFFFFFF7;
	}

	if (bIntrSys)
	{
		/* set WDT_Ctrl[2] = 1 */
		regVal |= 0x00000004;
	}
	else
	{
		/* reset WDT_Ctrl[2] = 0 */
		regVal &= 0xFFFFFFFB;
	}

	if (bResetSys)
	{
#if (CONFIG_AST1500_SOC_VER >= 2)

#if !(PATCH_CODEV3 & PATCH_AST1520A0_BUG14071000_HPLL_RESET)
		//Enable full chip reset
		regVal |= ((0x01) << 5);
#endif

#endif
		/* set WDT_Ctrl[1] = 1 */
		regVal |= 0x00000002;
	}
	else
	{
		/* reset WDT_Ctrl[1] = 0 */
		regVal &= 0xFFFFFFFD;
	}

	UMVP_WRITE_REG(WDT_Ctrl, regVal);
}

void wdt_enable(void)
{
	register unsigned int regVal;

	/* set WDT_Ctrl[0] as 1 */
	regVal = UMVP_READ_REG(WDT_Ctrl);
	regVal |= 1;
	UMVP_WRITE_REG(WDT_Ctrl, regVal);
}

void wdt_restart_new(unsigned int nPeriod, int sourceClk, bool_T bResetOut, bool_T bIntrSys, bool_T bResetSys, bool_T bUpdated)
{
	wdt_disable();

	UMVP_WRITE_REG(WDT_Reload, nPeriod);

	wdt_sel_clk_src(sourceClk);

	wdt_set_timeout_action(bResetOut, bIntrSys, bResetSys);

	UMVP_WRITE_REG(WDT_Restart, 0x4755);	/* reload! */

	if (!bUpdated)
  	  wdt_enable();
}

void wdt_restart(void)
{
	wdt_disable();
	UMVP_WRITE_REG(WDT_Restart, 0x4755);	/* reload! */
	wdt_enable();
}

void wdt_kick(void)
{
	/* Only kick when WDT was enabled. */
	if (test_bit(0, &wdt_is_open))
		wdt_restart();
}
EXPORT_SYMBOL(wdt_kick);

/**
 *	wdt_set_heartbeat:
 *	@t:		the new heartbeat value that needs to be set.
 *
 *	Set a new heartbeat value for the watchdog device. If the heartbeat value is
 *	incorrect we keep the old value and return -EINVAL. If successfull we
 *	return 0.
 */
static int wdt_set_heartbeat(int t)
{
  if ((t < 1) || (t > 1000))
      return -EINVAL;
      
  heartbeat=t;

#if 0
  wdt_restart_new(TICKS_PER_uSEC*1000000*t, WDT_CLK_SRC_PCLK, FALSE, TRUE, FALSE, FALSE);
#else
	if (test_bit(0, &wdt_is_open))
		wdt_restart_new(TICKS_PER_uSEC*1000000*t, WDT_CLK_SRC_EXT, FALSE, FALSE, TRUE, FALSE);
	else
		wdt_restart_new(TICKS_PER_uSEC*1000000*t, WDT_CLK_SRC_EXT, FALSE, FALSE, TRUE, TRUE);
#endif
  return 0;
}

#if 0
/*
   Kernel Interfaces
*/

/**
 *	umvp2500_wdt_write: 
 *	@file: file handle to the watchdog
 *	@buf: buffer to write (unused as data does not matter here
 *	@count: count of bytes
 *	@ppos: pointer to the position to write. No seeks allowed
 *
 *	A write to a watchdog device is defined as a keepalive signal. Any
 *	write of data will do, as we we don't define content meaning.
 */
         
 static ssize_t umvp2500_wdt_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
 {
   if(count) 
   {
     if (!nowayout)
     {
        size_t i;
             
        /* In case it was set long ago */
        expect_close = 0;
                         
        for (i = 0; i != count; i++) 
        {
          char c;
          if (get_user(c, buf + i))
            return -EFAULT;
          if (c == 'V')
            expect_close = 42;
        }
      }
      wdt_restart();
   }
   return count; 
 }
 
/**
 *	umvp2500_wdt_ioctl:
 *	@inode: inode of the device
 *	@file: file handle to the device
 *	@cmd: watchdog command
 *	@arg: argument pointer
 * *	The watchdog API defines a common set of functions for all watchdogs
 *	according to their available features. We only actually usefully support
 *	querying capabilities and current status.
 */
          
static int umvp2500_wdt_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
  void __user *argp = (void __user *)arg;
  int __user *p = argp;
  int new_heartbeat;
      
  static struct watchdog_info ident = 
  {
    .options 		= WDIOF_SETTIMEOUT|
                          WDIOF_MAGICCLOSE|
                          WDIOF_KEEPALIVEPING,
    .firmware_version 	= 1,
    .identity 		= "UMVP2500 WDT",
  };
  
  switch(cmd)
  {
    default:
      return -ENOIOCTLCMD;
    case WDIOC_GETSUPPORT:
      return copy_to_user(argp, &ident, sizeof(ident))?-EFAULT:0;                      
    case WDIOC_GETSTATUS:
    case WDIOC_GETBOOTSTATUS:
      return put_user(0, p);
    case WDIOC_KEEPALIVE:
      wdt_restart();
      return 0;
    case WDIOC_SETTIMEOUT:
      if (get_user(new_heartbeat, p))
        return -EFAULT;

      if (wdt_set_heartbeat(new_heartbeat))
        return -EINVAL;

      /* Fall */
    case WDIOC_GETTIMEOUT:
      return put_user(heartbeat, p);      
  }
}
/**
*	umvp2500_wdt_open:
*	@inode: inode of device
*	@file: file handle to device
*
*	The watchdog device has been opened. The watchdog device is single
*	open and on opening we load the counters. Counter zero is a 100Hz
*	cascade, into counter 1 which downcounts to reboot. When the counter
*	triggers counter 2 downcounts the length of the reset pulse which
*	set set to be as long as possible.
*/
          
static int umvp2500_wdt_open(struct inode *inode, struct file *file)
{
  if(test_and_set_bit(0, &wdt_is_open))
      return -EBUSY;
  /*
   *	Activate
   */
 // wdt_init(); 
  wdt_restart();
  return nonseekable_open(inode, file);
} 

/**
*	umvp2500_wdt_release:
*	@inode: inode to board
*	@file: file handle to board
*
*	The watchdog has a configurable API. There is a religious dispute
*	between people who want their watchdog to be able to shut down and
*	those who want to be sure if the watchdog manager dies the machine
*	reboots. In the former case we disable the counters, in the latter
*	case you have to open it again very soon.
*/
          
static int umvp2500_wdt_release(struct inode *inode, struct file *file)
{
  if (expect_close == 42 || !nowayout) 
  {
      wdt_disable();
      clear_bit(0, &wdt_is_open);
  } 
  else 
  {
      printk(KERN_CRIT "wdt: WDT device closed unexpectedly.  WDT will not stop!\n");
      wdt_restart();
  }
  expect_close = 0;
  return 0;
}
#endif

/**
*	notify_sys:
*	@this: our notifier block
*	@code: the event being reported
*	@unused: unused
*
*	Our notifier is called on system shutdowns. We want to turn the card
*	off at reboot otherwise the machine will reboot again during memory
*	test or worse yet during the following fsck. This would suck, in fact
*	trust me - if it happens it does suck.
*/
          
static int umvp2500_wdt_notify_sys(struct notifier_block *this, unsigned long code, void *unused)
{
   if(code==SYS_DOWN || code==SYS_HALT) 
   {
     /* Turn the WDT off */
     wdt_disable();
   }
   return NOTIFY_DONE;
}

#if 0
static struct file_operations umvp2500_wdt_fops = 
{
  .owner	= THIS_MODULE,
  .llseek	= no_llseek,
  .write	= umvp2500_wdt_write,
  .ioctl	= umvp2500_wdt_ioctl,
  .open		= umvp2500_wdt_open,
  .release	= umvp2500_wdt_release,
};

static struct miscdevice umvp2500_wdt_miscdev = 
{
   .minor	= WATCHDOG_MINOR,
   .name	= "watchdog",
   .fops	= &umvp2500_wdt_fops,
};
#endif
     
static struct notifier_block umvp2500_wdt_notifier = 
{
   .notifier_call=umvp2500_wdt_notify_sys,
};

#if 1
static ssize_t show_timeout(struct device *dev, struct device_attribute *attr, char *buf)
{
	printk(KERN_INFO "timeout = %d\n", heartbeat);
	return 0;
}

static ssize_t store_timeout(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{	
	int new_heartbeat;
	unsigned int c;

	c = sscanf(buf, "%d", &new_heartbeat);
	if (c == 1) {
		printk(KERN_INFO "set timeout to %d\n", new_heartbeat);
		wdt_set_heartbeat(new_heartbeat);
	}
	else {
		printk("Usage:\ntimeout\n");
	}
	return strlen(buf);
}
DEVICE_ATTR(timeout, (S_IRUGO | S_IWUSR), show_timeout, store_timeout);

static ssize_t show_enable(struct device *dev, struct device_attribute *attr, char *buf)
{
	if (test_bit(0, &wdt_is_open)){
		printk(KERN_INFO "watchdog is enabled\n");
		sprintf(buf, "yes\n");
	}
	else{
		printk(KERN_INFO "watchdog is disabled\n");
		sprintf(buf, "no\n");
	}
	return strlen(buf);
}

static ssize_t store_enable(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{	
	if (!strncmp(buf, "yes", 3)){
		printk(KERN_INFO "enable watchdog\n");
		if (test_and_set_bit(0, &wdt_is_open))
			printk(KERN_INFO "watchdog already enabled\n");
		else
			wdt_restart();
	}
	else if (!strncmp(buf, "no", 2)){
		printk(KERN_INFO "disable watchdog\n");
		wdt_disable();
		clear_bit(0, &wdt_is_open);
	}
	else{
		printk(KERN_ERR "Usage:\nyes | no\n");
	}
	return strlen(buf);
}
DEVICE_ATTR(enable, (S_IRUGO | S_IWUSR), show_enable, store_enable);

static ssize_t store_tickle(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{	
	if (test_bit(0, &wdt_is_open)){
//		printk(KERN_INFO "tickle\n");
		wdt_restart();
	}
	else{
		//printk(KERN_ERR "watchdog not enabled yet\n");
	}
	return strlen(buf);
}
DEVICE_ATTR(tickle, S_IWUSR, NULL, store_tickle);

static struct attribute *dev_attrs[] = {
	&dev_attr_timeout.attr,
	&dev_attr_enable.attr,
	&dev_attr_tickle.attr,
	NULL,
};

static struct attribute_group dev_attr_group = {
	.attrs = dev_attrs,
};

static const char device_name[] = "watchdog";

static void the_pdev_release(struct device *dev)
{
	return;
}

static struct platform_device pdev = {
	.name = device_name,
	.id = -1,
	.dev = {
		.release = the_pdev_release,
	},
};
#endif

void __exit wdt_exit(void)
{
#if 1
	sysfs_remove_group(&pdev.dev.kobj, &dev_attr_group);
	platform_device_unregister(&pdev);
#endif
#if 0
    misc_deregister(&umvp2500_wdt_miscdev);
#endif
#if 0
    disable_irq(INT_WDT);
    free_irq(INT_WDT, NULL);
#else
	unregister_reboot_notifier(&umvp2500_wdt_notifier);   
#endif
}

int __init wdt_init(void)
{
   int ret;  
    
	/* set INT_WDT as "raising_edge trigger, irq mode" sensitivity */
   vic_set_intr_trigger(INT_WDT, vicc_edge_activeRaising);


   wdt_disable();
#if 0
   wdt_sel_clk_src(WDT_CLK_SRC_PCLK);
   wdt_set_timeout_action(FALSE, FALSE, FALSE);
#endif

#if 0
   /* register ISR */
   if (request_irq(INT_WDT, wdt_isr, SA_INTERRUPT, "WDT", NULL))
   {
     printk("unable to register interrupt INT_WDT = %d\n", INT_WDT);
     return (-1);
   }
   else
     printk("success to register interrupt for INT_WDT (%d)\n", INT_WDT);
#endif

     
   ret = register_reboot_notifier(&umvp2500_wdt_notifier);
   if(ret) 
   {
     printk(KERN_ERR "wdt: cannot register reboot notifier (err=%d)\n", ret);
#if 0
     free_irq(INT_WDT, NULL);
#endif
     return ret;
   }
   
#if 0//use sysfs exclusively. Without registering a misc device, _initcall can be advanced.
   ret = misc_register(&umvp2500_wdt_miscdev);
   if (ret) 
   {
      printk(KERN_ERR "wdt: cannot register miscdev on minor=%d (err=%d)\n",WATCHDOG_MINOR, ret);
      unregister_reboot_notifier(&umvp2500_wdt_notifier);   
      return ret;
   }
#endif

#if 1
   ret = platform_device_register(&pdev);
   if (ret < 0) {
	   printk("platform_device_register err\n");
#if 0	   
	   misc_deregister(&umvp2500_wdt_miscdev);
#endif
	   unregister_reboot_notifier(&umvp2500_wdt_notifier);	 
   }
   
   ret = sysfs_create_group(&pdev.dev.kobj, &dev_attr_group);
   if (ret) {
	   printk("can't create sysfs files\n");
	   platform_device_unregister(&pdev);
#if 0	   
	   misc_deregister(&umvp2500_wdt_miscdev);
#endif
	   unregister_reboot_notifier(&umvp2500_wdt_notifier);	 
   }
#endif 
   
#if 0
   /* interrupt the system while WDT timeout */
   wdt_restart_new(TICKS_PER_uSEC*1000000*heartbeat, WDT_CLK_SRC_PCLK, FALSE, TRUE, FALSE, TRUE);
   /* enable INT */
   enable_irq(INT_WDT);
#else
	//select external 1MHz clock source
	//reset system while WDT timeout
	//enable watchdog after initialization
	test_and_set_bit(0, &wdt_is_open);
	wdt_restart_new(TICKS_PER_uSEC*1000000*heartbeat, WDT_CLK_SRC_EXT, FALSE, FALSE, TRUE, FALSE);
#endif

#if 0
   printk(KERN_INFO "UMVP2500 WDT is installed.(irq = %d, heartbeat = %d secs, nowayout = %d)\n",INT_WDT,heartbeat,nowayout);
#else
   printk(KERN_INFO "AST15XX WDT is installed.(heartbeat = %d secs, nowayout = %d)\n", heartbeat, nowayout);
#endif
   
   return (0);
}

#ifndef MODULE
core_initcall(wdt_init);
#else
module_init (wdt_init);
#endif
module_exit(wdt_exit);
MODULE_AUTHOR("ASPEED Corp.");
MODULE_DESCRIPTION("Driver for AST15XX Watch Dog");
MODULE_ALIAS_MISCDEV(WATCHDOG_MINOR);
MODULE_LICENSE("GPL");
