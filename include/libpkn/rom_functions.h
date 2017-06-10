/*****************************************************************
 *                                                                *
 * Copyright (C) 2016-2017 by HxP Inc.                            *
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
 * File:   rom_functions.h
 * Author: HunterxPokemon
 *
 * Created on 25. Februar 2017, 15:00
 */

#include <stdbool.h>
#include "gba.h"
 
#ifndef ROM_FUNCTIONS_H
#define ROM_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

u16 get_random_change_seed();
u32 _umod(u32 dividen, u32 divisor);
u8 givepokemon(u16 species, u8 level, u16 item, u8 padding, u8 shiny, u8 nature);
void play_song(u16 song_id);
u8 get_field_x2_from_trainerdata(u16 trainer_id);
bool checkflag (u16 flag);


#ifdef __cplusplus
}
#endif

#endif /* ROM_FUNCTIONS_H */

