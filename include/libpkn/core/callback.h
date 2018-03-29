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
 * @file     callback.h
 * @date     24.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"
#include "graphics/oams.h"

#ifndef CALLBACK_H
#define CALLBACK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*SuperCallback)(void);


/**
 * Bits for the keypad;
 */
enum Keypad {
    KEY_A = (1 << 0),
    KEY_B = (1 << 1),
    KEY_SELECT = (1 << 2),
    KEY_START = (1 << 3),
    KEY_RIGHT = (1 << 4),
    KEY_LEFT = (1 << 5),
    KEY_UP = (1 << 6),
    KEY_DOWN = (1 << 7),
    KEY_L = (1 << 8),
    KEY_R = (1 << 9),

    /** Directional pad mask */
    KEY_DPAD = (KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT),
};

/**
 * Check the if the all the given keys are pressed
 */
#define KEYS_ALL_PRESSED(x, keys) (((x) & (keys)) == (keys))

struct Superstate {
    SuperCallback callback1;
    SuperCallback callback2;
    SuperCallback callback2_backup;
    SuperCallback vblank_handler;
    SuperCallback hblank_handler;
    SuperCallback field_14;
    SuperCallback serial_callback;

    u32 bits_to_wait_for;
    u16* vblank_counter;
    u32 field_24;

    u16 buttons_held;
    u16 buttons_new;
    u16 buttons_held_remapped;
    u16 buttons_new_remapped;
    u16 buttons_new_and_repeated;
    u16 buttons_countdown;

    u32 unused_apparently;
    struct OamData sprites[128];
    u8 multi_purpose_state_tracker;
    u8 gpu_sprites_upload_skip;
};


/**
 * Set a secondary per-frame callback.
 *
 */
extern void set_callback2(SuperCallback func);

extern void vblank_handler_set(SuperCallback func);

/**
 * Global game state.
 *
 */
extern struct Superstate super;

#ifdef __cplusplus
}
#endif

#endif /* CALLBACK_H */


/* -- EOF -- */