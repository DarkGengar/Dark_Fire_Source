/*******************************************************************
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
 * @file     pokekey.c
 * @date     02.04.2018
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

#include "overworld/loading.h"
#include "overworld/ow_ui.h"

// assets
#include "gfx/gba/gba.h"
#include "gfx/pokekey/pokekey.h"


/* -- Structures -- */
const struct BgConfig sm_pkey_scene_bg_config[1] = {
    { .priority = 0, .palette = 0, .map_base = 31, .bgid = 0 }
};

/* -- Prototypes -- */
boolean sm_pkey_scene_start(void);
void sm_pkey_scene_load(void);
void sm_pkey_scene_reset(void);
void sm_pkey_scene_loop(u8 tsk_id);
void sm_pkey_scene_setup(void);
void sm_pkey_scene_load_gfx(void);
void sm_pkey_scene_vblank(void);
void sm_pkey_scene_cb_handler(void);

/* -- Methods -- */

/**
 * @brief    brief description
 * @param    param description
 * @return   return description 
 * @details  More Details
 */
boolean sm_pkey_scene_start(void) {
    if(pal_fade_control.active)
	return FALSE;
    fadeout_song(1);
    rain_sound_fadeout();
    overworld_free_bgmaps();
    set_callback2(sm_pkey_scene_load);
    return TRUE;
}

void sm_pkey_scene_load(void) {
    super.multi_purpose_state_tracker = 0;
    sm_pkey_scene_reset();
    task_add((TaskCallback)sm_pkey_scene_loop, 0);
    set_callback2(sm_pkey_scene_cb_handler);
}

void sm_pkey_scene_reset(void) {
    tasks_init();
    obj_and_aux_reset_all();
    pal_fade_control_and_dead_struct_reset();
    gpu_pal_allocator_reset();
    gpu_tile_obj_tags_reset();
    dma0_cb_reset();
}

void sm_pkey_scene_loop(u8 tsk_id) {
    dprintf("Task ID: %d", tsk_id);
    switch(super.multi_purpose_state_tracker) {
	case 0:
	    vblank_handler_set(NULL);
	    super.multi_purpose_state_tracker++;
	    break;
	case 1:
	    sm_pkey_scene_setup();
	    super.multi_purpose_state_tracker++;
	    break;
	case 2:
	    // Load resources
	    sm_pkey_scene_load_gfx();
	    play_song(289);
	    super.multi_purpose_state_tracker++;
	    break;
	case 3:
	    fadein_screen(0, CLR_BLACK);
	    super.multi_purpose_state_tracker++;
	    break;
	case 4:
	    if(!pal_fade_control.active)
		super.multi_purpose_state_tracker++;
	    break;
	case 5:
	    // Key input handling
	    if (super.buttons_new & KEY_B) {
		init_fadeout_screen(0);
		super.multi_purpose_state_tracker = 10;
	    }
	    break;
	case 10:
	    if(!pal_fade_control.active) {
		task_del(tsk_id);
		set_callback2(c2_overworld_switch_start_menu);
		set_callback1(c1_overworld);
	    }
	default:
	    break;
    }
}

void sm_pkey_scene_setup(void) {
    //memset((void *)(ADDR_VRAM), 0x0, 0x10000);
    gpu_tile_bg_drop_all_sets(1);
    //help_system_disable__sp198();
    bg_vram_setup(0, sm_pkey_scene_bg_config, 1);
    
    gpu_sync_bg_show(0);
    bg_display_sync();
    bgid_mod_x_offset(0, 0, 0);
    bgid_mod_y_offset(0, 0, 0);
    
    vblank_handler_set(sm_pkey_scene_vblank);
    interrupts_enable(INTERRUPT_VBLANK);
    
    void *bg0map = malloc(0x800);
    bgid_set_tilemap(0, bg0map);
}

void sm_pkey_scene_vblank(void) {
    gpu_sprites_upload();
    copy_queue_process();
    gpu_pal_upload();
}

void sm_pkey_scene_load_gfx(void) {
    lz77_uncomp_vram(pokekeyTiles, (void*) 0x06000000);
    lz77_uncomp_wram(pokekeyMap, bgid_get_tilemap(0));
    gpu_copy_to_vram_by_bgid(0, bgid_get_tilemap(0), 0x800, 0, 2);
    
    gpu_pal_apply(pokekeyPal, 0, 32);
}

void sm_pkey_scene_cb_handler(void) {
    if (pal_fade_control.active)
	process_palfade();
    else{
	task_exec();
	objc_exec();
	obj_sync_superstate();
    }
}

/* -- EOF -- */