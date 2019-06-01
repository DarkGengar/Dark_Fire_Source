.include "ow_script_language.s"

.global test_player2

test_player2:
    callasm load_mug + 1
    msgbox string_test_player MSG_NORMAL
    callasm delete_mug + 1
    closeonkeypress
    end
	