enemys_party = 0x0202402C;
players_party = 0x02024284;
palette_bg_unfaded = 0x020371F8;
palette_faded_buffer = 0x020375F8;
pal_prebuffer = 0x02037ACC;
saveblock1 = 0x03004F58;
saveblock2 = 0x03004F5C;
cpuset_copysize = 0x04000100;

/* palette.h */
pal_fade_control = 0x02037AB8;

scr_cmd_table = 0x0815f914;
attack_data_table = 0x08250B28;

/* oams.h */
gpu_pal_tags = 0x03000DE8;

/* variables */
var_0x8000 = 0x020370B8;
var_0x8001 = 0x020370BA;
lastresult = 0x020370D0;

/* string.h */
rboxes = 0x020204B4;
string_buffer = 0x02021D18;
textbox_close = 0x080694E4|1;

/* callback.h */
super = 0x03003040;

/* task.h */
tasks = 0x03004FE0;

/* static rom functions */
titlescreen_function_0 = 0x08078C00|1;
get_random_change_seed = 0x08044DCC|1;
__umod = 0x081E856C|1;
checkflag = 0x0806E634|1;
create_pokemon = 0x0803D954|1;
return_to_ow = 0x080A1128|1;
setflag = 0x0806E5E4|1;
get_pokemons_attribute = 0x0803FAE8|1;
set_pokemons_attribute = 0x0804027c|1;
recalculate_stats = 0x0803E37C|1;
init_script = 0x08069AD4|1;
catchable = 0x0802d428|1;
uncatchable = 0x0802d3f8|1;
cant_runaway = 0x08016810|1;
can_runaway = 0x801680c|1;
color_blend = 0x08045178|1;
return_addr = 0x080719dc|1;
get_field_x2_from_trainerdata = 0x0804357C|1;
play_song = 0x080719D8|1;
get_current_weather = 0x807B094|1;
__aeabi_uidivmod = 0x081E7A50|1;
rain_sound_fadeout = 0x0807AF68|1;
fadeout_song = 0x08071CC8|1;
set_weather = 0x0807B064|1;
update_weather = 0x0807B108|1;
show_coins = 0x080D08D4|1;
get_number_of_coins = 0x080D06FC|1;
init_fadescreen = 0x0807A77C|1;
close_start_menu = 0x0806EE7C|1;
scn_query_string = 0x0809DA38|1;
nullify_something_called_on_townmap = 0x080F6A9C|1;
load_message_box = 0x080F7178|1;
check_a_pressed = 0x08002DE4|1;

/* variables.h */
var_set = 0x0806E4E8|1;
var_load = 0x0806E4CC|1;
var_access = 0x0806E3B8|1;

pokemon_full_clean_slot = 0x0803D894|1;

/* memory.h */
free = 0x08002B44|1;
malloc = 0x08002B1C|1;
memcpy = 0x081E9D60|1;
memset = 0x081E9DC0|1;
malloc_and_clear = 0x08002B30|1;

/* oams.h */
template_instanciate_forward_search = 0x08006F0C|1;
gpu_tile_obj_decompress_alloc_tag_and_upload = 0x0800EFB8|1;
gpu_pal_decompress_alloc_tag_and_upload = 0x0800EFFC|1;
oac_nullsub = 0x0800758C|1;
objects = 0x0202063C;
anim_image_empty = 0x08231BC0;
rotscale_empty = 0x08231BCC;
obj_delete_and_free_tiles = 0x08007200|1;
obj_and_aux_reset_all = 0x08006A90|1;
gpu_tile_obj_tags_reset = 0x08008744|1;
objc_exec = 0x08006ADC|1;
obj_sync_superstate = 0x08006B28|1;
object_clone = 0x0805FB6C|1;

/* background.h */
gpu_tile_bg_drop_all_sets = 0x08001628|1;
bg_vram_setup = 0x08001668|1;
gpu_sprites_upload = 0x080072A0|1;
copy_queue_process = 0x08007590|1;
bgid_set_tilemap = 0x08001FB0|1;
bgid_mod_x_offset = 0x08001BA0|1;
bgid_mod_y_offset = 0x08001D18|1;
bgid_get_tilemap = 0x08002018|1;
bgid_mark_for_sync = 0x080F6A38|1;
gpu_sync_bg_show = 0x080019CC|1;
gpu_sync_bg_hide = 0x080019E0|1;
bg_display_sync = 0x080013E0|1;
gpu_copy_to_vram_by_bgid = 0x080012A8|1;
overworld_free_bgmaps = 0x08056410|1;
tilemaps_sync = 0x080F6A4C|1;
bgid_send_tilemap = 0x080020CC|1;
gpu_copy_to_tileset = 0x080017E0|1;
gpu_copy_tilemap = 0x08002050|1;

/* callback.h */
vblank_handler_set = 0x08000704|1;
dma0_cb_reset = 0x08087DC8|1;
set_callback1 = 0x08056600|1;
set_callback2 = 0x08000554|1;
c2_exit_to_overworld_2_switch = 0x080567FC|1;

/* palette.h */
pal_fade_control_and_dead_struct_reset = 0x0807048C|1;
fade_screen = 0x080704EC|1;
gpu_pal_allocator_reset = 0x08008870|1;
gpu_pal_upload = 0x080703D8|1;
gpu_pal_apply = 0x08070350|1;
gpu_pal_apply_compressed = 0x0807030C|1;
palette_bg_faded_fill_black = 0x0807DA9C|1;
process_palfade = 0x08070434|1;

/* io.h */
lcd_io_set = 0x08000A48|1;
interrupts_enable = 0x08000B78|1;

/* string.h */
rboxes_free = 0x08003E4C|1;
rboxid_clear_pixels = 0x080043DC|1;
rboxid_free = 0x08003DBC|1;
rboxid_update = 0x08003EA0|1;
box_related_one = 0x080F6F64|1;
fdecoder = 0x08008F4C|1;
remoboxes_upload_tilesets = 0x08002D68|1;

/* multichoice.h */
multichoice_field = 0x080F7C6C|1;
multichoice_get_response = 0x0810FAB4|1;

/* task.h */
tasks_init = 0x08077320|1;
task_add = 0x08077380|1;
task_exec = 0x080774DC|1;
task_del = 0x0807746C|1;

/* bios.h */
lz77_uncomp_wram = 0x081E7A58|1;
lz77_uncomp_vram = 0x081E7A54|1;
cpuset = 0x081E7A4C|1;
cpufastset = 0x081E7A48|1;
obj_affine_set = 0x081E7A64|1;
bg_affine_set = 0x081E7A44|1;
register_ram_reset = 0x081E7A68|1;
arctan = 0x081E7A40|1;
div = 0x081E7A50|1;
sqrt = 0x081E7A84|1;

/* ow_ui.h */
help_system_disable__sp198 = 0x0812B4C8|1;
c2_overworld_switch_start_menu = 0x080568C8|1;

/* loading.h */
c1_overworld = 0x08056554|1;
c2_return_overworld_music_scripts_cont = 0x080568E4|1;

/* block.h */
sav1_secure_increment = 0x08054EB0|1;

/* audio.h */
audio_play = 0x08072230|1;

/* m4a.h */
m4a_song_num_start = 0x081E138C|1;
play_song_1 = 0x08072204|1;

/* compression.h */
malloc_and_lz77_uncomp = 0x080F6D34|1;
