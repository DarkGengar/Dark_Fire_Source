.gba
.thumb
.open "C:\Users\HunterxPokemon\Documents\Github\Original_Dark_Fire_Source\game_build\df_rom.gba",0x08000000

.include "patches/patches.asm"

.org 0x08718C40
.importobj "output/linked.o"
.close
