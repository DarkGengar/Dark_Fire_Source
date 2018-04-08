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
 * @file     block.h
 * @date     28.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"

#ifndef BLOCK_H
#define BLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

enum Gender {
    GENDER_MALE,
    GENDER_FEMALE,
};

enum OptionsButtonMode {
    OPTIONS_BUTTON_MODE_NORMAL,
    OPTIONS_BUTTON_MODE_LR,
    OPTIONS_BUTTON_MODE_L_EQUALS_A
};

enum OptionsTextSpeed {
    OPTIONS_TEXT_SPEED_SLOW,
    OPTIONS_TEXT_SPEED_MID,
    OPTIONS_TEXT_SPEED_FAST
};

enum OptionsSound {
    OPTIONS_SOUND_MONO,
    OPTIONS_SOUND_STEREO
};

enum OptionsBattleStyle {
    OPTIONS_BATTLE_STYLE_SHIFT,
    OPTIONS_BATTLE_STYLE_SET
};

enum OptionsBattleScene {
    OPTIONS_BATTLE_SCENE_ON,
    OPTIONS_BATTLE_SCENE_OFF,
};
    
/**
 * Trainer and miscellaneous save data.
 */
struct SaveBlock2 {
    u8 name[8];
    enum Gender gender;
    u8 field_9;
    u16 trainerid;
    u16 secretid;
    u16 playtime_hours;
    u8 playtime_minutes;
    u8 playtime_seconds;
    u8 playtime_frames;
    enum OptionsButtonMode options_button_style;
    enum OptionsTextSpeed options_text_speed : 3;
    u8 options_window_frame : 5;
    enum OptionsSound options_sound : 1;
    enum OptionsBattleStyle options_battle_style : 1;
    enum OptionsBattleScene options_battle_scene_off : 1;
    u8 field_15[6];
    u32 unown_pid;
    u32 spinda_pid;
    u32 field_24;
    u8 pokemon_flags_3[52];
    u8 pokemon_flags_4[52];
    u8 field_90[1044];
    u8 fourCharacters[4];
    u8 field_4A8[1008];
    u8 mapdata[1672];
    u32 bag_item_quantity_xor_value;
    u8 field_F24[127];
    u8 last_byte_in_sav2;
};

extern struct SaveBlock2* saveblock2;
    
extern void sav1_secure_increment(u8 id);


#ifdef __cplusplus
}
#endif

#endif /* BLOCK_H */


/* -- EOF -- */