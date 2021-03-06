/*
 * (C) Copyright 2002
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Diagnostics support
 */
#include <common.h>
#include <command.h>
#include <post.h>
#include "slt.h"

#if defined (CONFIG_SLT)

int do_slt (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	int flags = 0;

	/* Reg. Test */
#if (CFG_CMD_SLT & CFG_CMD_REGTEST)
	if (do_regtest())
	{
	    flags |= FLAG_REGTEST_FAIL;	
            printf("[INFO] RegTest Failed \n");
	}    
	else
            printf("[INFO] RegTest Passed \n");
#endif
#if (CFG_CMD_SLT & CFG_CMD_MACTEST)
	if (do_mactest())
	{
	    flags |= FLAG_MACTEST_FAIL;	
            printf("[INFO] MACTest Failed \n");
	}    
	else
            printf("[INFO] MACTest Passed \n");
#endif
#if (CFG_CMD_SLT & CFG_CMD_VIDEOTEST)
	if (do_videotest())
	{
	    flags |= FLAG_VIDEOTEST_FAIL;	
            printf("[INFO] VideoTest Failed \n");
	}    
	else
            printf("[INFO] VideoTest Passed \n");
#endif
#if (CFG_CMD_SLT & CFG_CMD_HACTEST)
	if (do_hactest())
	{
	    flags |= FLAG_HACTEST_FAIL;	
            printf("[INFO] HACTest Failed \n");
	}    
	else
            printf("[INFO] HACTest Passed \n");
#endif
#if (CFG_CMD_SLT & CFG_CMD_MICTEST)
	if (do_mictest())
	{
	    flags |= FLAG_MICTEST_FAIL;	
            printf("[INFO] MICTest Failed \n");
	}    
	else
            printf("[INFO] MICTest Passed \n");
#endif
#if (CFG_CMD_SLT & CFG_CMD_OSDTEST)
	if (do_osdtest())
	{
	    flags |= FLAG_OSDTEST_FAIL;	
            printf("[INFO] OSDTest Failed \n");
	}    
	else
            printf("[INFO] OSDTest Passed \n");
#endif
#if (CFG_CMD_SLT & CFG_CMD_2DTEST)
	if (do_2dtest())
	{
	    flags |= FLAG_2DTEST_FAIL;	
            printf("[INFO] 2DTest Failed \n");
	}    
	else
            printf("[INFO] 2DTest Passed \n");
#endif
#if (CFG_CMD_SLT & CFG_CMD_HWCTEST)
	if (do_hwctest())
	{
	    flags |= FLAG_HWCTEST_FAIL;	
            printf("[INFO] HWC Test Failed \n");
	}    
	else
            printf("[INFO] HWC Test Passed \n");
#endif
	
	/* Summary */
	if (flags)
            printf ("[INFO] SLT Test Failed!! \n");
        else
            printf ("[INFO] SLT Test Passed!! \n");    
        
	return 0;
}
/***************************************************/

U_BOOT_CMD(
	slt,	CFG_MAXARGS,	0,	do_slt,
	"slt - slt test program \n",
	NULL
);

#endif /* CONFIG_SLT */
