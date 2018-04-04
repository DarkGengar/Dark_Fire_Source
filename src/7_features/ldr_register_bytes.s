.align 2
.thumb
.global ldr_register_bytes

ldr_register_bytes:
    ldr r0, = 0x08FFFFFF
    bx r0
    ldr r1, = 0x08FFFFFF
    bx r1
    ldr r2, = 0x08FFFFFF
    bx r2
    ldr r3, = 0x08FFFFFF
    bx r3

