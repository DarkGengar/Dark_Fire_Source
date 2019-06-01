MID_FLAGS       := -m92 -n
SND_DIR			:= $(RES_DIR)/snd
SND_LIB			:= $(LIB_DIR)/libsnd.a

local_mid_src	:= 	$(call rwildcard,$(SND_DIR),*.mid)
local_gen_src	:= 	$(local_mid_src:%.mid=$(OBJ_DIR)/%.s)
snd_objs		:= $(local_gen_src:%.s=%.o)

libraries		+= $(SND_LIB)

# ============================================================================
# Rules
# ============================================================================
$(OBJ_DIR)/%.s: %.mid
	$(MIDI2AGB) $< $@ $(M_FLAGS)

# ============================================================================
# Targets
# ============================================================================
$(SND_LIB) : $(snd_objs)