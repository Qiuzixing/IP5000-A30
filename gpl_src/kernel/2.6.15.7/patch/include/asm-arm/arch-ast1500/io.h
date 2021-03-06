/*
 *  linux/include/asm-arm/arch-mvp2000/io.h
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
#ifndef __ASM_ARM_ARCH_IO_H
#define __ASM_ARM_ARCH_IO_H

#define IO_SPACE_LIMIT 		0x0000ffff

#define	BIT(x)			((1)<<(x))

#define __io(a)			((void __iomem *)a)
#define __mem_pci(a)		(a)

#define IO_READ(r)		( *((volatile unsigned int *)(r)) )
#define IO_WRITE(r, v)		( (*((volatile unsigned *) (r))) = ((unsigned int)(v)) )

/*
 * Generic virtual read/write
 */
//#define __arch_getw(a)		(*(volatile unsigned short *)(a))
//#define __arch_putw(v,a)	(*(volatile unsigned short *)(a) = (v))

/*
 * Validate the pci memory address for ioremap.
 */
//#define iomem_valid_addr(iomem,size)	(1)

/*
 * Convert PCI memory space to a CPU physical address
 */
//#define iomem_to_phys(iomem)	(iomem)

#endif
