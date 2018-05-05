.equ MEMBANK_0, 0x0
.equ MSG_FACE, 0x2
.equ MSG_SIGN, 0x3
.equ MSG_NORMAL, 0x4
.equ MSG_YESNO, 0x5
.equ LASTRESULT, 0x800D
.equ VAR_4050, 0x4050
.equ VAR_4051, 0x4051
.equ VAR_4060, 0x4060
.equ VAR_4061, 0x4061
.equ MAPSCRIPT_TYP_2, 0x2
.equ MAPSCRIPT_TYP_4, 0x4
.equ TRUE, 0x1
.equ FALSE, 0x0


.macro end
.byte 0x2
.endm

.macro return
.byte 0x3
.endm

.macro call pointer
.byte 0x4
.word \pointer
.endm

.macro goto pointer
.byte 0x5
.word \pointer
.endm

.macro if condition goto_pointer
.byte 0x6
.byte \condition
.word \goto_pointer
.endm

.macro callstd callstd_param1
.byte 0x9
.byte \callstd_param1
.endm

.macro loadpointer loadpointer_param1 loadpointer_param2
.byte 0xF
.byte \loadpointer_param1
.word \loadpointer_param2
.endm

.macro setvar variable_A value_to_set_A
.byte 0x16
.hword \variable_A
.hword \value_to_set_A
.endm

.macro copyvarifnotzero copyvarifnotzero_param1 copyvarifnotzero_param2
.byte 0x1A
.hword \copyvarifnotzero_param1
.hword \copyvarifnotzero_param2
.endm

.macro compare variable_A value_to_compare_A
.byte 0x21
.hword \variable_A
.hword \value_to_compare_A
.endm

.macro callasm pointer_to_routine
.byte 0x23
.word \pointer_to_routine
.endm

.macro special special_id
.byte 0x25
.hword \special_id
.endm

.macro waitstate
.byte 0x27
.endm

.macro setflag flag_id
.byte 0x29
.word \flag_id
.endm

.macro clearflag flag_id
.byte 0x2A
.word \flag_id
.endm

.macro checkflag flag_id
.byte 0x2B
.word \flag_id
.endm

.macro fadein fading_speed
.byte 0x38
.byte \fading_speed
.endm

.macro faceplayer
.byte 0x5A
.endm

.macro closeonkeypress
.byte 0x68
.endm

.macro lockall
.byte 0x69
.endm

.macro lock
.byte 0x6A
.endm

.macro releaseall
.byte 0x6B
.endm

.macro release
.byte 0x6C
.endm

.macro waitkeypress
.byte 0x6D
.endm

.macro multichoice left_coordinate top_coordinate choice_list_id b_button_onoff
.byte 0x6F
.byte \left_coordinate 
.byte \top_coordinate 
.byte \choice_list_id 
.byte \b_button_onoff
.endm

.macro givepokemon pokemon level item filler shiny nature
.byte 0x79
.hword \pokemon
.byte \level
.hword \item
.word \filler
.word \shiny
.byte \nature
.endm

.macro fadescreen fade_effect
.byte 0x97
.byte \fade_effect
.endm

.macro setwildbattle pokemon_species level item
.byte 0xB6
.hword \pokemon_species
.byte \level
.hword \item
.endm

.macro dowildbattle
.byte 0xB7
.endm


.macro msgbox text callstdid
loadpointer 0x0 \text
callstd \callstdid
.endm

.macro giveitem item quantity callstdid
copyvarifnotzero 0x8000 \item
copyvarifnotzero 0x8001 \quantity
callstd \callstdid
.endm 

.macro wildbattle pokemon_species level item
setwildbattle \pokemon_species \level \item
dowildbattle
.endm

.macro wildbattle2 pokemon_species level item fading_speed
setwildbattle \pokemon_species \level \item
fadein \fading_speed
waitstate
.endm
