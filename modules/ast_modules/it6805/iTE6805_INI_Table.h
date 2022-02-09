///*****************************************
//  Copyright (C) 2009-2019
//  ITE Tech. Inc. All Rights Reserved
//  Proprietary and Confidential
///*****************************************
//   @file   <iTE6805_INI_Table.h>
//   @author Kuro.Chung@ite.com.tw
//   @date   2019/03/05
//   @fileversion: iTE6805_MCUSRC_1.31
//******************************************/
#ifndef _ITE6805_INI_TABLE_H_
#define _ITE6805_INI_TABLE_H_
// init table
#define BANK 0x0F
#define BANKM 0x07


iTE6805_INI_REG _CODE iTE6805_INIT_HDMI_TABLE[] = {
	{0x0F , 0xFF ,0x00 } ,
	{0x22 , 0xFF ,0x08 } , // RegRegRst : Register block reset
	{0x22 , 0xFF ,0x17 } , //[4]Auto Video Reset [2]Int Reset [1]Audio Reset [0]Video Reset
	{0x23 , 0xFF ,0x1F } , //Port 0 [4]EQ Reset [3]CLKD5 Reset [2]CDR Reset [1]HDCP Reset [0]All logic Reset
	{0x2B , 0xFF ,0x1F } , //Port 1 [4]EQ Reset [3]CLKD5 Reset [2]CDR Reset [1]HDCP Reset [0]All logic Reset
	{0x24 , 0xFF ,0xF8 } , // [7:3] MHL Logic reset
	//{0xC5 , 0xFF ,0x13 } , // EDID Reset
	{0x22 , 0xFF ,0x10 } , //[4]Auto Video Reset [2]Int Reset [1]Audio Reset [0]Video Reset
	{0x23 , 0xFF ,0xA0 } , //Port 0 [4]EQ Reset [3]CLKD5 Reset [2]CDR Reset [1]HDCP Reset [0]All logic Reset
	{0x2B , 0xFF ,0xA0 } , //Port 1 [4]EQ Reset [3]CLKD5 Reset [2]CDR Reset [1]HDCP Reset [0]All logic Reset
	{0x24 , 0xFF ,0x00 } , // [7:3] MHL Logic reset
	//{0xC5 , 0xFF ,0x03 } , // EDID Reset
	{0x34 , 0xFF ,0x00 } , // disable Reg_AutoRCLK
	{0x0F , 0xFF ,0x03 } ,
	//{0xAB , 0xFF ,0x4A } , //output HPD low
	//{0xAC , 0xFF ,0x40 } , // Reg_P0_ForceCBUS=1
	{0xAA , 0xFF ,0xEC } , // 0106 add
	{0x0F , 0xFF ,0x00 } ,
	//{0x51 , 0xFF ,0x09 } , // RD Debug
	//{0x4E , 0xFF ,0x07 } , // RD Debug
	//{0xC9 , 0xFF ,0x52 } , // EDID port0 EDID BLOCK0 check sum
	//{0x0F , 0xFF ,0x04 } ,
	//{0xC9 , 0xFF ,0x52 } , // EDID port1 EDID BLOCK0 check sum
	//{0x0F , 0xFF ,0x00 } ,
	//{0xCA , 0xFF ,0xBB } , // EDID port0 EDID BLOCK1 check sum
	//{0x0F , 0xFF ,0x04 } ,
	//{0xCA , 0xFF ,0xBB } , // EDID port1 EDID BLOCK1 check sum
	//{0x0F , 0xFF ,0x00 } ,
	//{0xC5 , 0xFF ,0x02 } , // enable Port 0 Internal EDID
	//{0x0F , 0xFF ,0x04 } ,
	//{0xC5 , 0xFF ,0x02 } , // enable Port 1 Internal EDID
	//{0x0F , 0xFF ,0x00 } ,
	{0x0F , 0xFF ,0x03 } ,
	//{0xAB , 0xFF ,0xCA } ,  // enable HPD output
	{0xAC , 0xFF ,0x40 } ,
	{0x0F , 0xFF ,0x00 } ,
	{0x3A , 0xFF ,0x89 } , // 0406 add, 0421 modify, emily command for CED Error sensetive from 89 to 99
	//{0x49 , 0xFF ,0xE1 } , // setting MHL address
	//{0x35 , 0xFF ,0x02 } , // setting main port
	{0x49 , 0xFF , ADDR_MHL | 1 } , // 0106 add
	{0x43 , 0xFF ,0x01 } , // 0106 add
	//{0x86 , 0xFF ,0x08 } , // 0106 add 0117 modify to mark
	{0x0F , 0xFF ,0x04 } , // 0106 add
	{0x43 , 0xFF ,0x01 } , // 0106 add 0117 modify to mark
	{0x3A , 0xFF ,0x89 } , // 0406 add, 0421 modify, emily command for CED Error sensetive from 89 to 99
	{0x0F , 0xFF ,0x03 } ,
	{0xA8 , 0xFF ,0x0B } , // P0_ENHYS = 011
	{0x0F , 0xFF ,0x00 } ,
	{0x4F , 0xFF ,0x84 } , // RCLK frequency select
	{0x44 , 0xFF ,0x19 } , // 1G
	{0x46 , 0xFF ,0x15 } , // 1P48G
	{0x47 , 0xFF ,0x88 } , // 3P4G
	{0xD9 , 0xFF ,0x00 } , // Reg_EnHwReAuthen // 0906 disable
	{0xF0 , 0xFF ,0x78 } , // Reg_DbgRSACnt[7:0]
	{0xF1 , 0xFF ,0x10 } , // RegHPMaxEcc[7:0]
	{0x0F , 0xFF ,0x03 } ,
	{0x3A , 0xFF ,0x02 } , // set Reg_ENHEQ
	{0x0F , 0xFF ,0x00 } ,
	{0x28 , 0xFF ,0x88 } , // 0106 modify
	{0x6E , 0xFF ,0x80 } ,
	{0x77 , 0xFF ,0x87 } , // Reg_PktRec_Type, set from 83 to 87 for record DRM pkt
	{0x7B , 0xFF ,0x00 } , // RegPktFlag_Ctrl
	{0x86 , 0xFF ,0x00 } , // 0118 add
	//{0x4F , 0xFF ,0x84 } ,
	{0x0F , 0xFF ,0x00 } ,
	{0x36 , 0xFF ,0x06 } ,
	{0x8F , 0xFF ,0x41 } ,
	{0x0F , 0xFF ,0x01 } ,
	{0xC0 , 0xFF ,0x42 } , // kuro fix
	//{0xC1 , 0xFF ,0x02 } , mark because will setting later
	{0xC4 , 0x70 , Clock_Delay << 4	}, // setting Reg_DlyDCLK
	{0xC4 , BIT7 , Clock_Invert << 7	}, // setting Reg_InvDCLK
	{0xC5 , 0xFF ,0x00 } , // tri-state
	{0xC6 , 0xFF ,0x00 } , // tri-state
	{0xC7 , 0xFF ,0x00 } , // tri-state
	{0xC8 , 0xFF ,0x00 } , // tri-state
	{0xC9 , 0xFF ,0x99 } , // 0106 modify Richard suggest 5mA, slow
	{0xCA , 0xFF ,0x99 } , // 0106 modify Richard suggest 5mA, slow
//0113 add start
	{0x0F , 0xFF ,0x00 } ,
	{0x86 , 0x0C ,0x08 } , // 0118 modify, HW RD mail [IT6664, IT6805, IT6634 Audio Seeting note] by Andrew Chang
	{0x81 , BIT7 ,BIT7 } , // 0125 JJ suggest
//0113 add end

	// JJ suggest
	// fixed Ulta-2000 HDCP fail issue at Receiver mode start
	{BANK	,BANKM	, 0x01	}, // change bank 1
    {0x10	,0xFF	, 0x00	},
    {0x11	,0xFF	, 0x00	},
    {0x12	,0xFF	, 0x00	},
    {0x13	,0xFF	, 0x00	}, // for receiver, BKSV should be zero on inital
    {0x28	,0xFF	, 0x00	}, // Clear KSV LIST
    {0x29	,0xFF	, 0x00	}, // Clear KSV LIST
    {0x2A	,0xFF	, 0x00	}, // Clear KSV LIST
    {0x2B	,0xFF	, 0x00	}, // Clear KSV LIST
    {0x2C	,0xFF	, 0x00	}, // Clear KSV LIST
	// fixed Ulta-2000 HDCP fail issue at Receiver mode end

	// 0203 add IO mode
	{0xC0	,0xC0	, Reg_IOMode},

	// 0208 add EQ Init Value
	{BANK	,BANKM	, 0x03	}, // change bank 3
	{0xE3	,0xFF	, 0x07	} , // 0426 modify by RD code edit it from 06 to 05, recommand by emily, and 11/24 modify for B1 and later
	{0x27	,0xFF	, EQ_INIT_VALUE	},
	{0x28	,0xFF	, EQ_INIT_VALUE	},
	{0x29	,0xFF	, EQ_INIT_VALUE	},
	{0xA7	,BIT6	, BIT6	},

	{BANK	,BANKM	, 0x07	}, // change bank 7
	{0xE3	,0xFF	, 0x07 } , // 0426 modify by RD code edit it from 06 to 05, recommand by emily
	{0x27	,0xFF	, EQ_INIT_VALUE	},
	{0x28	,0xFF	, EQ_INIT_VALUE	},
	{0x29	,0xFF	, EQ_INIT_VALUE	},
	{0xA7	,BIT6	, BIT6	},

	{BANK	,BANKM	, 0x00	}, // change bank 0

#if (_ENABLE_IT6805_CEC_==TRUE)
	{0x21	,BIT2	, 0x00	}, // disable CEC clock gating
	{0x4A	,0xFF	, ADDR_CEC	}, // CEC ADDR
#endif

	{0xF8	,0xFF	, 0xC3	},
	{0xF8	,0xFF	, 0xA5	},
	{BANK	,BANKM	, 0x01	},
	{0x5F	,0xFF	, 0x04	},
	{0x58	,0xFF	, 0x12	},
	{0x58	,0xFF	, 0x02	},
	{0x5F	,0xFF	, 0x00	},
	{BANK	,BANKM	, 0x00	},
	{0xF8	,0xFF	, 0xFF	},

	{BANK	,BANKM	, 0x05	}, // change bank 5
	{0x20	,0x03	, DownScale_Filter	},
#if (LVDSSSC==1 && iTE68052==1)
    {0xD7	,0xFF	, 0x3D	},
    {0xD8	,0xFF	, 0x0A	},
    {0xD9	,0xFF	, 0x03	},
#endif
	{BANK	,BANKM	, 0x00	}, // change bank 5

	{BANK	,BANKM	, 0x04	}, // change bank
	// add for MHL port0 plug-unplug port1 screen will be Flashing. by emily comment 0721 'IT6805 P0 MHL + P1 HDMI'
	{0x3C	,BIT5	, 0	},
	{BANK	,BANKM	, 0x00	}, // change bank
	// add for MHL port0 1: from Crystal 27MHz for MHL CTS
	{0x91	,BIT6	, BIT6	},

	// for CTS RR Test
	{BANK	,BANKM	, 0x03	}, // change bank
	//{0xE3	,0xFF	, 0x06	},
	{0xF0	,0xFF	, 0xC0	},
	{BANK	,BANKM	, 0x00	}, // change bank

	// ChipID = B0 chip set this for auto SCDC reset when 5v off
	{0x21	,BIT6	, BIT6	},

	// 0xCE 4: Enable Fast authentication 5: Enable feature 1.1 need to be set to 0
	{0xCE	,0x30	, 0x00	},
	{BANK	,BANKM	, 0x04	},
	{0xCE	,0x30	, 0x00	},
	{0x42	,0xC0	, 0xC0	},	// add 20180313 by emily mail
	{BANK	,BANKM	, 0x00	},
	{0x42	,0xC0	, 0xC0	},	// add 20180313 by emily mail
	{0x7B	,BIT4	, BIT4	},	// for detect DRM PKT

	// mail need to set to all 6805 Ax/Bx chip by mail IT6805 SW register setting
	{0x3C	,0x21	, 0x00	},
	{0x3B	,0xFF	, 0x23	},	//IT6805B0 SW Change
	{0xF6	,0xFF	, 0x08	},	//IT6805B0 SW Change
	{BANK	,BANKM	, 0x04	},
	{0x3C	,0x21	, 0x00	},
	{0x3B	,0xFF	, 0x23	},	//IT6805B0 SW Change
	{BANK	,BANKM	, 0x00	},

	// mail need to set 0x59 = 0 by emily mail for A0/A1/B0 chip
	{0x59	,0xFF	, 0x00	},


#if (iTE6807 == TRUE)
	{0x39	,0x01	, 0x01	},
	{0x67	,0x80	, 0x80	},// disable pixrpt Andrew 201808 for IT6807
    {0x68	,0x10	, 0x00	},// to prevent video-stable on-off-on
	{0xD8	,0xF0	, 0x20	},// IT6807A0 : RegRxHP2Ver =2
    {BANK	,BANKM	, 0x05	},
    {0xCB	,0x06	, VBO_SwapSel},
    {BANK	,BANKM	, 0x00	},
#endif

#if defined(AST_HDMIRX)
	{0x67,	0x80,	0x00}, /* enable pixel repetition, to be the same behavior as other HDMI RX */
#if (AST_IT6805_INTR == 1)
	/*
	 * [5]: enable interrupt IO output
	 * [4]: enable MHL Cbus interrupt , [3]: enable MHL Set interrupt
	 * [2]: enable HDMI interrupt
	 */
	{0x60,	0x3C,	0x20},
#endif
#if (_ENABLE_EDID_RAM_ == FALSE)
	{0xC5,	0x01,	0x01}, /* disable Port 0 Internal EDID, bank 0, reg 0xC5, bit 0; 1:disable */
#endif
#endif

	{0xFF	,0xFF	, 0xFF},



};

#endif

