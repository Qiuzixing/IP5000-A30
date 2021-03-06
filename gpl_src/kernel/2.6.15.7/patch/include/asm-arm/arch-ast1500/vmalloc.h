/*
 *  linux/include/asm-arm/arch-mvp2000/vmalloc.h
 *
 *  Copyright (C) 2000 Russell King.
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

/*
 * Just any arbitrary offset to the start of the vmalloc VM area: the
 * current 8MB value just means that there will be a 8MB "hole" after the
 * physical memory until the kernel virtual memory starts.  That means that
 * any out-of-bounds memory accesses will hopefully be caught.
 * The vmalloc() routines leaves a hole of 4kB between each vmalloced
 * area for the same reason. ;)
 */
#define VMALLOC_OFFSET	  (8*1024*1024)
#define VMALLOC_START	  (((unsigned long)high_memory + VMALLOC_OFFSET) & ~(VMALLOC_OFFSET-1))
#define VMALLOC_VMADDR(x) ((unsigned long)(x))
/*
 * extend vmalloc() / ioremap() space,
 * 0xE0000000 (PAGE_OFFSET + 0x20000000) => 0xF8000000
 *
 * from Documentation/arm/memory.txt,
 * ~0xfeffffff is free for platform use => VMALLOC_END can be 0xfeffffff
 * choose setting 0xf8000000 (from ast3200), 0xE0000000 (PAGE_OFFSET + 0x20000000) => 0xF8000000
 */
#define VMALLOC_END       0xf8000000

