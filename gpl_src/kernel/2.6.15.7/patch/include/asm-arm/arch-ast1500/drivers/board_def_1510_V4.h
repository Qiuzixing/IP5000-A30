#ifndef _AST1500_BOARD_DEF_1510_V4_H
#define	_AST1500_BOARD_DEF_1510_V4_H

/*
** Different board design version
*/
// BOARD_DESIGN_VER_TRAP 204:
//	- The first complete trapping design for AST1510
#define BOARD_DESIGN_VER_TRAP		204 //Basically based on AST1510 board V4
// BOARD_DESIGN_VER_I2S 204:
//	-Add codec/HDMI hotplug detect and auto change
#define BOARD_DESIGN_VER_I2S		204 //Basically based on AST1510 board V4
#define BOARD_DESIGN_VER_VIDEO	204 //Basically based on AST1510 board V4
// BOARD_DESIGN_VER_IR 204:
//	- Add Tx/Rx dual mode switch. Also changes IR polarity for dual mode
#define BOARD_DESIGN_VER_IR		204 //Basically based on AST1510 board V4
// BOARD_DESIGN_VER_MISC 104:
//	- Add GPIO_CH_UPDATE feature
#define BOARD_DESIGN_VER_MISC		104 //Basically based on AST1500 board V4

/*
** components
*/
#ifdef CONFIG_ARCH_AST1500_HOST
	#define CONFIG_AST1500_CAT6023
	#define CONFIG_AST1500_ADC9883
#endif
#define CONFIG_AST1500_CAT6613
	
/*
** I2C
*/
//host EDID EEPROM DDC
#define I2C_HOST_VIDEO_DDC_EEPROM	2
//host loopback VGA DDC
#define I2C_HOST_VIDEO_LOOPBACK_DDC	3
//client VGA DDC
#define I2C_CLIENT_VIDEO_DDC_EEPROM 3
//host analog video receiver
#define I2C_VIDEO2_9883 		    1
//host/client analog audio codec
#define I2C_AUDIO_CODEC 1
//host HDMI receiver
#define I2C_HDMI_RX 1
//host/client HDMI transmitter
#define I2C_HDMI_TX 3

/*
** trapping
*/
#define 	CLIENT_MODE_EN_MASK 			0x80000000
#define 	BE_SOURCE_CHIP				(0UL<<31)
#define 	BE_CLIENT_CHIP				(1UL<<31)
#define 	VIDEO_TYPE_SHIFT		(28)
#define 	VIDEO_TYPE_MASK 		(0x3UL<<VIDEO_TYPE_SHIFT)
#define 	VIDEO_TYPE_ANALOG		0x0
#define 	VIDEO_TYPE_NONE 			0x1
#define 	VIDEO_TYPE_HDMI 			0x2
#define 	VIDEO_TYPE_DVI				0x3
#define 	LOOPBACK_TX_STATUS_MASK 			0x40000000 //BIT30

/*
** GPIO
*/
#define GPIO_BUTTON1	AST1500_GPA2
#define GPIO_BUTTON2	AST1500_GPA3
#define GPIO_LED_LINK	AST1500_GPP4
#define GPIO_LED_PWR	AST1500_GPP5
#define GPIO_CH0	AST1500_GPK0
	#define GPIO_CH0_ACTIVE 1
#define GPIO_CH1	AST1500_GPK1
	#define GPIO_CH1_ACTIVE 1
#define GPIO_CH2	AST1500_GPK2
	#define GPIO_CH2_ACTIVE 1
#define GPIO_CH3	AST1500_GPK3
	#define GPIO_CH3_ACTIVE 1
#define GPIO_CH_UPDATE	AST1500_GPK4
	#define GPIO_CH_UPDATE_ACTIVE	0
#define GPIO_POWER_CTRL_IN		AST1500_GPK5//client
#define GPIO_POWER_CTRL_OUT		AST1500_GPK5//host
#define	GPIO_HOST_VIDEO_MONITOR_DETECT	AST1500_GPC4
#define	GPIO_HOST_VIDEO_ATTACH_CONTROL	AST1500_GPJ0
	#define GPIO_HOST_VIDEO_DETACH_LEVEL	1
	#define GPIO_HOST_VIDEO_ATTACH_LEVEL	0
#define	GPIO_HOST_VIDEO_DDC_PATH_CONTROL	AST1500_GPJ1
	#define	GPIO_HOST_VIDEO_DDC_PATH_DETACH_LEVEL 1
	#define	GPIO_HOST_VIDEO_DDC_PATH_ATTACH_LEVEL 0
#define	GPIO_CLIENT_VIDEO_MONITOR_DETECT	AST1500_GPC4
#define GPIO_CAT6023_RST AST1500_GPJ3
#define GPIO_CAT6023_INT AST1500_GPC7
#define GPIO_CAT6613_RST AST1500_GPJ2
#define GPIO_CAT6613_INT AST1500_GPC6
#define GPIO_AUDIO_CODEC_IN_HOTPLUG AST1500_GPH2
#define GPIO_AUDIO_CODEC_OUT_HOTPLUG AST1500_GPH1
#define GPIO_AUDIO_IO_SELECT AST1500_GPH3
#define GPIO_AUDIO_CODEC_RESET AST1500_GPH4
#define GPIO_IR_DISABLE AST1500_GPP6
#define GPIO_IR_IO_SWITCH AST1500_GPP6
	

#endif //#ifndef _AST1500_BOARD_DEF_1510_V4_H

