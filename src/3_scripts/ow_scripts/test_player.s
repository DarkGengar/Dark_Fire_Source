.include "ow_script_language.s"

.global test_player

test_player:
    setflag 0x828
    setflag 0x829
    setflag 0x822
    callasm cpm_scene_init + 1
    givepokemon LASTRESULT 50 0 0 0 0
    end
	