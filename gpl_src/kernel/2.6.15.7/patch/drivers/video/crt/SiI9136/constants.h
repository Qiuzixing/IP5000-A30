/*
 *****************************************************************************
 *
 * Copyright 2010, Silicon Image, Inc.  All rights reserved.
 * No part of this work may be reproduced, modified, distributed, transmitted,
 * transcribed, or translated into any language or computer format, in any form
 * or by any means without written permission of: Silicon Image, Inc., 1060
 * East Arques Avenue, Sunnyvale, California 94085
 *****************************************************************************
 */
/*
 *****************************************************************************
 * @file  Constants.h
 *
 * @brief Constant value declarations
 *
 *****************************************************************************
*/

// Generic Constants
//==================
#define FALSE                   0
#define TRUE                    1

#define OFF                     0
#define ON                      1

#define LOW                     0
#define HIGH                    1

#define DISABLE     			(0x00)
#define ENABLE      			(0xFF)

#define CLEAR   				(0x00)
#define SET     				(0xFF)

#if !(AST_HDMITX)
#define ROM   code       // 8051 type of ROM memory
#define IRAM  idata      // 8051 type of RAM memory
#endif

// Generic Masks
//==============
#define LOW_BYTE                0x00FF

#define LOW_NIBBLE              0x0F
#define HI_NIBBLE               0xF0

#define MSBIT                   0x80
#define LSBIT                   0x01

#define BIT_0                   0x01
#define BIT_1                   0x02
#define BIT_2                   0x04
#define BIT_3                   0x08
#define BIT_4                   0x10
#define BIT_5                   0x20
#define BIT_6                   0x40
#define BIT_7                   0x80

#define TWO_LSBITS              0x03
#define THREE_LSBITS            0x07
#define FOUR_LSBITS             0x0F
#define FIVE_LSBITS             0x1F
#define SEVEN_LSBITS            0x7F
#define TWO_MSBITS              0xC0
#define EIGHT_BITS              0xFF
#define BYTE_SIZE               0x08
#define BITS_1_0                0x03
#define BITS_2_1                0x06
#define BITS_2_1_0              0x07
#define BITS_3_2                0x0C
#define BITS_4_3_2              0x1C
#define BITS_5_4                0x30
#define BITS_5_4_3				0x38
#define BITS_6_5                0x60
#define BITS_6_5_4              0x70
#define BITS_7_6                0xC0


// Interrupt Masks
//================
#define HOT_PLUG_EVENT          0x01
#define RX_SENSE_EVENT          0x02
#define HOT_PLUG_STATE          0x04
#define RX_SENSE_STATE          0x08

#define AUDIO_ERROR_EVENT       0x10
#define SECURITY_CHANGE_EVENT   0x20
#define V_READY_EVENT           0x40
#define HDCP_CHANGE_EVENT       0x80

#define NON_MASKABLE_INT		0xFF

// TPI Control Masks
// =================

#define CS_HDMI_RGB         0x00
#define CS_DVI_RGB          0x03
#define OUTPT_MODE_DVI      0x00
#define OUTPT_MODE_HDMI     0x01

// Pixel Repetition Masks
//=======================
#define BIT_BUS_24          0x20
#define BIT_EDGE_RISE       0x10

//Audio Maps
//==========
#define BIT_AUDIO_MUTE      0x10

// Input/Output Format Masks
//==========================
#define BITS_IN_RGB         0x00
#define BITS_IN_YCBCR444    0x01
#define BITS_IN_YCBCR422    0x02

#define BITS_IN_AUTO_RANGE  0x00
#define BITS_IN_FULL_RANGE  0x04
#define BITS_IN_LTD_RANGE   0x08

#define BIT_EN_DITHER_10_8  0x40
#define BIT_EXTENDED_MODE   0x80

#define BITS_OUT_RGB        0x00
#define BITS_OUT_YCBCR444   0x01
#define BITS_OUT_YCBCR422   0x02

#define BITS_OUT_AUTO_RANGE 0x00
#define BITS_OUT_FULL_RANGE 0x04
#define BITS_OUT_LTD_RANGE  0x08

#define BIT_BT_709          0x10


// DE Generator Masks
//===================
#define BIT_EN_DE_GEN       0x40
#define DE 					0x00
#define DeDataNumBytes 		12

// Embedded Sync Masks
//====================
#define BIT_EN_SYNC_EXTRACT 0x40
#define EMB                 0x80
#define EmbDataNumBytes     8


// Audio Modes
//============
#define AUD_PASS_BASIC      0x00
#define AUD_PASS_ALL        0x01
#define AUD_DOWN_SAMPLE     0x02
#define AUD_DO_NOT_CHECK    0x03

#define REFER_TO_STREAM_HDR     0x00
//#define TWO_CHANNELS            0x00
#define TWO_CHANNELS            0x01  //CEA-861-E page 49	- Fix for bug #19948
//#define EIGHT_CHANNELS          0x01
#define EIGHT_CHANNELS          0x07  //CEA-861-E page 49	- Fix for bug #19948
#define AUD_IF_SPDIF            0x40
#define AUD_IF_I2S              0x80
#define AUD_IF_DSD				0xC0
#define AUD_IF_HBR				0x04

#define TWO_CHANNEL_LAYOUT      0x00
#define EIGHT_CHANNEL_LAYOUT    0x20


// Configuration File Constants
//=============================
#define CONFIG_DATA_LEN     0x10
#define IDX_VIDEO_MODE      0x00

// I2C Slave Addresses
//====================
// see include/i2c_slave_addrs.h

// DDC Bus Addresses
//==================
#define DDC_BSTATUS_ADDR_L  0x41
#define DDC_BSTATUS_ADDR_H  0x42
#define DDC_KSV_FIFO_ADDR   0x43
#define KSV_ARRAY_SIZE      128

// DDC Bus Bit Masks
//==================
#define BIT_DDC_HDMI        0x80
#define BIT_DDC_REPEATER    0x40
#define BIT_DDC_FIFO_RDY    0x20
#define DEVICE_COUNT_MASK   0x7F

// KSV Buffer Size
//================
#define DEVICE_COUNT            128    // May be tweaked as needed

// InfoFrames
//===========
#define BITS_OUT_FORMAT         0x60    // Y1Y0 field - in InfoFrame DByte 1

#define _4_To_3                 0x10    // Aspect ratio - 4:3  in InfoFrame DByte 2
#define _16_To_9                0x20    // Aspect ratio - 16:9 in InfoFrame DByte 2
#define SAME_AS_AR              0x08    // R3R2R1R0 - in AVI InfoFrame DByte 2
#define ACT_FORMAT_INFO_VALID	0x10	// A0 - in AVI Infoframe DByte 1

#define BT_601                  0x40
#define BT_709                  0x80

#define TYPE_GBD_INFOFRAME       	0x0A

#define ENABLE_AND_REPEAT			0xC0

#define EN_AND_RPT_MPEG				0xC3
#define DISABLE_MPEG				0x03

#define EN_AND_RPT_HDMI_VSIF		0xC6
#define DISABLE_HDMI_VSIF			0x06

#define EN_AND_RPT_AUDIO			0xC2
#define DISABLE_AUDIO				0x02

#define EN_AND_RPT_MPEG				0xC3
#define DISABLE_MPEG				0x03

#define EN_AND_RPT_AVI				0xC0	// Not normally used.  Write to TPI 0x19 instead
#define DISABLE_AVI				0x00	/* But this is used to Disable */

#define NEXT_FIELD					0x80
#define GBD_PROFILE					0x00
#define AFFECTED_GAMUT_SEQ_NUM		0x01

#define ONLY_PACKET					0x30
#define CURRENT_GAMUT_SEQ_NUM		0x01

// FPLL Multipliers:
//==================

#define X1                      0x01

// 3D Constants
//=============

#define _3D_STRUC_PRESENT				0x02

// 3D_Stucture Constants
//=======================
#define FRAME_PACKING					0x00
#define FIELD_ALTERNATIVE				0x01
#define LINE_ALTERNATIVE				0x02
#define SIDE_BY_SIDE_FULL				0x03
#define L_PLUS_DEPTH					0x04
#define L_PLUS_DEPTH_PLUS_GRAPHICS		0x05
#define SIDE_BY_SIDE_HALF				0x08

// 3D_Ext_Data Constants
//======================
#define HORIZ_ODD_LEFT_ODD_RIGHT		0x00
#define HORIZ_ODD_LEFT_EVEN_RIGHT		0x01
#define HORIZ_EVEN_LEFT_ODD_RIGHT  		0x02
#define HORIZ_EVEN_LEFT_EVEN_RIGHT		0x03

#define QUINCUNX_ODD_LEFT_EVEN_RIGHT	0x04
#define QUINCUNX_ODD_LEFT_ODD_RIGHT		0x05
#define QUINCUNX_EVEN_LEFT_ODD_RIGHT	0x06
#define QUINCUNX_EVEN_LEFT_EVEN_RIGHT	0x07

#define NO_3D_SUPPORT					0x0F

//===================
// InfoFrames
// InfoFrames types according to PR
#define AVI  						0x00
#define SPD  						0x01
#define AUDIO 						0x02
#define MPEG 						0x03
#define GEN_1	 					0x04
#define GEN_2 						0x05
#define HDMI_VSIF 					0x06
#define GBD 						0x07

// InfoFrames types according to CEA-861-E spec
#define TYPE_HDMI_VSIF_INFOFRAMES	0x81
#define TYPE_AVI_INFOFRAMES		0x82
#define TYPE_SPD_INFOFRAMES		0x83
#define TYPE_AUDIO_INFOFRAMES		0x84
#define TYPE_MPEG_INFOFRAMES		0x85
#define TYPE_HDR_INFOFRAMES		0x87	/* HDR */
#define TYPE_GBD_INFOFRAMES		0x0A
#define TYPE_ISRC1_INFOFRAMES		0x05
#define TYPE_ISRC2_INFOFRAMES		0x06

#define INFOFRAMES_BUFF_LENGTH		0x1F
#define SIZE_AVI_INFOFRAME		0x0E    /* including checksum byte */
#define SIZE_HDR_INFOFRAME		0x1E    /* including checksum byte */

#define AUDIO_INFOFRAMES_LENGTH		0x0A
#define SPD_INFOFRAMES_LENGTH		0x19
#define MPEG_INFOFRAME_LENGTH		0x0A	/* 10 bytes */
#define HDR_INFOFRAME_LENGTH		0x1A	/* 26 bytes */
#define MISC_INFOFRAMES_LENGTH		0x1B
#define PACKET_INFOFRAMES_LENGTH	0x1C

#define AVI_INFOFRAMES_VERSION      0x02
#define MISC_INFOFRAMES_VERSION     0x01

//#define EN_AUDIO_INFOFRAMES         0xC2
#define ENABLE_AND_REPEAT			0xC0

#define EN_AND_RPT_MPEG				0xC3
#define DISABLE_MPEG				0x03	// Also Vendor Specific InfoFrames

#define EN_AND_RPT_AUDIO			0xC2
#define EN_AND_RPT_SPD				0xC1
#define DISABLE_AUDIO				0x02

#define EN_AND_RPT_AVI				0xC0	// Not normally used.  Write to TPI 0x19 instead
#define DISABLE_AVI					0x00	// But this is used to Disable

#define NEXT_FIELD					0x80
#define GBD_PROFILE					0x00
#define AFFECTED_GAMUT_SEQ_NUM		0x01

#define ONLY_PACKET					0x30
#define CURRENT_GAMUT_SEQ_NUM		0x01

// Size of InfoFrame Data types
#define MAX_SIZE_INFOFRAME_DATA     0x22
#define SIZE_AVI_INFOFRAME			0x0E	// 14 bytes
#define SIZE_SPD_INFOFRAME 			0x19	// 25 bytes
#define SIZE_AUDIO_INFOFRAME		0x0E    // Audio (n = 14 bytes); according to PR.
#define SIZE_MPRG_HDMI_INFOFRAME    0x1B	// 27 bytes
#define SIZE_MPEG_INFOFRAME 		0x0A	// 10 bytes
#define SIZE_PACKET_INFOFRAME     	0x1C  	// 28 bytes

#define AVI_INFOFRM_OFFSET          0x0C
#define PACKET_INFOFRM_OFFSET      	0xC3
#define OTHER_INFOFRM_OFFSET        0xC4
#define TPI_INFOFRAME_ACCESS_REG    0xBF

// Serial Communication Buffer constants
#define MAX_COMMAND_ARGUMENTS       50
#define GLOBAL_BYTE_BUF_BLOCK_SIZE  131


//------------------------------------------------------------------------------
// Video Mode Constants
//------------------------------------------------------------------------------
#define VMD_CS_COMPRESSION_STANDARD		0x00
#define VMD_CS_COMPRESSION_OPTIONAL		0x01

#define VMD_ASPECT_RATIO_4x3			0x01
#define VMD_ASPECT_RATIO_16x9			0x02

#define VMD_PIXEL_REP_MAP				0x0F

#define VMD_COLOR_SPACE_MAP				0x03
#define VMD_COLOR_SPACE_RGB				0x00
#define VMD_COLOR_SPACE_YCBCR422		0x02
#define VMD_COLOR_SPACE_YCBCR444		0x01
#define VMD_COLOR_SPACE_BLACK_MODE		0x03

#define VMD_COLOR_DEPTH_MAP				0xC0
#define VMD_COLOR_DEPTH_8BIT			0x00
#define VMD_COLOR_DEPTH_10BIT			0x02
#define VMD_COLOR_DEPTH_12BIT			0x03
#define VMD_COLOR_DEPTH_16BIT			0x01

#define VMD_VIDEO_RANGE_MAP				0x0C
#define VMD_VIDEO_RANGE_AUTO			0x00
#define VMD_VIDEO_RANGE_FULL			0x01
#define VMD_VIDEO_RANGE_LIMITED			0x02

#define VMD_HDCP_NOT_AUTHENTICATED		0x00
#define VMD_HDCP_AUTHENTICATED			0x01

#define VMD_HDMIFORMAT_CEA_VIC          0x00
#define VMD_HDMIFORMAT_HDMI_VIC         0x01
#define VMD_HDMIFORMAT_3D               0x02
#define VMD_HDMIFORMAT_PC               0x03

// These values are from HDMI Spec 1.4 Table H-2
#define VMD_3D_FRAMEPACKING_MAP			0x0F
#define VMD_3D_EXT_DATA_MAP				0x70
#define VMD_3D_FRAMEPACKING				0
#define VMD_3D_FIELDALTERNATIVE			1
#define VMD_3D_LINEALTERNATIVE			2
#define VMD_3D_SIDEBYSIDEFULL			3
#define VMD_3D_LDEPTH					4
#define VMD_3D_LDEPTHGRAPHICS			5
#define VMD_3D_SIDEBYSIDEHALF			8

//------------------------------------------------------------------------------
// Audio Mode Constants
//------------------------------------------------------------------------------
#define AMD_HBRA_OFF					0x00
#define AMD_HBRA_ON						0x01

//------------------------------------------------------------------------------
// Input Color Space Constants
//------------------------------------------------------------------------------
#define ICS_RGB                             0x00    // RGB 4:4:4
#define ICS_YCBCR444                        0x01    // YCbCr 4:4:4
#define ICS_YCBCR422                        0x02    // YCbCr 4:2:2

//------------------------------------------------------------------------------
// Input Range Expansion Constants
//------------------------------------------------------------------------------
#define IVRX_AUTO                           0x00
#define IVRX_ON                             0x04
#define IVRX_OFF                            0x80

//------------------------------------------------------------------------------
// Output Color Space Constants
//------------------------------------------------------------------------------
#define OCS_RGB                             0x00    // RGB 4:4:4
#define OCS_YC444                           0x80    // YCbCr 4:4:4
#define OCS_YC422_8BIT                      0xC0    // YCbCr 4:2:2 8  bit
#define OCS_YC422_10BIT                     0xC8    // YCbCr 4:2:2 10 bit
#define OCS_YC422_MUX_8BIT                  0xE0    // YCbCr 4:2:2 8  bit multiplexed
#define OCS_YC422_MUX_10BIT                 0xE8    // YCbCr 4:2:2 10 bit multiplexed
#define OCS_YC422_MUX_8BIT_EMBED_SYNC       0xF0    // YCbCr 4:2:2 8  bit multiplexed with embedded sync
#define OCS_YC422_MUX_10BIT_EMBEDD_SYNC     0xF8    // YCbCr 4:2:2 10 bit multiplexed with embedded sync

//------------------------------------------------------------------------------
// Optional (Adobe) Color Space Conversion Constants
//------------------------------------------------------------------------------
// Conversion Methods
#define STANDARD_COLOR_SPACE				0x00	// value of standard color space
#define OPTIONAL_COLOR_SPACE				0x80	// value of optional color space

#define ENABLE_SWOverRide_BIT				0x04	// value of SWOverRide Mode

// opRGB to opYCC Conversion
#define VID_ACTION_ENABLE					0x49	// BKDR address of opRGB2opYCC Enable
#define RGB2XVYCC_CTL						0x50	// BKDR address of opRGB2opYCC SWOverRide Mode
#define ENABLE_opRGB2opYCC_BIT			 	0x04	// value of opRGB->opYCbCr Enable bit

// opYCC to opRGB Conversion
#define VID_MODE							0x4A 	// BKDR address of Video Mode(non TPI page - 0x72)
#define XVYCC2RGB_CTL						0x90	// BKDR address of opYCC2opRGB SWOverRide Mode
#define ENABLE_opYCC2opRGB_BITS				0x18	// value of opYCC->opRGB Enable bits
