/******************************************************************
*                                                                 *
* Copyright (C) 2015-2017 by HxP Studio                           *
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
*  \file     template.c
*  \date     30 April 2017
*  \author   HunterxPokemon
*  \brief    template include
*
*  \details  This is a template file.
*/
#include "types.h"
#include "rom_functions.h"
#include "agb_debug.h"
#include "palette.h"
#include "oams.h"
#include "background.h"
#include "memory.h"
#include "core/callback.h"
#include "core/bios.h"
#include "core/string.h"
#include "core/io.h"

#define LASTRESULT 0x800D
#define bootscreenTilesLen 468
extern const unsigned int bootscreenTiles[117];

#define bootscreenMapLen 328
extern const unsigned short bootscreenMap[164];

#define bootscreenPalLen 512
extern const unsigned short bootscreenPal[256];

extern u16 *lastresult;
extern void scr_cmd_table;
extern void fadeout_song(u8 spd);

const struct BgConfig test_config[1] = {
    { .priority = 0, .palette = 0, .map_base = 31, .bgid = 0}
};

void vblank(void)
{
    gpu_sprites_upload();
    copy_queue_process();
    gpu_pal_upload();
}

/**
*  \brief    Main Function
*  
*  \return   Return Nothing
*  
*  \details  nothing.
*/
void capsule_machine(void)
{
    // table of pokemon
    u16 poke_gen1_table[] = {50, 151, 5};
    // pokemon
    u16 poke;
    // random value for table
    u16 rand_value = get_random_change_seed() % 3;
    
    // generate random pokemon from table
    poke = poke_gen1_table[rand_value];
    // get offset of lastresult
    u16* value = var_access(LASTRESULT);
    // set lastresult to pokemon
    *value = poke;
    
    //set_weather(0);
    //update_weather();
    tasks_init();
    vblank_handler_set(NULL);
    obj_and_aux_reset_all();
    pal_fade_control_and_dead_struct_reset();
    gpu_pal_allocator_reset();
    gpu_tile_obj_tags_reset();
    //memset((void *)(ADDR_VRAM), 0x0, 0x10000);
    gpu_tile_bg_drop_all_sets(TRUE);
    //rain_sound_fadeout();
    rboxes_free();
    fadeout_song(1);
    bg_vram_setup(0, test_config, 1);
    
    bg_sync_display_and_show(0);
    bg_display_sync();
    //bgid_mod_x_offset(0, 0, 0);
    //bgid_mod_y_offset(0, 0, 0);
    //lcd_io_set(0x10, 0);
    //lcd_io_set(0x12, 0);
    
    //vblank_handler_set(vblank);
    void *bg0map = malloc(0x800);
    
    bgid_set_tilemap(0, bg0map);
    
    lz77_uncomp_vram(bootscreenTiles, (void*) 0x06000000);
    lz77_uncomp_wram(bootscreenMap, bg0map);
    gpu_copy_to_vram_by_bgid(0, bg0map, 0x800, 0, 2);
    
    gpu_pal_apply(bootscreenPal, 0, 32);
    palette_bg_faded_fill_black();
    
    fade_screen(0xFFFFFFFF, 1, 16, 0, 0x0000);
}

// EOF
