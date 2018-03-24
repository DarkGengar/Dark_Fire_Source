/******************************************************************
*                                                                 *
* Copyright (C) 2015-2017 by DarkGengar                           *
* This file is part of Pokémon Dark Fire			  *
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
* {Project} is redistributed to help you with                     *
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
 * @file     mugshot.c
 * @date     24.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More details about file.
 */

/* -- Includes -- */

#include "types.h"
#include "rom_functions.h"
#include "agb_debug.h"
#include "assets/gfx_tb_s_135.h"
#include "oams.h"
#include "pokemon.h"

/* pokemon.h */

#define TAG_TEST    0xEAAE
#define LASTRESULT  0x800D

extern void *tileset_header;

/* -- Methods -- */

/**
*  \brief    Main Function
*  
*  \return   Return Nothing
*  
*  \details  nothing.
*/
void load_mug(void)
{
    // print tileset header
    dprintf("Tileset Header: 0x0%x\n", &tileset_header);

    // Oam Data
    const struct OamData test_oam = {
        .shape = 0,
        .size = 3
    };
    
    // Sprite
    struct SpriteTiles testTiles = {&gfx_tb_s_135Tiles, 2048, TAG_TEST};
    struct SpritePalette testPal = {&gfx_tb_s_135Pal, TAG_TEST};
    
    // Oam Template
    const struct Template test_template = {
        .tiles_tag = TAG_TEST,
        .pal_tag = TAG_TEST,
        .oam = &test_oam,
        .animation = &anim_image_empty,
        .graphics = &testTiles,
        .rotscale = &rotscale_empty,
        .callback = oac_nullsub
    };

    // ´load pal and tiles in VRAM
    gpu_tile_obj_decompress_alloc_tag_and_upload(&testTiles);
    gpu_pal_decompress_alloc_tag_and_upload(&testPal);
    // get id of created obj
    u8 id = template_instanciate_forward_search(&test_template, 10, 10, 0);

    // set position of obj
    objects[id].pos1.x = 47;
    objects[id].pos1.y = 83;
    
    var_set(LASTRESULT, id);
    dprintf("LASTRESULT variable: %d\n", var_load(LASTRESULT));
    dprintf("OAM ID: %d\n", id);
}

/**
*  \brief    Main Function
*  
*  \return   Return Nothing
*  
*  \details  nothing.
*/
void delete_mug(void)
{
    u8 id = var_load(LASTRESULT);
    obj_delete_and_free_tiles(&objects[id]);
}


/* -- EOF -- */