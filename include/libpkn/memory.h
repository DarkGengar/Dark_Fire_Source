/******************************************************************
*                                                                 *
* Copyright (C) 2015-2017 by DarkGengar                           *
* This file is part of {Project}                              	  *
*                                                                 *
* {Project} is free software.                                     *
* You can redistribute or modify it under the terms               *
* of the GNU Lesser General Public License as published           *
* by the Free Software Foundation, either                         *
* version 3 of the License, or (at your option) any               *
* later version provided you include a copy of the                *
* licence and this header.                                        *
* See GNU GENERAL PUBLIC LICENSE for more details.                *
*                                                                 *
* {Project} is redistributed to help you with                     *
* your next projects, but WITHOUT ANY WARRANTY;                   *
* without even the implied warranty of                            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            *
*                                                                 *
* You should have received a copy of                              *
* the GNU GENERAL PUBLIC LICENSE along with {Project}.            *
* If you not have a copy of the                                   *
* GNU GENERAL PUBLIC LICENSE see: http://www.gnu.org/licenses     *
*                                                                 *
******************************************************************/
 
/**
*   \file     memory.h
*   \date     16 march 2018
*   \author   DarkGengar
*   \brief    brief description
*
*   \details  More details about file.
*/

#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

    
#define ADDR_VRAM 0x06000000

/**
 * Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
 *
 */
extern void* malloc(u32 size);

/**
 * Deallocate a block of memory previously allocated with malloc.
 *
 */
extern void free(void* address);

/**
 * Copies size bytes from src to dst.
 *
 */
extern void* memcpy(void* dst, const void* src, u32 size);

/**
 * Set size bytes at dst to value.
 *
 */
extern void* memset(void* dst, u8 value, u32 size);

/**
 * Allocates a block of size bytes of memory and zero fills it.
 *
 */
extern void* malloc_and_clear(u32 size);

#ifdef __cplusplus	
}
#endif


#endif // MEMORY_H