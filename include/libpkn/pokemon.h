#include "types.h"

#ifndef POKEMON_H
#define POKEMON_H

//languages
#define JAPANESE 0x0201
#define ENGLISH 0x0202
#define FRENCH 0x0203
#define ITALIAN 0x0204
#define GERMAN 0x0205
#define KOREAN 0x0206
#define SPANISH 0x0207

typedef struct
{
	u8 circle 	:	1;
	u8 square	:	1;
	u8 triangle :	1;
	u8 heart 	: 	1;
}marking;

typedef struct
{
	u8 sleep	:	3;
	u8 poison	:	1;
	u8 burn		:	1;
	u8 freeze	:	1;
	u8 para		:	1;	
	u8 bad_pois	:	1;
} status;


typedef struct
{
	u32 personality_value;
	u32 ot_id;
	char nickname[10];
	u16 language;
	char ot_name[7];
	marking markings;
	u16 checksum;
	u16 padding;
	u8 data_encrypted[48];
	status status_condition;
	u8 level;
	u8 pokerus_remaining;
	u16 current_hp;
	u16 total_hp;
	u16 attack;
	u16 defense;
	u16 speed;
	u16 sp_attack;
	u16 sp_defense;	
} pokemon;


pokemon player_party[6];

#endif //POKEMON_H
