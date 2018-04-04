.include "ow_script_language.s"

.global test_player3

test_player3:
    checkflag 0x200
    if TRUE msg
    end

msg:
    msgbox string_test_player MSG_NORMAL
    end


