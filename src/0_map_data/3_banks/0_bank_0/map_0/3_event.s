.align 2
.global map_event_0_0

map_event_0_0:
	
	event_cnt:
		.byte 2
		.byte 3
		.byte 0
		.byte 4
		.word person
		.word warp
		.word 0
		.word signpost
		
	person:
	
		person_000:
			.byte 0
			.byte 57
			.byte 0
			.byte 0
			.hword 0x14
			.hword 0x12
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.hword 0
			.word test_player
			.hword 0
			.byte 0
			.byte 0

        person_001:
			.byte 1
			.byte 57
			.byte 0
			.byte 0
			.hword 0x16
			.hword 0x12
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.hword 0
			.word test_player2
			.hword 0
			.byte 0
			.byte 0
	
		
	warp:
	
		warp_000:
			.hword 0x8
			.hword 0xF
			.byte 0
			.byte 0
			.byte 1
			.byte 0
			
		warp_001:
			.hword 0x12
			.hword 0x2
			.byte 0
			.byte 0
			.byte 0
			.byte 1
			
		warp_002:
			.hword 0x13
			.hword 0x2
			.byte 0
			.byte 1
			.byte 0
			.byte 1
		
	script_field:
	
		
	signpost:
	
		sp_000:
			.hword 0xA
			.hword 0x10
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.word schild_player
	
		sp_001:
			.hword 0x18
			.hword 0x16
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.word schild_eremit
			
		sp_002:
			.hword 0x14
			.hword 0x11
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.word schild_zintea
			
		sp_003:
			.hword 0x14
			.hword 0x4
			.byte 0
			.byte 0
			.byte 0
			.byte 0
			.word schild_zeitwald
	