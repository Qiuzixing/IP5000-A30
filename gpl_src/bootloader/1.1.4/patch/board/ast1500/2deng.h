/*
 * Copyright (c) 2005 ASPEED Technology Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of the authors not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  The authors makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * THE AUTHORS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/* Eng Capability Definition */
#define	ENG_CAP_Sync				0x0001
#define	ENG_CAP_ScreenToScreenCopy		0x0002
#define	ENG_CAP_SolidFill			0x0004
#define	ENG_CAP_SolidLine			0x0008
#define	ENG_CAP_DashedLine			0x0010
#define	ENG_CAP_Mono8x8PatternFill		0x0020
#define	ENG_CAP_Color8x8PatternFill		0x0040
#define	ENG_CAP_CPUToScreenColorExpand		0x0080
#define	ENG_CAP_ScreenToScreenColorExpand	0x0100
#define	ENG_CAP_Clipping			0x0200	
#define ENG_CAP_ALL	(ENG_CAP_Sync | ENG_CAP_ScreenToScreenCopy | ENG_CAP_SolidFill	|	\
                         ENG_CAP_SolidLine | ENG_CAP_DashedLine |				\
                         ENG_CAP_Mono8x8PatternFill | ENG_CAP_Color8x8PatternFill |		\
                         ENG_CAP_Clipping);

/* CMDQ Definition */
#define    AGP_CMD_QUEUE                   	1
#define    VM_CMD_QUEUE                    	0
#define    VM_CMD_MMIO                     	2

#define    CMD_QUEUE_SIZE_256K             	0x00040000
#define    CMD_QUEUE_SIZE_512K             	0x00080000
#define    CMD_QUEUE_SIZE_1M               	0x00100000
#define    CMD_QUEUE_SIZE_2M               	0x00200000
#define    CMD_QUEUE_SIZE_4M               	0x00400000

/* CMD Type Info */
#define    PKT_NULL_CMD             		0x00009561

#define    PKT_SINGLE_LENGTH        		8
#define    PKT_SINGLE_CMD_HEADER    		0x00009562

typedef struct  _PKT_SC
{
    ULONG    PKT_SC_dwHeader;
    ULONG    PKT_SC_dwData[1];
    
} PKT_SC, *PPKT_SC;

/* Eng Reg. Limitation */
#define	MAX_SRC_X				0x7FF
#define	MAX_SRC_Y				0x7FF
#define	MAX_DST_X				0x7FF
#define	MAX_DST_Y				0x7FF

#define	MASK_SRC_PITCH				0x1FFF
#define	MASK_DST_PITCH				0x1FFF
#define	MASK_DST_HEIGHT				0x7FF
#define	MASK_SRC_X				0xFFF
#define	MASK_SRC_Y				0xFFF
#define	MASK_DST_X				0xFFF
#define	MASK_DST_Y				0xFFF
#define	MASK_RECT_WIDTH				0x7FF
#define	MASK_RECT_HEIGHT			0x7FF
#define MASK_CLIP				0xFFF

#define MASK_LINE_X        			0xFFF   
#define MASK_LINE_Y           			0xFFF
#define MASK_LINE_ERR   			0x3FFFFF        
#define MASK_LINE_WIDTH   			0x7FF        
#define MASK_LINE_K1				0x3FFFFF           
#define MASK_LINE_K2				0x3FFFFF
#define MASK_AIPLINE_X        			0xFFF   
#define MASK_AIPLINE_Y         			0xFFF

#define MAX_PATReg_Size				256

/* Eng Reg. Definition */
#define ENG_BASE		0x1E760000  
/* MMIO Reg */
#define MMIOREG_SRC_BASE	(ENG_BASE + 0x0000)                
#define MMIOREG_SRC_PITCH	(ENG_BASE + 0x0004)
#define MMIOREG_DST_BASE	(ENG_BASE + 0x0008)
#define MMIOREG_DST_PITCH	(ENG_BASE + 0x000C)
#define MMIOREG_DST_XY		(ENG_BASE + 0x0010)
#define MMIOREG_SRC_XY		(ENG_BASE + 0x0014)
#define MMIOREG_RECT_XY		(ENG_BASE + 0x0018)
#define MMIOREG_FG		(ENG_BASE + 0x001C)
#define MMIOREG_BG		(ENG_BASE + 0x0020)
#define MMIOREG_FG_SRC		(ENG_BASE + 0x0024)
#define MMIOREG_BG_SRC		(ENG_BASE + 0x0028)
#define MMIOREG_MONO1		(ENG_BASE + 0x002C)
#define MMIOREG_MONO2		(ENG_BASE + 0x0030)
#define MMIOREG_CLIP1		(ENG_BASE + 0x0034)
#define MMIOREG_CLIP2		(ENG_BASE + 0x0038)
#define MMIOREG_CMD		(ENG_BASE + 0x003C)    
#define MMIOREG_PAT		(ENG_BASE + 0x0100)    

#define MMIOREG_LINE_XY         (ENG_BASE + 0x0010)  
#define MMIOREG_LINE_Err        (ENG_BASE + 0x0014)  
#define MMIOREG_LINE_WIDTH      (ENG_BASE + 0x0018)  
#define MMIOREG_LINE_K1         (ENG_BASE + 0x0024)  
#define MMIOREG_LINE_K2         (ENG_BASE + 0x0028)  
#define MMIOREG_LINE_STYLE1     (ENG_BASE + 0x002C)  
#define MMIOREG_LINE_STYLE2     (ENG_BASE + 0x0030)  
#define MMIOREG_LINE_XY2        (ENG_BASE + 0x0014)
#define MMIOREG_LINE_NUMBER     (ENG_BASE + 0x0018)  

/* CMDQ Reg */
#define CMDQREG_SRC_BASE	(0x00 << 24)                       
#define CMDQREG_SRC_PITCH	(0x01 << 24)
#define CMDQREG_DST_BASE	(0x02 << 24)
#define CMDQREG_DST_PITCH	(0x03 << 24)
#define CMDQREG_DST_XY		(0x04 << 24)
#define CMDQREG_SRC_XY		(0x05 << 24)
#define CMDQREG_RECT_XY		(0x06 << 24)
#define CMDQREG_FG		(0x07 << 24)
#define CMDQREG_BG		(0x08 << 24)
#define CMDQREG_FG_SRC		(0x09 << 24)
#define CMDQREG_BG_SRC		(0x0A << 24)
#define CMDQREG_MONO1		(0x0B << 24)
#define CMDQREG_MONO2		(0x0C << 24)
#define CMDQREG_CLIP1		(0x0D << 24)
#define CMDQREG_CLIP2		(0x0E << 24)
#define CMDQREG_CMD		(0x0F << 24)
#define CMDQREG_PAT		(0x40 << 24)

#define CMDQREG_LINE_XY         (0x04 << 24)
#define CMDQREG_LINE_Err        (0x05 << 24)  
#define CMDQREG_LINE_WIDTH      (0x06 << 24)    
#define CMDQREG_LINE_K1         (0x09 << 24) 
#define CMDQREG_LINE_K2         (0x0A << 24)
#define CMDQREG_LINE_STYLE1     (0x0B << 24) 
#define CMDQREG_LINE_STYLE2     (0x0C << 24)
#define CMDQREG_LINE_XY2        (0x05 << 24)
#define CMDQREG_LINE_NUMBER     (0x06 << 24)    

/* CMD Reg. Definition */
#define   CMD_BITBLT                 		0x00000000
#define   CMD_LINEDRAW               		0x00000001
#define   CMD_COLOREXP               		0x00000002
#define   CMD_ENHCOLOREXP            		0x00000003
#define   CMD_TRANSPARENTBLT           		0x00000004
#define   CMD_MASK            	        	0x00000007
					
#define   CMD_DISABLE_CLIP           		0x00000000   
#define   CMD_ENABLE_CLIP            		0x00000008

#define   CMD_COLOR_08               		0x00000000
#define   CMD_COLOR_16               		0x00000010
#define   CMD_COLOR_32               		0x00000020

#define   CMD_SRC_SIQ                		0x00000040

#define   CMD_TRANSPARENT               	0x00000080

#define   CMD_PAT_FGCOLOR            		0x00000000
#define   CMD_PAT_MONOMASK           		0x00010000
#define   CMD_PAT_PATREG             		0x00020000

#define   CMD_OPAQUE                 		0x00000000
#define   CMD_FONT_TRANSPARENT          	0x00040000

#define   CMD_X_INC				0x00000000	
#define   CMD_X_DEC				0x00200000

#define   CMD_Y_INC				0x00000000	
#define   CMD_Y_DEC				0x00100000

#define   CMD_NT_LINE				0x00000000
#define	  CMD_NORMAL_LINE			0x00400000

#define   CMD_DRAW_LAST_PIXEL           	0x00000000
#define   CMD_NOT_DRAW_LAST_PIXEL       	0x00800000

#define   CMD_DISABLE_LINE_STYLE     		0x00000000
#define   CMD_ENABLE_LINE_STYLE      		0x40000000

#define   CMD_RESET_STYLE_COUNTER       	0x80000000
#define   CMD_NOT_RESET_STYLE_COUNTER   	0x00000000

#define   BURST_FORCE_CMD            		0x80000000

/* Line */
#define	LINEPARAM_XM				0x00000001
#define	LINEPARAM_X_DEC				0x00000002
#define	LINEPARAM_Y_DEC				0x00000004

typedef struct _LINEPARAM {
    USHORT	dsLineX;
    USHORT	dsLineY;
    USHORT	dsLineWidth;
    ULONG	dwErrorTerm;
    ULONG	dwK1Term;
    ULONG	dwK2Term;
    ULONG	dwLineAttributes;	
} LINEPARAM, *PLINEPARAM;

typedef struct {
	
    LONG X1;
    LONG Y1;
    LONG X2;
    LONG Y2;	
    
} _LINEInfo;

/* Macro */
/* MMIO 2D Macro */
#define ASTSetupSRCBase_MMIO(base) \
      { \
        do { \
           *(ULONG *)(MMIOREG_SRC_BASE) = (ULONG) (base); \
        } while (*(volatile ULONG *)(MMIOREG_SRC_BASE) != (ULONG) (base)); \
      }
#define ASTSetupSRCPitch_MMIO(pitch) \
      { \
        do { \
           *(ULONG *)(MMIOREG_SRC_PITCH) = (ULONG)(pitch << 16); \
        } while (*(volatile ULONG *)(MMIOREG_SRC_PITCH) != (ULONG)(pitch << 16)); \
      }
#define ASTSetupDSTBase_MMIO(base) \
      { \
        do { \
           *(ULONG *)(MMIOREG_DST_BASE) = (ULONG)(base); \
        } while (*(volatile ULONG *)(MMIOREG_DST_BASE) != (ULONG)(base)); \
      }      
#define ASTSetupDSTPitchHeight_MMIO(pitch, height) \
      { \
        ULONG dstpitch; \
        dstpitch = (ULONG)((pitch << 16) + ((height) & MASK_DST_HEIGHT)); \
        do { \
           *(ULONG *)(MMIOREG_DST_PITCH) = dstpitch; \
        } while (*(volatile ULONG *)(MMIOREG_DST_PITCH) != dstpitch); \
      }      
#define ASTSetupDSTXY_MMIO(x, y) \
      { \
        ULONG dstxy; \
        dstxy = (ULONG)(((x & MASK_DST_X) << 16) + (y & MASK_DST_Y)); \
        do { \
           *(ULONG *)(MMIOREG_DST_XY) = dstxy; \
        } while (*(volatile ULONG *)(MMIOREG_DST_XY) != dstxy); \
      }           
#define ASTSetupSRCXY_MMIO(x, y) \
      { \
        ULONG srcxy; \
        srcxy = (ULONG)(((x & MASK_SRC_X) << 16) + (y & MASK_SRC_Y)); \
        do { \
           *(ULONG *)(MMIOREG_SRC_XY) = srcxy; \
        } while (*(volatile ULONG *)(MMIOREG_SRC_XY) != srcxy); \
      }             
#define ASTSetupRECTXY_MMIO(x, y) \
      { \
        ULONG rectxy; \
        rectxy = (ULONG)(((x & MASK_RECT_WIDTH) << 16) + (y & MASK_RECT_WIDTH)); \
        do { \
           *(ULONG *)(MMIOREG_RECT_XY) = rectxy; \
        } while (*(volatile ULONG *)(MMIOREG_RECT_XY) != rectxy); \
      }  
#define ASTSetupFG_MMIO(color) \
      { \
        do { \
           *(ULONG *)(MMIOREG_FG) = (ULONG)(color); \
        } while (*(volatile ULONG *)(MMIOREG_FG) != (ULONG)(color)); \
      } 
#define ASTSetupBG_MMIO(color) \
      { \
        do { \
           *(ULONG *)(MMIOREG_BG) = (ULONG)(color); \
        } while (*(volatile ULONG *)(MMIOREG_BG) != (ULONG)(color)); \
      }
#define ASTSetupMONO1_MMIO(pat) \
      { \
        do { \
          *(ULONG *)(MMIOREG_MONO1) = (ULONG)(pat); \
        } while (*(volatile ULONG *)(MMIOREG_MONO1) != (ULONG)(pat)); \
      } 
#define ASTSetupMONO2_MMIO(pat) \
      { \
        do { \
          *(ULONG *)(MMIOREG_MONO2) = (ULONG)(pat); \
        } while (*(volatile ULONG *)(MMIOREG_MONO2) != (ULONG)(pat)); \
      }
#define ASTSetupCLIP1_MMIO(left, top) \
      { \
       ULONG clip1; \
       clip1 = (ULONG)(((left & MASK_CLIP) << 16) + (top & MASK_CLIP)); \
       do { \
          *(ULONG *)(MMIOREG_CLIP1) = clip1; \
       } while (*(volatile ULONG *)(MMIOREG_CLIP1) != clip1); \
      } 
#define ASTSetupCLIP2_MMIO(right, bottom) \
      { \
       ULONG clip2; \
       clip2 = (ULONG)(((right & MASK_CLIP) << 16) + (bottom & MASK_CLIP)); \
       do { \
          *(ULONG *)(MMIOREG_CLIP2) = clip2; \
       } while (*(volatile ULONG *)(MMIOREG_CLIP2) != clip2); \
      }                                                                                               
#define ASTSetupCMDReg_MMIO(reg) \
      { \
        *(ULONG *)(MMIOREG_CMD) = (ULONG)(reg);	\
      }
#define ASTSetupPatReg_MMIO(patreg, pat) \
      { \
       do { \
          *(ULONG *)(MMIOREG_PAT + patreg*4) = (ULONG)(pat); \
       } while (*(volatile ULONG *)(MMIOREG_PAT + patreg*4) != (ULONG)(pat)); \
      }      
                                
/* Line CMD */
#define ASTSetupLineXY_MMIO(x, y) \
      { \
        ULONG linexy; \
        linexy = (ULONG)(((x & MASK_LINE_X) << 16) + (y & MASK_LINE_Y)); \
        do { \
           *(ULONG *)(MMIOREG_LINE_XY) = linexy; \
        } while (*(volatile ULONG *)(MMIOREG_LINE_XY) != linexy); \
      }
#define ASTSetupLineXMErrTerm_MMIO(xm, err) \
      { \
        ULONG lineerr; \
        lineerr = (ULONG)((xm << 24) + (err & MASK_LINE_ERR)); \
        do { \
           *(ULONG *)(MMIOREG_LINE_Err) = lineerr; \
        } while (*(volatile ULONG *)(MMIOREG_LINE_Err) != lineerr); \
      }      
#define ASTSetupLineWidth_MMIO(width) \
      { \
        ULONG linewidth; \
        linewidth = (ULONG)((width & MASK_LINE_WIDTH) << 16); \
        do { \
          *(ULONG *)(MMIOREG_LINE_WIDTH) = linewidth; \
        } while (*(volatile ULONG *)(MMIOREG_LINE_WIDTH) != linewidth); \
      }
#define ASTSetupLineK1Term_MMIO(err) \
      { \
        do { \
          *(ULONG *)(MMIOREG_LINE_K1) = (ULONG)(err & MASK_LINE_K1); \
        } while (*(volatile ULONG *)(MMIOREG_LINE_K1) != (ULONG)(err & MASK_LINE_K1)); \
      }            
#define ASTSetupLineK2Term_MMIO(err) \
      { \
        do { \
           *(ULONG *)(MMIOREG_LINE_K2) = (ULONG)(err & MASK_LINE_K2); \
        } while (*(volatile ULONG *)(MMIOREG_LINE_K2) != (ULONG)(err & MASK_LINE_K2)); \
      }
#define ASTSetupLineStyle1_MMIO(pat) \
      { \
        do { \
           *(ULONG *)(MMIOREG_LINE_STYLE1) = (ULONG)(pat); \
        } while (*(volatile ULONG *)(MMIOREG_LINE_STYLE1) != (ULONG)(pat)); \
      } 
#define ASTSetupLineStyle2_MMIO(pat) \
      { \
        do { \
          *(ULONG *)(MMIOREG_LINE_STYLE2) = (ULONG)(pat); \
        } while (*(volatile ULONG *)(MMIOREG_LINE_STYLE2) != (ULONG)(pat)); \
      }

/* AIP Line CMD */
#define AIPSetupLineXY_MMIO(x, y) \
      { \
        ULONG linexy; \
        linexy = (ULONG)(((x & MASK_AIPLINE_X) << 16) + (y & MASK_AIPLINE_Y)); \
        do { \
           *(ULONG *)(MMIOREG_LINE_XY) = linexy; \
        } while (*(volatile ULONG *)(MMIOREG_LINE_XY) != linexy); \
      }
#define AIPSetupLineXY2_MMIO(x, y) \
      { \
        ULONG linexy; \
        linexy = (ULONG)(((x & MASK_AIPLINE_X) << 16) + (y & MASK_AIPLINE_Y)); \
        do { \
           *(ULONG *)(MMIOREG_LINE_XY2) = linexy; \
        } while (*(volatile ULONG *)(MMIOREG_LINE_XY2) != linexy); \
      }
#define AIPSetupLineNumber_MMIO(no) \
      { \
        do { \
           *(ULONG *)(MMIOREG_LINE_NUMBER) = (ULONG) no; \
        } while (*(volatile ULONG *)(MMIOREG_LINE_NUMBER) != (ULONG) no); \
      }

/* CMDQ Mode Macro */
/*
#define mUpdateWritePointer *(ULONG *) (pAST->CMDQInfo.pjWritePort) = (pAST->CMDQInfo.ulWritePointer >>3)
*/

/* General CMD */
#define ASTSetupSRCBase(addr, base) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_SRC_BASE); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(base);					\
      }
#define ASTSetupSRCPitch(addr, pitch) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_SRC_PITCH); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(pitch << 16);					\
      }
#define ASTSetupDSTBase(addr, base) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_DST_BASE); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(base);					\
      }      
#define ASTSetupDSTPitchHeight(addr, pitch, height) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_DST_PITCH); 	\
        addr->PKT_SC_dwData[0] = (ULONG)((pitch << 16) + ((height) & MASK_DST_HEIGHT));					\
      }      
#define ASTSetupDSTXY(addr, x, y) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_DST_XY); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((x & MASK_DST_X) << 16) + (y & MASK_DST_Y));					\
      }           
#define ASTSetupSRCXY(addr, x, y) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_SRC_XY); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((x & MASK_SRC_X) << 16) + (y & MASK_SRC_Y));					\
      }             
#define ASTSetupRECTXY(addr, x, y) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_RECT_XY); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((x & MASK_RECT_WIDTH) << 16) + (y & MASK_RECT_WIDTH));					\
      }  
#define ASTSetupFG(addr, color) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_FG); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(color);					\
      }
#define ASTSetupBG(addr, color) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_BG); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(color);					\
      }
#define ASTSetupMONO1(addr, pat) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_MONO1); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(pat);				\
      }            
#define ASTSetupMONO2(addr, pat) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_MONO2); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(pat);				\
      }     
#define ASTSetupCLIP1(addr, left, top) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_CLIP1); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((left & MASK_CLIP) << 16) + (top & MASK_CLIP));	\
      }            
#define ASTSetupCLIP2(addr, right, bottom) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_CLIP2); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((right & MASK_CLIP) << 16) + (bottom & MASK_CLIP));	\
      }                                                                                                    
#define ASTSetupCMDReg(addr, reg) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_CMD); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(reg);					\
      }
#define ASTSetupPatReg(addr, patreg, pat) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + (CMDQREG_PAT + (patreg << 24))); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(pat);				\
      }    

/* Line CMD */
#define ASTSetupLineXY(addr, x, y) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_XY); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((x & MASK_LINE_X) << 16) + (y & MASK_LINE_Y));					\
      }
#define ASTSetupLineXMErrTerm(addr, xm, err) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_Err); 	\
        addr->PKT_SC_dwData[0] = (ULONG)((xm << 24) + (err & MASK_LINE_ERR));					\
      }      
#define ASTSetupLineWidth(addr, width) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_WIDTH); 	\
        addr->PKT_SC_dwData[0] = (ULONG)((width & MASK_LINE_WIDTH) << 16);				\
      }            
#define ASTSetupLineK1Term(addr, err) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_K1); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(err & MASK_LINE_K1);				\
      }            
#define ASTSetupLineK2Term(addr, err) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_K2); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(err & MASK_LINE_K2);				\
      }     
#define ASTSetupLineStyle1(addr, pat) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_STYLE1); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(pat);				\
      }            
#define ASTSetupLineStyle2(addr, pat) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_STYLE2); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(pat);				\
      }     

#define ASTSetupNULLCMD(addr) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG) (PKT_NULL_CMD); 			\
        addr->PKT_SC_dwData[0] = (ULONG) 0;					\
      }

/* AIP Line CMD */
#define AIPSetupLineXY(addr, x, y) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_XY); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((x & MASK_AIPLINE_X) << 16) + (y & MASK_AIPLINE_Y));					\
      }
#define AIPSetupLineXY2(addr, x, y) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_XY2); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(((x & MASK_AIPLINE_X) << 16) + (y & MASK_AIPLINE_Y));					\
      }
#define AIPSetupLineNumber(addr, no) \
      { \
        addr->PKT_SC_dwHeader  = (ULONG)(PKT_SINGLE_CMD_HEADER + CMDQREG_LINE_NUMBER); 	\
        addr->PKT_SC_dwData[0] = (ULONG)(no);					\
      }
