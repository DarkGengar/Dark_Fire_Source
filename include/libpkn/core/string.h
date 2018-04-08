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
 * @file     string.h
 * @date     25.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"

#ifndef STRING_H
#define STRING_H

#ifdef __cplusplus
extern "C" {
#endif

struct Textbox {
    u8 bg_id;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 pal_id;
    u16 charbase;
    u8* pixels;
};
    
extern struct Textbox rboxes[32];    
    
extern void rboxes_free(void);

/**
 * Free a textbox.
 */
extern u8 rboxid_free(u8 id);

/**
 * Clear a textbox.
 */
extern void rboxid_clear_pixels(u8 id, u8 offset);

#ifdef __cplusplus
}
#endif

#endif /* STRING_H */


/* -- EOF -- */