backsprite_table_hero equ 0x082345E4

//gfx
.org backsprite_table_hero + 0*8
		.byte 0x00, 0x08, 0x00, 0x00
		.word gfx_backsprite_heroTiles + 0 * (64 * 64 * 1/2)
		
.org backsprite_table_hero + 1*8
		.byte 0x00, 0x08, 0x00, 0x00
		.word gfx_backsprite_heroTiles + 1 * (64 * 64 * 1/2)

.org backsprite_table_hero + 2*8
		.byte 0x00, 0x08, 0x00, 0x00
		.word gfx_backsprite_heroTiles + 2 * (64 * 64 * 1/2)	
		
.org backsprite_table_hero + 3*8
		.byte 0x00, 0x08, 0x00, 0x00
		.word gfx_backsprite_heroTiles + 3 * (64 * 64 * 1/2)		
		
.org backsprite_table_hero + 4*8
		.byte 0x00, 0x08, 0x00, 0x00
		.word gfx_backsprite_heroTiles + 4 * (64 * 64 * 1/2)		
		
		
.org 0x08239E74
		.word gfx_backsprite_heroTiles
		
//pal
.org 0x08239EA4
		.word gfx_backsprite_heroPal
		