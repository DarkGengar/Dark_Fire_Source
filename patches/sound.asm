// ===========================================================================
// Main Mixer
// ===========================================================================

// pointer to main sound area
.org 0x080007C4
    .word 0x0203E000
.org 0x081E1358
    .word 0x0203E000

.org 0x081E134C
    .word main_mixer    // new mixer ROM location
    .word 0x03005E40    // new mixer RAM location (used for loading)
    .halfword mixer_size
    .halfword 0x400     // CpuSet, copy code by 32 bit units
    .word  0x0203E000   // new PCM work area

.org 0x081E032C
    .word 0x03005E40+1 // new mixer RAM location (used for branch)

.org 0x081E1360
    // set correct sound driver operation mode
    // 12 channels at 13379 Hz samplerate
    .byte  0x00, 0xCC, 0x94, 0x00


    