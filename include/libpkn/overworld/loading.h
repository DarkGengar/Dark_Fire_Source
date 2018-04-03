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
 * @file     loading.h
 * @date     03.04.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"

#ifndef LOADING_H
#define LOADING_H

#ifdef __cplusplus
extern "C" {
#endif

    
/**
 * Main overworld callback (callback 1). Requires c2_overworld as callback 2.
 */
extern void c1_overworld(void);    

/**
 * Secondary overworld callback (callback 2), return to overworld and continue scripts+music.
 */
extern void c2_exit_to_overworld_2_switch(void);

/**
 * Secondary overworld callback (callback 2), return to overworld and continue scripts+music.
 */
extern void c2_return_overworld_music_scripts_cont(void);


#ifdef __cplusplus
}
#endif

#endif /* LOADING_H */


/* -- EOF -- */