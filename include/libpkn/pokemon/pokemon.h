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

#define POKEMON_PARTY_SIZE 6

typedef struct Pokemon {
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
};

extern void pokemon_full_clean_slot(struct Pokemon* dst);

extern struct Pokemon players_party[POKEMON_PARTY_SIZE];

#endif //POKEMON_H
