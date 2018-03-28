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

#include "graphics/palette.h"
#include "graphics/oams.h"
#include "graphics/background.h"

#include "core/memory.h"
#include "core/callback.h"
#include "core/bios.h"
#include "core/string.h"
#include "core/io.h"
#include "core/task.h"

#include "overworld/ow_ui.h"

#define LASTRESULT 0x800D
#define bootscreenTilesLen 468
extern const unsigned int bootscreenTiles[117];

#define bootscreenMapLen 328
extern const unsigned short bootscreenMap[164];

#define bootscreenPalLen 512
extern const unsigned short bootscreenPal[256];

extern u16 *lastresult;
extern void scr_cmd_table;

void setup();
void load_gfx();
void cb_handler();

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
bool capsule_machine(void)
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
    
    if(pal_fade_control.active)
	return FALSE;
    
    setup();
    load_gfx();
    
    palette_bg_faded_fill_black();
    fade_screen(0xFFFFFFFF, 1, 16, 0, 0x0000);
    
    set_callback2(cb_handler);
    dprintf("END OF SCENE LOAD\n");
    return TRUE;
}

void setup() 
{
    tasks_init();
    vblank_handler_set(NULL);
    obj_and_aux_reset_all();
    pal_fade_control_and_dead_struct_reset();
    gpu_pal_allocator_reset();
    gpu_tile_obj_tags_reset();
    dma0_cb_reset();
    //memset((void *)(ADDR_VRAM), 0x0, 0x10000);
    gpu_tile_bg_drop_all_sets(1);
    rboxes_free();
    rain_sound_fadeout();
    fadeout_song(1);
    //help_system_disable__sp198();
    bg_vram_setup(0, test_config, 1);
    
    bg_sync_display_and_show(0);
    bg_display_sync();
    bgid_mod_x_offset(0, 0, 0);
    bgid_mod_y_offset(0, 0, 0);
    //lcd_io_set(0x10, 0);
    //lcd_io_set(0x12, 0);
    
    vblank_handler_set(vblank);
    interrupts_enable(INTERRUPT_VBLANK);
    
    void *bg0map = malloc(0x800);
    bgid_set_tilemap(0, bg0map);
}

void load_gfx() 
{
    lz77_uncomp_vram(bootscreenTiles, (void*) 0x06000000);
    lz77_uncomp_wram(bootscreenMap, bgid_get_tilemap(0));
    gpu_copy_to_vram_by_bgid(0, bgid_get_tilemap(0), 0x800, 0, 2);
    
    gpu_pal_apply(bootscreenPal, 0, 32);
}

void cb_handler()
{
    if (pal_fade_control.active)
        process_palfade();
    else {
	task_exec();
        objc_exec();
        obj_sync_superstate();
    }
}

// EOF
