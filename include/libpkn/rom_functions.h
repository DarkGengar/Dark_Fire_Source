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
 * File:   rom_functions.h
 * Author: DarkGengar
 *
 * Created on 25. Februar 2017, 15:00
 */

#include "types.h"
 
#ifndef ROM_FUNCTIONS_H
#define ROM_FUNCTIONS_H

#ifdef __cplusplus
extern "C" 
{
#endif

extern void set_weather(u16 weather);
extern void update_weather();
extern u16 get_random_change_seed();
extern u32 _umod(u32 dividen, u32 divisor);
extern void play_song(u16 song_id);
extern u8 get_field_x2_from_trainerdata(u16 trainer_id);
extern boolean checkflag (u16 flag);
extern u8 get_current_weather();
extern void rain_sound_fadeout();
extern void fadeout_song(u8 speed);
extern void init_fadescreen(u8 type, u8 speed);
extern void close_start_menu(void);

extern void show_coins(u16 coins, u8 x, u8 y);
extern u16 get_number_of_coins();

/* variables.h */
// get offset of variable
extern u16* var_access(u16 variable);
extern u16* var_set(u16 variable, u16 value);
extern u16 var_load(u16 variable);

extern u32 __aeabi_uidivmod(u32 dividend, u32 divisor);

/* oam.h*/
extern u8 template_instanciate_forward_search(const struct Template*, u16 x, u16 y, u8 priority);
extern void gpu_tile_obj_decompress_alloc_tag_and_upload(struct SpriteTiles* tile);
extern void gpu_pal_decompress_alloc_tag_and_upload(struct SpritePalette* pal);

/* callback.h */
void dma0_cb_reset();


#ifdef __cplusplus
}
#endif

#endif /* ROM_FUNCTIONS_H */

