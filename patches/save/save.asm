/* -- JPAN saveblock hack -- */

// Load hijack entry
.org 0x080DA100
    ldr r0, = load_hijack|1
    bx r0
    .pool

// Save hijack entry
.org 0x080D9B42
    bx r7

// Save hijack pointer
.org 0x080D9B80
    .word store_hijack|1

.org 0x083FEC98
    .include "patches/save/save_table.asm"

/* -- Extensions -- */

// Flags
.org 0x0806E53A
    ldr r0, = flag_ext_hack|1
    bx r0
    lsl r0, #0
    .pool

// Vars
.org 0x0806E3C0
    ldr r0, = var_ext_hack|1
    bx r0
    .pool
   
// EOF