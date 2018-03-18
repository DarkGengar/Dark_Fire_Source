/******************************************************************
*                                                                 *
* Copyright (C) 2015-2017 by HxP Studio                           *
* This file is part of {Project}                              	  *
*                                                                 *
* {Project} is free software.                                     *
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
* the GNU GENERAL PUBLIC LICENSE along with {Project}.            *
* If you not have a copy of the                                   *
* GNU GENERAL PUBLIC LICENSE see: http://www.gnu.org/licenses     *
*                                                                 *
******************************************************************/
 
/**
*  \file     template.c
*  \date     30 April 2017
*  \author   HunterxPokemon
*  \brief    template include
*
*  \details  This is a template file.
*/

#include "types.h"
#include "rom_functions.h"
#include "agb_debug.h"
#include "assets/gfx_tb_s_135.h"

/* pokemon.h */
typedef struct pokemon {
    u32 pid;
    u32 tid;
    u8 nickname [10];
    u16 language;
    u8 ot_name [7];
    u8 markings;
    u16 checksum;
    u16 padding;
    u16 encrypted_substructure [24];
    u32 status_condition;
    u8 level;
    u8 pokerus_remaining_byte;
    u16 current_hp;
    u16 total_hp;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 sattack;
    u16 sdefense;

} pokemon;

pokemon *players_party = (pokemon*)0x02024284;

/* oam.h */

struct Object;

/**
 * Sprite object callback.
 * @param o The object the callback belongs to
 */
typedef void (*ObjectCallback)(struct Object* o);


/**
 * 8 bit coordinates
 */
struct Coords8 {
    u8 x;
    u8 y;
};

/**
 * 16 bit coordinates;
 */
struct Coords16 {
    s16 x;
    s16 y;
};

/**
 * Tile animation frame
 */
struct Frame {
    u16 data;
    u8 duration : 6;
    u8 hflip : 1;
    u8 vflip : 1;
};

/**
 * Rotation/Scaling frame
 */
struct RotscaleFrame {
    u16 scale_delta_x;
    u16 scale_delta_y;
    u8 rot_delta;
    u8 duration;
    u16 field_6;
};


/**
 * OAM Structure
 */

struct OamData {
    u32 y : 8;

    /**
     * 0=Normal, 1=Affine, 2=Disable, 3=Double Size
     */
    u32 affine_mode : 2;

    /**
     * 0=Normal, 1=Semi-Transparent, 2=OBJ Window, 3=Prohibited
     */
    u32 obj_mode : 2;

    /**
     * Enable mosaic
     */
    u32 mosaic : 1;

    /**
     * 1=256 colours
     */
    u32 bpp : 1;

    /**
     * 0=Square,1=Horizontal,2=Vertical,3=Prohibited
     */
    u32 shape : 2;

    u32 x : 9;
    u32 matrix_num : 3; // bits 3/4 are h-flip/v-flip if not in affine mode
    u32 h_flip : 1;
    u32 v_flip : 1;
    /**
     * Size  Square   Horizontal  Vertical
     * 0     8x8      16x8        8x16
     * 1     16x16    32x8        8x32
     * 2     32x32    32x16       16x32
     * 3     64x64    64x32       32x64
     */
    u32 size : 2;

    u16 tile_num : 10;

    /**
     * 0-3; 0=Highest
     */
    u16 priority : 2;
    u16 palette_num : 4;
    u16 affine_param;
};

/**
 * Tileset Data
 */
struct SpriteTiles {
    const void* data;
    u16 size;
    u16 tag;
};

struct SpritePalette {
    const void* data;
    u16 tag;
};

/**
 * A template for a sprite object
 */
struct Template {
    u16 tiles_tag;
    u16 pal_tag;
    const struct OamData* oam;

    /**
     * Animation table. Each entry is a pointer to an array of frames.
     */
    const struct Frame **animation;
    const struct SpriteTiles* graphics;
    const struct RotscaleFrame **rotscale;
    ObjectCallback callback;
};


/**
 * Sprite object
 */
struct Object {
    struct OamData final_oam;
    struct Frame **animation_table;
    struct SpriteTiles* gfx_table;
    struct RotscaleFrame **rotscale_table;
    struct Template* object_template;
    u32 field18;
    ObjectCallback callback;
    struct Coords16 pos1;
    struct Coords16 pos2;
    struct Coords8 shift;
    u8 anim_number;
    u8 anim_frame;
    u8 anim_delay;
    u8 counter;
    u16 priv[8];
    u8 bitfield2;
    u8 bitfield;
    u16 anim_data_offset;
    u8 field42;

    /**
     * Changes order of sprites in OAM. Allows fine-grained control of
     * hardware sprite priority. A lower value indicates higher
     * priority.  Sprites must have equal priority in OAM for this to
     * have any effect.
     */
    u8 y_height_related;
};

extern void oac_nullsub(struct Object* o);
extern struct Object objects[64];
extern const struct RotscaleFrame *rotscale_empty;
extern const struct Frame *anim_image_empty;

u16 __key_curr=0, __key_prev=0;

#define KEY_A        0x0001
#define KEY_B        0x0002
#define KEY_SELECT   0x0004
#define KEY_START    0x0008
#define KEY_RIGHT    0x0010
#define KEY_LEFT     0x0020
#define KEY_UP       0x0040
#define KEY_DOWN     0x0080
#define KEY_R        0x0100
#define KEY_L        0x0200

#define KEY_MASK     0x03FF
#define MEM_IO		0x04000000
#define REG_BASE	MEM_IO
#define REG_KEYINPUT		*(vu16*)(REG_BASE+0x0130)	// Key status
//0x04000130

#define TAG_TEST    0xEAAE

/**
*  \brief    Main Function
*  
*  \return   Return Nothing
*  
*  \details  nothing.
*/
int test_song(void)
{
    for (int i = 0; i < 10; i++) {
        players_party->nickname[i] = 0;
    }
    players_party->nickname[0] = 0xC4;
    players_party->nickname[1] = 0xDD;
    players_party->nickname[2] = 0xE1;
    players_party->nickname[3] = 0xE1;
    players_party->nickname[4] = 0xED;
    players_party->language = 0x201;

    const struct OamData test_oam = {
        .shape = 0,
        .size = 3
    };
    struct SpriteTiles testTiles = {&gfx_tb_s_135Tiles, 2048, TAG_TEST};
    struct SpritePalette testPal = {&gfx_tb_s_135Pal, TAG_TEST};
    const struct Template test_template = {
        .tiles_tag = TAG_TEST,
        .pal_tag = TAG_TEST,
        .oam = &test_oam,
        .animation = &anim_image_empty,
        .graphics = &testTiles,
        .rotscale = &rotscale_empty,
        .callback = oac_nullsub
    };

    gpu_tile_obj_decompress_alloc_tag_and_upload(&testTiles);
    gpu_pal_decompress_alloc_tag_and_upload(&testPal);
    u8 id = template_instanciate_forward_search(&test_template, 10, 10, 0);

    dprintf("%d", id);

    objects[id].pos1.x = 80;
    objects[id].pos1.y = 80;

    u8 weather = get_current_weather();
    if (weather) {
        dprintf("It is rainy");
    }
    for (int i = 0; i < 30; i++) {
        dprintf("\n%d", get_random_change_seed() % 10);
    }
    return 0;
}


// EOF
