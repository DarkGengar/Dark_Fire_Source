.include "ow_script_language.s"

.global test_player

test_player:
	
	setflag 0x828
	setflag 0x829
	setflag 0x822
	msgbox string_test_player MSG_NORMAL
	givepokemon 1 1 1 0 1 4
	closeonkeypress
	end
	