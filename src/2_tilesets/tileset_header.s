.align 2
.global tileset_header

tileset_header:
	ow_set:
	
	tileset_0:
		.byte 1
		.byte 0
		.byte 0
		.byte 0
		.word tileset_0Tiles
		.word tileset_0Pal
		.word tileset_0_block_daten
		.word 0
		.word tileset_0_aufgaben_daten
		
	tileset_1:
		.byte 1
		.byte 1
		.byte 0
		.byte 0
		.word tileset_1Tiles
		.word tileset_1Pal
		.word tileset_1_block_daten
		.word 0
		.word tileset_1_aufgaben_daten
		
	tileset_2:
		.byte 1
		.byte 1
		.byte 0
		.byte 0
		.word tileset_2Tiles
		.word tileset_2Pal
		.word tileset_2_block_daten
		.word 0
		.word tileset_2_aufgaben_daten
	
	
	indoor_set:
	
	tileset_3:
		.byte 1
		.byte 0
		.byte 0
		.byte 0
		.word 0x082751B8
		.word 0x082775B8
		.word 0x082AD6D8
		.word 0
		.word 0x082AFED8
		
	tileset_4:
		.byte 1
		.byte 1
		.byte 0
		.byte 0
		.word 0x08EA82FC
		.word 0x08EA80FC
		.word 0x082B4D70
		.word 0
		.word 0x082B4EF0
		