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
 * @file  si_cpi_regs.h
 *
 * @brief   SiI9387 Device CPI Registers Manifest Constants.
 *
 *****************************************************************************
*/

#ifndef __SI_CPI_REGS_H__
#define __SI_CPI_REGS_H__

//------------------------------------------------------------------------------
// NOTE: Register addresses are 16 bit values with page and offset combined.
//
// Examples:  0x005 = page 0, offset 0x05
//            0x1B6 = page 1, offset 0xB6
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Registers in Page 8
//------------------------------------------------------------------------------

#define REG_CEC_DEBUG_2             0x886

#define	REG_CEC_DEBUG_3             0x887
#define BIT_SNOOP_EN                        0x01
#define BIT_FLUSH_TX_FIFO                   0x80

#define REG_CEC_TX_INIT             0x888
#define BIT_SEND_POLL                       0x80

#define REG_CEC_TX_DEST             0x889

#define REG_CEC_CONFIG_CPI          0x88E

#define REG_CEC_TX_COMMAND          0x88F
#define REG_CEC_TX_OPERAND_0        0x890

#define REG_CEC_TRANSMIT_DATA       0x89F
#define	BIT_TX_BFR_ACCESS                   0x40
#define	BIT_TX_AUTO_CALC                    0x20
#define	BIT_TRANSMIT_CMD                    0x10

#define REG_CEC_CAPTURE_ID0         0x8A2

#define REG_CEC_INT_ENABLE_0        0x8A4
#define BIT_TX_FIFO_FULL                    0x20

#define REG_CEC_INT_ENABLE_1        0x8A5
#define BIT_RX_FIFO_OVERRUN                 0x08

// 0xA6 CPI Interrupt Status Register (R/W)
#define REG_CEC_INT_STATUS_0        0x8A6
#define BIT_CEC_LINE_STATE                  0x80
#define BIT_TX_MESSAGE_SENT                 0x20
#define BIT_TX_HOTPLUG                      0x10
#define BIT_POWER_STAT_CHANGE               0x08
#define BIT_TX_FIFO_EMPTY                   0x04
#define BIT_RX_MSG_RECEIVED                 0x02
#define BIT_CMD_RECEIVED                    0x01

// 0xA7 CPI Interrupt Status Register (R/W)
#define REG_CEC_INT_STATUS_1        0x8A7
#define BIT_RX_FIFO_OVERRUN                 0x08
#define BIT_SHORT_PULSE_DET                 0x04
#define BIT_FRAME_RETRANSM_OV               0x02
#define BIT_START_IRREGULAR                 0x01

#define REG_CEC_RX_CONTROL          0x8AC
// CEC  CEC_RX_CONTROL bits
#define BIT_CLR_RX_FIFO_CUR         0x01
#define BIT_CLR_RX_FIFO_ALL         0x02

#define REG_CEC_RX_COUNT            0x8AD
#define BIT_MSG_ERROR               0x80


#define REG_CEC_RX_CMD_HEADER       0x8AE
#define REG_CEC_RX_OPCODE           0x8AF
#define REG_CEC_RX_OPERAND_0        0x8B0


#define REG_CEC_RX_COUNT            0x8AD

#define CEC_OP_ABORT_0              0x8C0
#define CEC_OP_ABORT_31             0x8DF

#define REG_CEC_DISCOVERY_CTRL		0x8E0
#define DISCOVERY_START		0x01
#define DISCOVERY_STATUS_CLR	0x02
#define DISCOVERY_DONE		0x80
#define REG_CEC_DISCOVERY_STATUS_0	0x8E1
#define REG_CEC_DISCOVERY_STATUS_1	0x8E2

#endif  // __SI_CPI_REGS_H__
