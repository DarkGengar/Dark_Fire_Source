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
#include "types.h"
#include "agb_debug.h"
#include "rom_functions.h"
#include "color.h"

#include "core/callback.h"
#include "core/task.h"

#include "graphics/palette.h"
#include "graphics/oams.h"

#define fadeout_screen(speed, color) fade_screen(0xFFFFFFFF, speed, 0, 16, color)
#define fadein_screen(speed, color) fade_screen(0xFFFFFFFF, speed, 16, 0, color)
#define init_fadeout_screen(speed) init_fadescreen(1, speed)
#define init_fadein_screen(speed) init_fadescreen(0, speed)


/* -- Methods -- */
void demo_scene_init(void);
void demo_scene_load(void);
void demo_scene_reset(void);
void demo_scene_cb_handler(void);

/**
 * @brief    brief description
 * @param    param description
 * @return   return description 
 * @details  More Details
 */
void demo_scene_start(void) {
    dprintf("START\n");
    dprintf("COLOR: %x\n", rgb5(255, 0, 0));
    init_fadeout_screen(0);
    set_callback2(demo_scene_init);
}

void demo_scene_init(void) {
    dprintf("PAL_FADE_CONTROL_STATUS: %d\n", pal_fade_control.active);
    if(!pal_fade_control.active){
	dprintf("NOT ACTIVE\n");
	dprintf("DEMO_SCENE_RESET\n");
	dprintf("SET_CALLBACK2\n");
	//demo_scene_reset();
	//set_callback2(demo_scene_cb_handler);
    }
    else {
	dprintf("ACTIVE\n");
	process_palfade();
    }
    
	
}

void demo_scene_load(void) {
    
}

void demo_scene_reset(void) {
    tasks_init();
    obj_and_aux_reset_all();
    pal_fade_control_and_dead_struct_reset();
    gpu_pal_allocator_reset();
    gpu_tile_obj_tags_reset();
    dma0_cb_reset();
}

void demo_scene_cb_handler(void) {
    objc_exec();
    obj_sync_superstate();
}

/* -- EOF -- */