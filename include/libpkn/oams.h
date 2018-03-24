#include "types.h"

#ifndef OAMS_H
#define OAMS_H

#ifdef __cplusplus
extern "C" 
{
#endif

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
extern void obj_delete_and_free_tiles(struct Object* obj);

#ifdef __cplusplus
}
#endif

#endif /* OAMS_H */