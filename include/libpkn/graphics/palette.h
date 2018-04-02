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
 * @file     palette.h
 * @date     24.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"

#ifndef PALETTE_H
#define PALETTE_H

#ifdef __cplusplus
extern "C" {
#endif


    
// this doesn't structured right at. Bit fields broken between bytes
// and game loads it as though it's a byte. Please review
struct FadeControl {
    u16 bg_pal_bitfield;
    u16 obj_pal_bitfield;
    u8 delay_counter:6;
    u16 y:5; // blend coefficient
    u16 target_y:5; // target blend coefficient
    u16 blend_color:15;
    u16 active:1;
    u16 multipurpose:6;
    u16 y_dec:1; // whether blend coefficient is decreasing
    u16 buffer_transfer_disabled:1;
    u16 mode:2;
    u16 should_reset_blend_registers:1;
    u16 hardware_fade_finishing:1;
    u16 software_fade_finishing_counter:5;
    u16 software_fade_finishing:1;
    u16 obj_palette_toggle:1;
    u8 delta_y:4; // rate of change of blend coefficient
};

struct ColorComponents {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 unused : 1;
};

union Color {
    struct ColorComponents components;
    u16 packed;
};

extern struct FadeControl pal_fade_control;
    
extern boolean fade_screen(u32 bitmask, s8 speed, u8 to, u8 from, u16 color);
extern void pal_fade_control_and_dead_struct_reset(void);
extern void gpu_pal_allocator_reset(void);
extern void gpu_pal_upload(void);
extern void gpu_pal_apply(const void* palette, u16 offset, u16 size);
extern void gpu_pal_apply_compressed(void* palette, u16 offset, u16 size);
extern void palette_bg_faded_fill_black(void);
extern void process_palfade(void);

#ifdef __cplusplus
}
#endif

#endif /* PALETTE_H */


/* -- EOF -- */