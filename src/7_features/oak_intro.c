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
 * @file     oak_intro_hack.c
 * @date     05.04.2018
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

#include "core/task.h"
#include "core/callback.h"
#include "core/audio.h"
#include "core/m4a.h"
#include "core/string.h"

#include "graphics/background.h"
#include "graphics/oams.h"
#include "graphics/palette.h"

#include "save/block.h"

#include "overworld/loading.h"

#include "strings/intro/string_intro.h"

#define NAME_PLAYER 0
#define NAME_RIVAL  4

pchar str_test_oak[] = { 0xC2, 0xBF, 0xC6, 0xC6, 0xC9, 0xFB, 0xFF };
u32 *tilemap = (void *) 0x203B108;
u16 *variables = ((u16*)0x020370B8);

extern u8 check_a_pressed(u8 b);

/* -- Prototypes -- */
void scn_oak_intro_loop(u8 tsk_id);
void scn_oak_intro_start_tutorial(u8 tsk_id);
void scn_oak_intro_prepare_player_name_screen(u8 tsk_id);
void scn_oak_intro_show_player_name_screen(u8 tsk_id);
void scn_oak_intro_return_from_player_nmscn(u8 tsk_id);
void scn_oak_intro_confirm_player_name(u8 tsk_id);
void scn_oak_intro_finished(void);
void scn_oak_intro_after_name(u8 tsk_id);
void scn_oak_intro_reset(void);
void scn_oak_intro_setup(void);
void scn_oak_intro_cb_handler(void);
void show_message(pchar *message);

/* -- Methods -- */

/**
 * @brief    brief description
 * @param    param description
 * @return   return description 
 * @details  More Details
 */
void scn_oak_intro_loop(u8 tsk_id) {
    switch(variables[0xC]){
	case 0:
	    fadein_screen(0, CLR_BLACK);
	    tasks[tsk_id].function = (TaskCallback)scn_oak_intro_start_tutorial;
	    //tasks[tsk_id].function = (TaskCallback)0x08130C41;
	    //set_callback2(0x08056665);
	    //pokemon_query_string(0, saveblock2->name, 0, 0, 0, scn_oak_intro_after_name);
	    break;
	case 1:
	    fadein_screen(16, CLR_BLACK);
	    tasks[tsk_id].function = (TaskCallback)scn_oak_intro_return_from_player_nmscn;
	    break;
	default:
	    break;
    }
}

void scn_oak_intro_start_tutorial(u8 tsk_id) {
    show_message(str_dev_greeting);
    tasks[tsk_id].function = scn_oak_intro_prepare_player_name_screen;
}

void scn_oak_intro_prepare_player_name_screen(u8 tsk_id) {
    if(check_a_pressed(0)) 
	return;
    textbox_close();
    fadeout_screen(1, CLR_BLACK);
    tasks[tsk_id].function = scn_oak_intro_show_player_name_screen;
}

void scn_oak_intro_show_player_name_screen(u8 tsk_id) {
    dprintf("Name Screen\n");
    if(pal_fade_control.active) {
	dprintf("Name Screen Fade is active\n");
	variables[0xC] = 1;
	scn_query_string(0, saveblock2->name, 0, 0, 0, scn_oak_intro_after_name);
    }
    ((void (*)(u8, u8)) 0x081311B9)(tsk_id, 1);
}

void scn_oak_intro_return_from_player_nmscn(u8 tsk_id) {
    dprintf("return from player nmscn");
    show_message(str_intr_confirm_name);
    tasks[tsk_id].function = scn_oak_intro_confirm_player_name;
}

void scn_oak_intro_confirm_player_name(u8 tsk_id) {
    if(check_a_pressed(0)) 
	return;
}

void scn_oak_intro_finished(void) {
}

void scn_oak_intro_after_name(u8 tsk_id) {
    switch(super.multi_purpose_state_tracker) {
	case 0:
	    vblank_handler_set(NULL);
	    scn_oak_intro_reset();
	    super.multi_purpose_state_tracker++;
	    break;
	case 1:
	    for(int i = 0; i < 7; i++)
		dprintf("Letter %d: 0x%X\n", i, saveblock2->name[i]);
	    scn_oak_intro_setup();
	    super.multi_purpose_state_tracker++;
	    break;
	case 2:
	    task_add((TaskCallback)scn_oak_intro_loop, 0);
	    super.multi_purpose_state_tracker++;
	    break;
	case 3:
	    set_callback2(scn_oak_intro_cb_handler);
	    break;
	default:
	    break;
	    
    }
}

void scn_oak_intro_reset(void) {
    pal_fade_control_and_dead_struct_reset();
    dma0_cb_reset();
    obj_and_aux_reset_all();
    gpu_pal_allocator_reset();
    nullify_something_called_on_townmap();
}

void scn_oak_intro_setup(void) {
    gpu_tile_bg_drop_all_sets(0);
    bg_vram_setup(1, (struct BgConfig *)0x08463F24, 3);
    
    bgid_set_tilemap(1, *tilemap + 0x1C20);
    bgid_set_tilemap(2, *tilemap + 0x1820);
    
    bgid_mod_x_offset(1, 0, 0);
    bgid_mod_y_offset(1, 0, 0);
    bgid_mod_x_offset(2, 0, 0);
    bgid_mod_y_offset(2, 0, 0);
}

void scn_oak_intro_cb_handler(void) {
    task_exec();
    remoboxes_upload_tilesets();
    objc_exec();
    obj_sync_superstate();
    process_palfade();
}

void show_message(pchar *message) {
    //pchar *dest = (pchar*) 0x02021D18;
    u8 speed = 1; /* 0: instant, 8: slow (default) */

    load_message_box(0, 0);
    fdecoder(string_buffer, message);
    box_related_one(0, 4, string_buffer, speed, 0, 2, 1, 3);

    rboxid_update(0, 3);
}
/* -- EOF -- */