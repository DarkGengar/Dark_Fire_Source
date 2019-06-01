CORE_DIR			:= $(SRC_DIR)/core
CORE_LIB			:= $(LIB_DIR)/libcore.a

local_c_src			:= $(call rwildcard,$(CORE_DIR),*.c)
local_s1_src		:= $(call rwildcard,$(CORE_DIR),*.s)
local_s2_src		:= $(call rwildcard,$(CORE_DIR),*.S)



core_objs			:= 	$(local_c_src:%.c=$(OBJ_DIR)/%.o)	\
						$(local_s1_src:%.s=$(OBJ_DIR)/%.o)	\
						$(local_s2_src:%.S=$(OBJ_DIR)/%.o)

libraries			+= $(CORE_LIB)

# ============================================================================
# Targets
# ============================================================================

$(CORE_LIB) : $(core_objs)