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
 * @file  RegBits.h
 *
 * @brief Register bit definitions.
 *
 *****************************************************************************
*/

#define T_EN_TPI       	10
#define T_HPD_DELAY    	10



#define DDC_ABORT           BIT_2
#define MSC_MR_MSC_MSG      BIT_3
#define MSC_MT_DONE         BIT_4
#define MSC_RequesterAbort  BIT_5
#define MSC_ResponderAbort  BIT_6
#define MSC_ABORT (MSC_ResponderAbort|MSC_RequesterAbort)

#define SYS_STAT_RSEN       BIT_2

#define INTR4_SCDT_CHANGE   BIT_0
#define INTR4_RPWR5V_CHANGE BIT_1
#define INTR4_MHL_EST       BIT_2
#define INTR4_USB_EST       BIT_3
#define INTR4_CBUS_LKOUT    BIT_4
#define INTR4_VBUS_LOW      BIT_5
#define INTR4_RGND_RDY      BIT_6
#define INTR4_PVT_HTBT_FAIL BIT_7

#define INTR4_MASK_SCDT_CHANGE_MASK         0x01
#define INTR4_MASK_SCDT_CHANGE_DISABLE      0x00
#define INTR4_MASK_SCDT_CHANGE_ENABLE       0x01

#define INTR4_MASK_RPWR5V_CHANGE_MASK       0x02
#define INTR4_MASK_RPWR5V_CHANGE_DISABLE    0x00
#define INTR4_MASK_RPWR5V_CHANGE_ENABLE     0x02

#define INTR4_MASK_MHL_EST_MASK             0x04
#define INTR4_MASK_MHL_EST_DISABLE          0x00
#define INTR4_MASK_MHL_EST_ENABLE           0x04

#define INTR4_MASK_USB_EST_MASK             0x08
#define INTR4_MASK_USB_EST_DISABLE          0x00
#define INTR4_MASK_USB_EST_ENABLE           0x08

#define INTR4_MASK_CBUS_LKOUT_MASK          0x10
#define INTR4_MASK_CBUS_LKOUT_DISABLE       0x00
#define INTR4_MASK_CBUS_LKOUT_ENABLE        0x10

#define INTR4_MASK_VBUS_LOW_MASK            0x20
#define INTR4_MASK_VBUS_LOW_DISABLE         0x00
#define INTR4_MASK_VBUS_LOW_ENABLE          0x20

#define INTR4_MASK_RGND_RDY_MASK            0x40
#define INTR4_MASK_RGND_RDY_DISABLE         0x00
#define INTR4_MASK_RGND_RDY_ENABLE          0x40

#define INTR4_MASK_PVT_HTBT_FAIL_MASK       0x80
#define INTR4_MASK_PVT_HTBT_FAIL_DISABLE    0x00
#define INTR4_MASK_PVT_HTBT_FAIL_ENABLE     0x80


#define INT_CTRL_RSVD0_MASK                       0x01

#define INT_CTRL_REG_INTR_POLARITY_MASK           0x02
    #define INT_CTRL_REG_INTR_POLARITY_AST1           0x00
    #define INT_CTRL_REG_INTR_POLARITY_AST0           0x02

#define INT_CTRL_REG_INTR_OD_MASK                 0x04
    #define INT_CTRL_REG_INTR_OD_PUSH_PULL            0x00
    #define INT_CTRL_REG_INTR_OD_OPEN_DRAIN           0x04

#define INT_CTRL_REG_SOFT_INTR_EN_MASK            0x08
    #define INT_CTRL_REG_SOFT_INTR_EN_DISABLE         0x00
    #define INT_CTRL_REG_SOFT_INTR_EN_ENABLE          0x08

#define INT_CTRL_REG_HPD_OUT_OVR_EN_MASK          0x10
    #define INT_CTRL_REG_HPD_OUT_OVR_EN_DISABLE       0x00
    #define INT_CTRL_REG_HPD_OUT_OVR_EN_ENABLE        0x10

#define INT_CTRL_REG_HPD_OUT_OVR_VAL_MASK         0x20
    #define INT_CTRL_REG_HPD_OUT_OVR_VAL_LOW          0x00
    #define INT_CTRL_REG_HPD_OUT_OVR_VAL_HIGH         0x20

#define INT_CTRL_REG_HPDOUT_OD_EN_MASK            0x40
    #define INT_CTRL_REG_HPDOUT_OD_EN_DISABLE          0x00
    #define INT_CTRL_REG_HPDOUT_OD_EN_ENABLE           0x40

#define INT_CTRL_RSVD7_MASK                       0x07

#define MSC_REQUESTER_ABORT_REASON_DOWNSTREAM_HOT_PLUG_STATUS  BIT_6
//#define MSC_REQUESTER_ABORT_REASON_DOWNSTREAM_HOT_PLUG_STATUS_SHIFT_COUNT 6


#define DISC_CTRL1_REG_DISC_EN_MASK             0x01
#define DISC_CTRL1_REG_DISC_EN_DISABLE          0x00
#define DISC_CTRL1_REG_DISC_EN_ENABLE           0x01

#define DISC_CTRL1_REG_PON_N_MASK               0x02
#define DISC_CTRL1_REG_PON_STROBE_ACTIVE_LOW    0x00
#define DISC_CTRL1_REG_PON_DEFAULT              0x02

#define DISC_CTRL1_REG_DISC_CYCLE_MASK          0x0C
#define DISC_CTRL1_REG_DISC_CYCLE_50uS          0x00
#define DISC_CTRL1_REG_DISC_CYCLE_100uS         0x04
#define DISC_CTRL1_REG_DISC_CYCLE_150uS         0x08
#define DISC_CTRL1_REG_DISC_CYCLE_200uS         0x0C

#define DISC_CTRL1_REG_DISC_CYC_MASK            0x70
#define DISC_CTRL1_REG_DISC_CYC_5_ATTEMPTS      0x00
#define DISC_CTRL1_REG_DISC_CYC_10_ATTEMPTS     0x10
#define DISC_CTRL1_REG_DISC_CYC_20_ATTEMPTS     0x20
#define DISC_CTRL1_REG_DISC_CYC_64_ATTEMPTS     0x30
#define DISC_CTRL1_REG_DISC_CYC_256_ATTEMPTS    0x40
#define DISC_CTRL1_REG_DISC_CYC_512_ATTEMPTS    0x50
#define DISC_CTRL1_REG_DISC_CYC_768_ATTEMPTS    0x60
#define DISC_CTRL1_REG_DISC_CYC_1023_ATTEMPTS   0x70

#define DISC_CTRL1_REG_CBUS_INTR_EN_MASK        0x80
#define DISC_CTRL1_REG_CBUS_INTR_EN_DISABLED    0x00
#define DISC_CTRL1_REG_CBUS_INTR_EN_ENABLE      0x80

#define DISC_CTRL2_REG_DEGLITCH_TIME_MASK   0x07
#define DISC_CTRL2_REG_DEGLITCH_TIME_2MS    0x00
#define DISC_CTRL2_REG_DEGLITCH_TIME_4MS    0x01
#define DISC_CTRL2_REG_DEGLITCH_TIME_8MS    0x02
#define DISC_CTRL2_REG_DEGLITCH_TIME_16MS   0x03
#define DISC_CTRL2_REG_DEGLITCH_TIME_40MS   0x04
#define DISC_CTRL2_REG_DEGLITCH_TIME_50MS   0x05
#define DISC_CTRL2_REG_DEGLITCH_TIME_60MS   0x06
#define DISC_CTRL2_REG_DEGLITCH_TIME_128MS  0x07

#define DISC_CTRL2_REG_CBUS100k_EN_MASK    0x08
#define DISC_CTRL2_REG_CBUS100k_EN_DISABLE 0x00
#define DISC_CTRL2_REG_CBUS100k_EN_ENABLE  0x08

#define DISC_CTRL2_REG_ATT_THRESH_MASK      0x30
#define DISC_CTRL2_REG_ATT_THRESH_EIGHTH    0x00
#define DISC_CTRL2_REG_ATT_THRESH_QUARTER   0x10
#define DISC_CTRL2_REG_ATT_THRESH_HALF      0x20
#define DISC_CTRL2_REG_ATT_THRESH_WHOLE     0x30

#define DISC_CTRL2_REG_SKIP_RGND_MASK       0x40
#define DISC_CTRL2_REG_SKIP_RGND_CONDUCTED  0x00
#define DISC_CTRL2_REG_SKIP_RGND_SKIPPED    0x40

#define DISC_CTRL2_REG_DLYTRG_EN_MASK       0x80
#define DISC_CTRL2_REG_DLYTRG_EN_DISABLE    0x00
#define DISC_CTRL2_REG_DLYTRG_EN_ENABLE     0x80

#define DISC_CTRL3_REG_DLYTRG_SEL_MASK      0x07
#define DISC_CTRL3_REG_DLYTRG_SEL_133uS     0x00
#define DISC_CTRL3_REG_DLYTRG_SEL_534uS     0x01
#define DISC_CTRL3_REG_DLYTRG_SEL_2MS       0x02
#define DISC_CTRL3_REG_DLYTRG_SEL_8MS       0x03
#define DISC_CTRL3_REG_DLYTRG_SEL_16MS      0x04
#define DISC_CTRL3_REG_DLYTRG_SEL_32MS      0x05
#define DISC_CTRL3_REG_DLYTRG_SEL_64MS      0x06
#define DISC_CTRL3_REG_DLYTRG_SEL_128MS     0x07

#define DISC_CTRL3_REG_USB_EN_MASK          0x08
#define DISC_CTRL3_REG_USB_EN_MHL           0x00
#define DISC_CTRL3_REG_USB_EN_USB           0x08

#define DISC_CTRL3_REG_FORCE_USB_MASK       0x10
#define DISC_CTRL3_REG_FORCE_USB_USE_CBUS   0x00
#define DISC_CTRL3_REG_FORCE_USB_FORCE_USB  0x10

#define DISC_CTRL3_REG_DISC_SIMODE_MASK     0x20
#define DISC_CTRL3_REG_DISC_SIMODE_DISABLE  0x00
#define DISC_CTRL3_REG_DISC_SIMODE_ENABLE   0x20

#define DISC_CTRL3_REG_FORCE_MHL_MASK       0x40
#define DISC_CTRL3_REG_FORCE_MHL_USE_CBUS   0x00
#define DISC_CTRL3_REG_FORCE_MHL_FORCE_MHL  0x40

#define DISC_CTRL3_REG_COMM_IMME_MASK       0x80
#define DISC_CTRL3_REG_COMM_IMME_HOLD       0x00
#define DISC_CTRL3_REG_COMM_IMME_ALLOW      0x80

#define DISC_CTRL4_REG_LOOP_THRESH_MASK         0x07
#define DISC_CTRL4_REG_LOOP_THRESH_DEFAULT      0x04

#define DISC_CTRL4_REG_USB_D_SW_MASK            0x08
#define DISC_CTRL4_REG_USB_D_SW_MHL             0x00
#define DISC_CTRL4_REG_USB_D_SW_USB             0x08

#define DISC_CTRL4_REG_CBUSIDLE_PUP_SEL_MASK    0x30
#define DISC_CTRL4_REG_CBUSIDLE_PUP_SEL_OFF     0x00
#define DISC_CTRL4_REG_CBUSIDLE_PUP_SEL_20K     0x10
#define DISC_CTRL4_REG_CBUSIDLE_PUP_SEL_10K     0x20
#define DISC_CTRL4_REG_CBUSIDLE_PUP_SEL_5K      0x30

#define DISC_CTRL4_REG_CBUSDISC_PUP_SEL_MASK    0xC0
#define DISC_CTRL4_REG_CBUSDISC_PUP_SEL_OFF     0x00
#define DISC_CTRL4_REG_CBUSDISC_PUP_SEL_20K     0x40
#define DISC_CTRL4_REG_CBUSDISC_PUP_SEL_10K     0x80
#define DISC_CTRL4_REG_CBUSDISC_PUP_SEL_5K      0xC0

#define DISC_CTRL5_REG_CBUSMHL_PUP_SEL_MASK         0x03
#define DISC_CTRL5_REG_CBUSMHL_PUP_SEL_OFF          0x00
#define DISC_CTRL5_REG_CBUSMHL_PUP_SEL_20K          0x01
#define DISC_CTRL5_REG_CBUSMHL_PUP_SEL_10K          0x02
#define DISC_CTRL5_REG_CBUSMHL_PUP_SEL_5K           0x03

#define DISC_CTRL5_REG_CBUS_VTH_SEL_MASK            0x04
#define DISC_CTRL5_REG_CBUS_VTH_SEL_1_2V            0x00
#define DISC_CTRL5_REG_CBUS_VTH_SEL_1_8V            0x04

#define DISC_CTRL5_REG_DSM_OVRIDE_MASK              0x08
#define DISC_CTRL5_REG_DSM_OVRIDE_DISABLE           0x00
#define DISC_CTRL5_REG_DSM_OVRIDE_USE_REG_DISC_SM   0x08

#define DISC_CTRL5_REG_RGND_LEVEL_CTL_MASK          0x30
#define DISC_CTRL5_REG_RGND_LEVEL_CTL_TBD_00        0x00
#define DISC_CTRL5_REG_RGND_LEVEL_CTL_TBD_10        0x10
#define DISC_CTRL5_REG_RGND_LEVEL_CTL_TBD_20        0x20
#define DISC_CTRL5_REG_RGND_LEVEL_CTL_TBD_30        0x30

#define DISC_CTRL5_REG_RGND_DETECT_MODE_MASK        0x40
#define DISC_CTRL5_REG_RGND_DETECT_MODE_SW          0x00
#define DISC_CTRL5_REG_RGND_DETECT_MODE_HW          0x40

#define DISC_CTRL5_REG_RGND_DETECT_SW_MASK          0x80
#define DISC_CTRL5_REG_RGND_DETECT_SW_TBD_DISABLED  0x00
#define DISC_CTRL5_REG_RGND_DETECT_SW_TBD_ENABLED   0x80



#define DISC_CTRL6_REG_SINGLE_ATT_MASK                  0x01
#define DISC_CTRL6_REG_SINGLE_ATT_SINGLE                0x00
#define DISC_CTRL6_REG_SINGLE_ATT_MULTIPLE              0x01

#define DISC_CTRL6_REG_CIC2A_WKUP_MASK                  0x02
#define DISC_CTRL6_REG_CIC2A_WKUP_DISABLE               0x00
#define DISC_CTRL6_REG_CIC2A_WKUP_ENABLE                0x02

#define DISC_CTRL6_REG_CIC2A_POL_MASK                   0x04
#define DISC_CTRL6_REG_CIC2A_POL_ACTIVE_HIGH            0x00
#define DISC_CTRL6_REG_CIC2A_POL_ACTIVE_LOW             0x04

#define DISC_CTRL6_REG_SKIP_DEGLITCH_MASK               0x08
#define DISC_CTRL6_REG_SKIP_DEGLITCH_CONDUCT            0x00
#define DISC_CTRL6_REG_SKIP_DEGLITCH_SKIP               0x08

#define DISC_CTRL6_REG_BLOCK_RGNDINT_MASK               0x10
#define DISC_CTRL6_REG_BLOCK_RGNDINT_ALLOW              0x00
#define DISC_CTRL6_REG_BLOCK_RGNDINT_BLOCK              0x10


#define DISC_CTRL6_REG_DRV_FLT_SEL_MASK                 0x20
#define DISC_CTRL6_REG_DRV_FLT_SEL_USB                  0x00
#define DISC_CTRL6_REG_DRV_FLT_SEL_FLOAT                0x20

#define DISC_CTRL6_REG_USB_OVRIDE_MASK                  0x40
#define DISC_CTRL6_REG_USB_OVRIDE_DISABLE               0x00
#define DISC_CTRL6_REG_USB_OVRIDE_USE_REG_USB_EN        0x40

#define DISC_CTRL6_REG_USB_D_OVRIDE_MASK                0x80
#define DISC_CTRL6_REG_USB_D_OVRIDE_DISABLE             0x00
#define DISC_CTRL6_REG_USB_D_OVRIDE_USE_REG_USB_D_SW    0x80

#define DISC_CTRL7_REG_RGND_INTP_MASK                   0x03
#define DISC_CTRL7_REG_RGND_INTP_ONLY_1K                0x00
#define DISC_CTRL7_REG_RGND_INTP_ONLY_2K                0x01
#define DISC_CTRL7_REG_RGND_INTP_BOTH                   0x02
#define DISC_CTRL7_REG_RGND_INTP_INVALID                0x03

#define DISC_CTRL7_REG_VBUS_CHECK_MASK                  0x04
#define DISC_CTRL7_REG_VBUS_CHECK_IDLE                  0x00
#define DISC_CTRL7_REG_VBUS_CHECK_VBUS_CHK              0x04

#define DISC_CTRL7_REG_CBUS_DBG_MODE_MASK               0x08
#define DISC_CTRL7_REG_CBUS_DBG_MODE_DISABLE            0x00
#define DISC_CTRL7_REG_CBUS_DBG_MODE_ENABLE             0x08

#define DISC_CTRL7_REG_USB_ID_PD_EN_MASK                0x10
#define DISC_CTRL7_REG_USB_ID_PD_EN_HW                  0x00
#define DISC_CTRL7_REG_USB_ID_PD_EN_USE_REG_USB_PD_VAL  0x10

#define DISC_CTRL7_REG_USB_PD_VAL_MASK                  0x20
#define DISC_CTRL7_REG_USB_PD_VAL_PULL_DOWN             0x00
#define DISC_CTRL7_REG_USB_PD_VAL_NO_PULL_DOWN          0x20

#define DISC_CTRL7_REG_CBUSLVL_SW_MASK                  0x40
#define DISC_CTRL7_REG_CBUSLVL_SW_USE_HW                0x00
#define DISC_CTRL7_REG_CBUSLVL_SW_USE_REG_CBUSLVL_VAL   0x40

#define DISC_CTRL7_REG_CBUSLVL_VAL_MASK                 0x80
#define DISC_CTRL7_REG_CBUSLVL_VAL_LEVEL_0              0x00
#define DISC_CTRL7_REG_CBUSLVL_VAL_LEVEL_1              0x80

#define DISC_CTRL8_REG_HTBTFAIL_AUTO_EN_MASK            0x01
#define DISC_CTRL8_REG_HTBTFAIL_AUTO_EN_DISABLE         0x00
#define DISC_CTRL8_REG_HTBTFAIL_AUTO_EN_ENABLE          0x01
#define DISC_CTRL8_REG_SKIP_VBUS_MASK                   0x02
#define DISC_CTRL8_REG_SKIP_VBUS_DISABLE                0x00
#define DISC_CTRL8_REG_SKIP_VBUS_ENABLE                 0x02
#define DISC_CTRL8_REG_RSVD_MASK                        0xFC



#define DISC_STAT2_RGND_OPEN    0x00
#define DISC_STAT2_RGND_2K_OHM  0x01
#define DISC_STAT2_RGND_1K_OHM  0x02
#define DISC_STAT2_RGND_SHORT   0x03

#define DISC_STAT2_RGND_MASK    0x03
