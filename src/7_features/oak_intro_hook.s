.align 2
.thumb
.global oak_intro_hook

.thumb_func
oak_intro_hook:
    ldr r1, = oak_intro_test + 1
    bx r1

// EOF