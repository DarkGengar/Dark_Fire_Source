/*****************************************************************
 *                                                                *
 * Copyright (C) 2016-2017 by DarkGengar                          *
 * This file is part of Pokémon Dark Fire                         *
 *                                                                *
 * Pokémon Dark Fire is free software.                            *
 * You can redistribute or modify it under                        *
 * the terms of the GNU GENERAL PUBLIC LICENSE.                   *
 * See GNU GENERAL PUBLIC LICENSE for more details.               *
 *                                                                *
 * This project is redistributed to help you with                 *
 * your next projects, but without any WARRANTY.                  *
 *                                                                *
 * You should have a copy of the GNU GENERAL PUBLIC LICENSE       *
 * along with Pokémon Dark Fire.                                  *
 * If you don't have a copy of the                                *
 * GNU GENERAL PUBLIC LICENSE see: http://www.gnu.org/licenses    *
 *                                                                *
 *****************************************************************/
/* 
 * File:   bios.h
 * Author: HunterxPokemon
 *
 * Created on 25. Februar 2017, 14:56
 */
#include "types.h"
 
#ifndef BIOS_H
#define BIOS_H

#ifdef __cplusplus
extern "C" {
#endif


/*Reset*/
//swi 0x1
extern void register_ram_reset(u32 flags);	

/*Decompression*/
//swi 0x11
extern void lz77_uncomp_wram(const void *src, void *dst);
//swi 0x12
extern void lz77_uncomp_vram(const void *src, void *dst);	

/*Arithmetic*/
//swi 0x6
extern s32 div(s32 num, s32 den);
//swi 0x8
extern u32 sqrt(u32 num);	
//swi 0xA
extern s16 arctan(s16 dydx);			

/*Memory Fills*/
//swi 0xB
extern void cpuset(const void *src, void *dst, u32 mode);
//swi 0xC
extern void cpufastset(const void *src, void *dst, u32 mode);		

/*Rot/scale*/
//swi 0xE
extern void bg_affine_set(const BgAffineSource *src, BgAffineDest *dst, s32 num);
//swi 0xF
extern void obj_affine_set(const ObjAffineSource *src, void *dst, s32 num, s32 offset);		


#ifdef __cplusplus
}
#endif

#endif /* BIOS_H */

