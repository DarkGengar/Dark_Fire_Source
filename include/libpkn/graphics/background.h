/*******************************************************************                                                                 *
 * Copyright (C) 2015-2017 by DarkGengar                           *
 * This file is part of Pokémon Dark Fire                          *
 *                                                                 *
 * Pokémon Dark Fire is free software.                             *
 * You can redistribute or modify it under the terms               *
 * of the GNU Lesser General Public License as published           *
 * by the Free Software Foundation, either                         *
 * version 3 of the License, or (at your option) any               *
 * later version provided you include a copy of the                *
 * licence and this header.                                        *
 * See GNU GENERAL PUBLIC LICENSE for more details.                *
 *                                                                 *
 * Pokémon Dark Fire is redistributed to help you with             *
 * your next projects, but WITHOUT ANY WARRANTY;                   *
 * without even the implied warranty of                            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            *
 *                                                                 *
 * You should have received a copy of                              *
 * the GNU GENERAL PUBLIC LICENSE along with Pokémon Dark Fire.    *
 * If you not have a copy of the                                   *
 * GNU GENERAL PUBLIC LICENSE see: http://www.gnu.org/licenses     *
 *                                                                 *
 ******************************************************************/
/**
 * @file     background.h
 * @date     24.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

#ifdef __cplusplus
extern "C" {
#endif

struct BgConfig {
    u16 bgid : 2;
    u16 character_base : 2;
    u16 map_base : 5;
    u16 size : 2;
    u16 palette : 1;
    u16 priority : 2;
    u16 b_padding : 2; // bit field padding
    u16 padding;
};

extern void gpu_tile_bg_drop_all_sets(u8);
extern void bg_vram_setup(u8 mode, const struct BgConfig* config, u8 layers);
extern void gpu_sprites_upload(void);
extern void copy_queue_process(void);
extern void bgid_set_tilemap(u8 layer, u8* space);
extern void bgid_mod_x_offset(u8 bgid, s32 delta, u8 dir);
extern void bgid_mod_y_offset(u8 bgid, s32 delta, u8 dir);
extern void* bgid_get_tilemap(u8 layer);
extern void bgid_mark_for_sync(u8 bgid);
extern void bg_display_sync();
extern void bg_sync_display_and_show(u8 bgid);
extern void gpu_copy_to_vram_by_bgid(u8 bgid, void*source, u16 size, u16 starttile, u8 mode);
extern void overworld_free_bgmaps();
extern void tilemaps_sync(void);

#ifdef __cplusplus
}
#endif

#endif /* BACKGROUND_H */


/* -- EOF -- */