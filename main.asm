.gba
.thumb
.open "base/BPRD.gba", "bin/Dark_Fire.gba", 0x08000000

.include "patches.asm"

.org 0x08718C40
.importobj "obj/linked.o"
.close
