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

#include "core/task.h"
#include "core/callback.h"
#include "core/audio.h"

#include "overworld/loading.h"

/* -- Methods -- */

/**
 * @brief    brief description
 * @param    param description
 * @return   return description 
 * @details  More Details
 */
void oak_intro_scene_loop(void) {
    switch(super.multi_purpose_state_tracker){
	case 0:
	    //play_song(0x124);
	    super.multi_purpose_state_tracker++;
	    break;
	case 1:
	    dprintf("Hello World from Intro\n");
	    set_callback1(c1_overworld);
	    set_callback2(0x08056665);
	    break;
    }
}

void oak_intro_scene_cb_handler(void) {
    
}

void oak_intro_test(void) {
    dprintf("Hello\n");
    audio_play(SONG_ROUTE_THEME_2);
}

/* -- EOF -- */