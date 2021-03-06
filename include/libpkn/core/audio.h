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
 * @file     audio.h
 * @date     06.04.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"

#ifndef AUDIO_H
#define AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

enum Sound  {
    SOUND_RS_BERRY_PICKING_MAYBE = 0x1,
    SOUND_PC_GO_BACK = 0x3,
    SOUND_PC_OPEN = 0x4,
    SOUND_GENERIC_CLINK = 0x5,
    SOUND_WALLRUN = 0x7,
    SOUND_DOOR_OPEN_MAYBE = 0x8,
    SOUND_BIKE_CLINK = 0xB,
    SOUND_NOT_VERY_EFFECTIVE = 0xC,
    SOUND_NORMAL_DAMAGE = 0xD,
    SOUND_SUPER_EFFECTIVE = 0xE,
    SOUND_POKEMON_ENTER_LEAVE = 0xF,
    SOUND_GOT_AWAY_SAFELY = 0x11,
    SOUND_TELEPHONE_MAYBE = 0x12,
    SOUND_FLY_MAYBE = 0x14,
    SOUND_EXCLAMATION_MARK = 0x15,
    SOUND_RS_CONTEST_NOT_YOU = 0x16,
    SOUND_RS_CONTEST_1 = 0x18,
    SOUND_RS_CONTEST_2 = 0x19,
    SOUND_RS_CONTEST_3 = 0x1A,
    SOUND_EXP_GAIN = 0x1B,
    SOUND_RSE_BERRY_MIX_CLICK = 0x22,
    SOUND_FALL_THROUGH_ICE = 0x23,
    SOUND_DAMAGE_ICE_FLOOR = 0x24,
    SOUND_RSE_ROULETTE_BALL_FALL = 0x25,
    SOUND_RSE_ROULETTE_BALL_LAND = 0x26,
    SOUND_SOME_BEEP = 0x28,
    SOUND_GAME_SAVED = 0x30,
    SOUND_OVERWORLD_POISON = 0x48,
    SOUND_COUNTINOUS_RAINING_1 = 0x4A,
    SOUND_RAIN_END = 0x4B,
    SOUND_COUNTINOUS_RAINING_2 = 0x4C,
    SOUND_LEVEL_UP = 0x58,
    SOUND_SUNLIGHT = 0xC3,
    SOUND_BOULDER_BUMP = 0xCF,
    SOUND_YAWN_MAYBE = 0xDC,
    SOUND_RUN_THE_TERMINATOR = 0xE3,
    SOUND_SOME_AIR_MOVE_1 = 0xE4,
    SOUND_SWEET_SCENT = 0xE5,
    SOUND_YAWN_PROBABLY = 0xE6,
    SOUND_SOME_AIR_MOVE_2 = 0xE7,
    SOUND_STAT_INCREASE = 0xE8,
    SOUND_SOME_FIRE_MOVE = 0xE9,
    SOUND_HEAVENLY = 0xEC,
    SOUND_WOAH = 0xED,
    SOUND_STAT_DECREASE = 0xEE,
    SOUND_WHAT = 0xEF,
    SOUND_DOOR_OPEN_MAYBE_2 = 0xF1,
    SOUND_HMM = 0xF2,
    SOUND_TRAINER_CARD = 0xF4,
    SOUND_OPEN_START_MENU_MAYBE = 0xF5,
    SOUND_SCRATCHING = 0xF7,
    SOUND_THE_STORE_IS_OPEN = 0xF8,
    SOUND_SOMEONE_ORDER_A_SHIP = 0xF9,
    SOUND_OPENING_HELP_MENU = 0xFA,
    SOUND_CLOSING_HELP_MENU = 0xFB,
    SOUND_CANT_OPEN_HELP_MENU = 0xFC,
    SOUND_TRIANGLE_QUIZ = 0xFD,
    SOUND_HEALING = 0xFE,
    SONG_HEALING_RS = 0x105,
    SONG_LEVEL_UP = 0x106,
    SONG_EVOLUTION_START = 0x107,
    SONG_EVOLUTION_SAFARI = 0x108,
    SONG_BATTLE_1 = 0x109,
    SONG_BATTLE_2 = 0x10A,
    SONG_UNKNOWN_10B = 0x10B,
    SONG_FANFARE_1 = 0x10C,
    SONG_FANFARE_2 = 0x10D,
    SONG_YOU_FAIL_IT = 0x10E,
    SONG_YOU_FAIL_IT_AGAIN = 0x10F,
    SONG_FOLLOW_ME = 0x110,
    SONG_GAME_CORNER = 0x111,
    SONG_EVIL_LURKS = 0x112,
    SONG_GYM = 0x113,
    SONG_JIGGLYPUFFS_SONG = 0x114,
    SONG_INTRODUCTION = 0x115,
    SONG_POKEMON_THEME = 0x116,
    SONG_CINNABAR_ISLAND = 0x117,
    SONG_LAVENDER_TOWN = 0x118,
    SONG_HEALING = 0x119,
    SONG_BICYCLE = 0x11A,
    SONG_ENCOUNTER_1 = 0x11B,
    SONG_ENCOUNTER_2 = 0x11C,
    SONG_ENCOUNTER_3 = 0x11D,
    SONG_YOURE_IN_THE_HALL_OF_FAME = 0x11E,
    SONG_VIRIDIAN_FOREST = 0x11F,
    SONG_MOUNT_MOON = 0x120,
    SONG_ABANDONED_PLACE = 0x121,
    SONG_END_CREDITS = 0x122,
    SONG_ROUTE_THEME_1 = 0x123,
    SONG_ROUTE_THEME_2 = 0x124,
    SONG_ROUTE_THEME_3 = 0x125,
    SONG_ROUTE_THEME_4 = 0x126,
    SONG_INDIGO_PLATEAU = 0x127,
    SONG_BATTLE_3 = 0x128,
    SONG_BATTLE_4 = 0x129,
    SONG_BATTLE_5 = 0x12A,
    SONG_BATTLE_6 = 0x12B,
    SONG_PALLET_TOWN = 0x12C,
    SONG_OAKS_LAB = 0x12D,
    SONG_OAKS_THEME = 0x12E,
    SONG_POKEMON_CENTER = 0x12F,
    SONG_SS_ANNE = 0x130,
    SONG_SURFS_UP = 0x131,
    SONG_POKEMON_TOWER = 0x132,
    SONG_SILPH_CO = 0x133,
    SONG_CERULEAN_CITY = 0x134,
    SONG_CELADON_CITY = 0x135,
    SONG_VICTORY_1 = 0x136,
    SONG_VICTORY_2 = 0x137,
    SONG_VICTORY_3 = 0x138,
    SONG_VERMILLON_CITY = 0x139,
    SONG_VIRIDIAN_CITY_AND_PEWTER_CITY = 0x13A,
    SONG_GARYS_THEME = 0x13B,
    SONG_GARYS_THEME_BIS = 0x13C,
    SONG_FANFARE_3 = 0x13D,
    SONG_FANFARE_4 = 0x13E,
    SONG_YOU_CAUGHT_A_POKEMON = 0x13F,
    SONG_TRAINER_CARD_PHOTO = 0x140,
    SONG_GAME_FREAK = 0x141,
    SONG_VICTORY_2_BIS = 0x142,
    SONG_INTRO_MESSAGE_1 = 0x143,
    SONG_INTRO_MESSAGE_2 = 0x144,
    SONG_INTRO_MESSAGE_3 = 0x145,
    SONG_GAME_CORNER_1 = 0x146,
    SONG_GAME_CORNER_2 = 0x147,
    SONG_NET_CORNER = 0x148,
    SONG_MYSTERY_CONNECTION = 0x149,
    SONG_GAME_CORNER_3 = 0x14A,
    SONG_MOUNT_EMBER = 0x14B,
    SONG_FOLLOW_ME_ALT = 0x14C,
    SONG_WATER_LABYRINTH = 0x14D,
    SONG_TANOBY_RUINS = 0x14E,
    SONG_ISLANDS_1_2_3 = 0x14F,
    SONG_ISLANDS_4_5 = 0x150,
    SONG_ISLANDS_6_7 = 0x151,
    SONG_POKE_FLUTE = 0x152,
    SONG_BATTLE_DEOXYS = 0x153,
    SONG_BATTLE_5_1 = 0x154,
    SONG_BATTLE_5_2 = 0x155,
    SONG_ENCOUNTER_4 = 0x156,
    SONG_DEOXYS_ENCOUNTER = 0x157,
    SONG_TRAINER_TOWER = 0x158,
    SONG_PALLET_TOWN_REMIX = 0x159,
    SONG_TEACHY_TV = 0x15A,
};
    
/**
 * Play a sound effect.
 */
extern void audio_play(enum Sound sound);


#ifdef __cplusplus
}
#endif

#endif /* AUDIO_H */


/* -- EOF -- */