.macro Mapheader name_of_mapheader p_mapfooter p_mapevent p_levelscript p_map_connection bg_music map_id map_name flash weather map_type is_bike show_name_type floor battle_style
.word \mapfooter
.word \mapevent
.endm

@ Map Bank Header Macros

@ Map Bank Macros

@ Map Header Macros
.macro P_Mapfooter
.word \P_Mapfooter
.endm

.macro P_Map_Event
.word \P_Map_Event
.endm

.macro P_Map_Levelscript
.word \P_Levelscript
.endm

.macro P_Map_Connection
.word \P_Map_Connection
.endm

.macro Map_BG_Music
.hword \Map_BG_Music
.endm

.macro Map_ID
.hword \Map_ID
.endm

.macro Map_Name_Bank
.byte \Map_Name_Bank
.endm

.macro Map_Flash
.byte \Map_Flash
.endm

.macro Weather
.byte \Weather
.endm

.macro Map_Type
.byte \Map_Type
.endm

.macro Is_Bike
.byte \Is_Bike
.endm

.macro Show_Name_Type
.byte \Show_Name_Type
.endm

.macro Map_Floor
.byte \Map_Floor
.endm

.macro Map_Battle_Style
.byte \Map_Battle_Style
.endm


@ Map Footer Macros

@ Map Event Macros

@ Map Wild Pokemon Habitat Macros

@ Map Connection Macros

@ Map Footer Table Macros

@ Map Wild Pokemon Header Macros
