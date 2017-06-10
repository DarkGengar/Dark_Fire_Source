.align 2
.global map_event_1_0

map_event_1_0:
	
	event_cnt:
		.byte 0
		.byte 2
		.byte 0
		.byte 0	
		
		.word 0
		.word warp
		.word 0
		.word 0
		
	person:
	
		
	warp:
	
		warp_000:
			.hword 0x18
			.hword 0x42
			.byte 0
			.byte 1
			.byte 0
			.byte 0
			
		warp_001:
			.hword 0x19
			.hword 0x42
			.byte 0
			.byte 2
			.byte 0
			.byte 0
			
	script_field:
	
		
	signpost:
