.gba
.thumb
.open "base/BPRD_0.gba", "game_build/dark_fire.gba", 0x08000000

.include "patches/patches.asm"

.org 0x08718C40
.importobj "output/linked.o"
.close
