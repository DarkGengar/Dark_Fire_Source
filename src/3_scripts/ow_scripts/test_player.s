.include "ow_script_language.s"

.global test_player

test_player:
    lock
    setflag 0x828
    setflag 0x829
    setflag 0x822

    givepokemon 1 1 0 0 0 0
    msgbox string_test_player MSG_YESNO
    compare LASTRESULT TRUE
    if TRUE nickname
    goto scr_end
	
nickname:
    setvar 0x8004 0
    call name_screen
    goto scr_end

name_screen:
    fadescreen 1
    special 0x9E
    waitstate
    return

scr_end:
    release
    end
