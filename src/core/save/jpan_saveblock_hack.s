// Free RAM : 0x0203C000 - 0x0203CEC4

.align 2
.thumb
.global load_hijack
.global store_hijack

/*0x080DA100 (save_routine): Branch zu dieser Routine in r0*/
load_hijack:	ldr r1, [r4]
		mov r3, #0xff 
		lsl r3, r3, #0x4
		add r3, r3, r1
		ldrh r0, [r3, #0x4]
		cmp r0, #0x0
		beq first_cc_load
		cmp r0, #0x4
		beq middle_load
		cmp r0, #0xd
		beq last_load
load_ender:	cmp r5, #0xd
		ble next_loop_iter
		
		mov r0, #0x1
		pop {r3}
		mov r8, r3
		pop {r4-r7, pc}		
first_cc_load:	mov r1, #0xcc
		ldr r2, c0c8_addr
		b load_loop	
	
middle_load:	mov r1, #0x96
		lsl r1, r1, #0x2
		ldr r2, c320_addr
		b load_loop
last_load:	mov r1, #0xba
		lsl r1, r1, #0x4
		ldr r2, cec0_addr
				
load_loop:	sub r3, #0x4
		ldr r0, [r3]
		str r0, [r2]
		sub r2, #0x4	
		sub r1, #0x4
		cmp r1, #0x0
		bne load_loop
		b load_ender
.hword 0x0000
/*Die Ramadressen des neuen Save-Breichs.*/
c0c8_addr:	.word 0x0203c0c8
c320_addr:	.word 0x0203c320
cec0_addr:	.word 0x0203cec0
next_loop_iter:	ldr r0, game_load_ret_addr
		bx r0
game_load_ret_addr:	.word 0x080DA095
.word 0xffffffff
/*Die save Routine, hier nehmen wir uns den Teil vor, der ausgeführt wird kurz bevor die
Daten auf den Flash-Speicher geschrieben werden, an 0x080D9B42 setzen wir einen Branch,
nach r7, wir können die zuvorgehende ldr Anweißung benutzen, dazu schreiben wir noch an
0x080D995C einen Pointer zu unserer Routine(+0x61, denn dort liegt store_hijack)*/
store_hijack:	mov r7, #0xff
		lsl r7, r7, #0x4
		add r7, r1, r7
		strh r0, [r7,#0x6]
		ldrh r6, [r7, #0x4]
		cmp r6, #0x0
		beq first_store
		cmp r6, #0x4
		beq middle_store
		cmp r6, #0xd
		beq last_store
.hword 0x0000
store_ender:	ldr r0, game_store_ret_addr
		bx r0
game_store_ret_addr:	.word 0x080D9B47
first_store:	mov r3, #0xcc
		ldr r2, c0c8_addr_2
		b store_loop	
	
middle_store:	mov r3, #0x96
		lsl r3, r3, #0x2
		ldr r2, c320_addr_2
		b store_loop
last_store:	mov r3, #0xba
		lsl r3, r3, #0x4
		ldr r2, cec0_addr_2
store_loop:	sub r7, #0x4
		ldr r0, [r2]
		str r0, [r7]
		sub r2, #0x4
		sub r3, #0x4
		cmp r3, #0x0
		bne store_loop
		b store_ender
/*Die Ramadressen des neuen Save-Breichs.*/
c0c8_addr_2:	.word 0x0203c0c8
c320_addr_2:	.word 0x0203c320
cec0_addr_2:	.word 0x0203cec0


