/******************************************************************
 *                                                                 *
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
 * @file     demo_scene.c
 * @date     31.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More details about file.
 */

/* -- Includes -- */

// libpkn
#include "types.h"
#include "agb_debug.h"
#include "rom_functions.h"
#include "color.h"

#include "core/callback.h"
#include "core/task.h"
#include "core/bios.h"
#include "core/memory.h"
#include "core/io.h"

#include "graphics/palette.h"
#include "graphics/oams.h"
#include "graphics/background.h"

// assets
#include "gfx/gba/gba.h"

#define fadeout_screen(speed, color) fade_screen(0xFFFFFFFF, speed, 0, 16, color)
#define fadein_screen(speed, color) fade_screen(0xFFFFFFFF, speed, 16, 0, color)
#define init_fadeout_screen(speed) init_fadescreen(1, speed)
#define init_fadein_screen(speed) init_fadescreen(0, speed)

#define PAL_POS_BTN_A 4
#define PAL_POS_BTN_B 13
#define PAL_POS_BTN 5
#define KEY_MAX 10

/* -- Structures -- */
const struct BgConfig demo_scene_bg_config[1] = {
    { .priority = 0, .palette = 0, .map_base = 31, .bgid = 0 }
};

union Color clr_new_btn = { .packed = 0, .components.r = 31 };

union Color clr_held_btn = { .packed = 0, .components.g = 31 };

union Color clr_btn = { 
     .packed = 0, 
     .components.r = 27, 
     .components.g = 27, 
     .components.b = 29
};


/* -- Methods -- */
void demo_scene_init(void);
void demo_scene_load(void);
void demo_scene_reset(void);
void demo_scene_loop();
void demo_scene_setup(void);
void demo_scene_vblank(void);
void demo_scene_load_gfx(void);
void demo_scene_cb_handler(void);

/**
 * @brief    brief description
 * @param    param description
 * @return   return description 
 * @details  More Details
 */
void demo_scene_start(void) {
    fadeout_song(1);
    rain_sound_fadeout();
    init_fadeout_screen(0);
    set_callback2(demo_scene_init);
}

void demo_scene_init(void) {
    if(!pal_fade_control.active)
	set_callback2(demo_scene_load);
    else
	process_palfade();
}

void demo_scene_load(void) {
    super.multi_purpose_state_tracker = 0;
    demo_scene_reset();
    task_add((TaskCallback)demo_scene_loop, 0);
    set_callback2(demo_scene_cb_handler);
}

void demo_scene_reset(void) {
    tasks_init();
    obj_and_aux_reset_all();
    pal_fade_control_and_dead_struct_reset();
    gpu_pal_allocator_reset();
    gpu_tile_obj_tags_reset();
    dma0_cb_reset();
}

void demo_scene_loop() {
    u32 btn = 0;
    switch(super.multi_purpose_state_tracker) {
	case 0:
	    vblank_handler_set(NULL);
	    super.multi_purpose_state_tracker++;
	    break;
	case 1:
	    demo_scene_setup();
	    super.multi_purpose_state_tracker++;
	    break;
	case 2:
	    demo_scene_load_gfx();
	    super.multi_purpose_state_tracker++;
	    break;
	case 3:
	    for(u32 i = 0; i < KEY_MAX; i++){
		btn = (u32)(1<<i);
		if(super.buttons_new & btn)
		    gpu_pal_apply(&clr_new_btn, (u16)(PAL_POS_BTN+i), 2);
		else if(super.buttons_held & btn)
		    gpu_pal_apply(&clr_held_btn, (u16)(PAL_POS_BTN+i), 2);
		else
		    gpu_pal_apply(&clr_btn, (u16)(PAL_POS_BTN+i), 2);
	    }
	    break;
	default:
	    break;
    }
}

void demo_scene_setup() 
{
    //memset((void *)(ADDR_VRAM), 0x0, 0x10000);
    gpu_tile_bg_drop_all_sets(1);
    //help_system_disable__sp198();
    bg_vram_setup(0, demo_scene_bg_config, 1);
    
    gpu_sync_bg_show(0);
    bg_display_sync();
    bgid_mod_x_offset(0, 0, 0);
    bgid_mod_y_offset(0, 0, 0);
    
    vblank_handler_set(demo_scene_vblank);
    interrupts_enable(INTERRUPT_VBLANK);
    
    void *bg0map = malloc(0x800);
    bgid_set_tilemap(0, bg0map);
}

void demo_scene_vblank(void)
{
    gpu_sprites_upload();
    copy_queue_process();
    gpu_pal_upload();
}

void demo_scene_load_gfx() 
{
    lz77_uncomp_vram(gbaTiles, (void*) 0x06000000);
    lz77_uncomp_wram(gbaMap, bgid_get_tilemap(0));
    gpu_copy_to_vram_by_bgid(0, bgid_get_tilemap(0), 0x800, 0, 2);
    
    gpu_pal_apply(gbaPal, 0, 32);
}

void demo_scene_cb_handler(void) {
    if (pal_fade_control.active)
	process_palfade();
    else{
	task_exec();
	objc_exec();
	obj_sync_superstate();
    }
}

void debug_scene_state(u8 state) {
    dprintf("STATE %d\n", state);
}

/* -- EOF -- */