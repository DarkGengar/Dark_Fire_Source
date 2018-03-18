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

extern void* malloc(size_t size);
extern void free(void* address);
extern void* memcpy(void * destination, const void* source, size_t num);
extern void* memset(void* dst, int value, size_t size);

#ifdef __cplusplus	
}
#endif


#endif // MEMORY_H