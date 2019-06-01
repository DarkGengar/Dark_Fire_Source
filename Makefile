ifeq ($(strip $(DEVKITARM)),)
  $(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include	df_tools.mk
include	functions.mk

.SUFFIXES:

# ============================================================================
# Project Details
# ============================================================================
# PROJ		: Base project name
# TITLE		: Title for ROM header (12 characters)
# LIBS		: Libraries to use, formatted as list for linker flags
# BUILD		: Directory for build process temporaries. Should NOT be empty!
# APPDIR	: Directory for GBA application
# SRCDIRS	: List of source file directories
# DATADIRS	: List of data file directories
# INCDIRS	: List of header file directories
# LIB_DIR	: Directory of project libraries. ONLY FOR LIBS OF BUILD PROCESS!
# LIB_DIRS	: List of library directories

PROJ		:= Dark_Fire
BIN_DIR		:= bin
DF_ROM		:= $(BIN_DIR)/$(PROJ).gba
OBJ_DIR		:= obj
SRC_DIR		:= src
RES_DIR		:= res
DATA_DIR	:= data
INC_DIR		:= include
LIB_DIR		:= lib
DEPS_DIR	:= $(OBJ_DIR)

INCLUDE 	:= -Iinclude/libpkn -Iinclude/libdf -Ilib/include				\
				-Iinclude/libpkn/asm/ -Iinclude/libdf/asm/

# === switches ===
bTEMPS	:= 0	# Save gcc temporaries (.i and .s files)
bDEBUG	:= 0	# Generate debug info

# ============================================================================
# Bash Scripting
# ============================================================================
SHELL				:=	/bin/bash
MOVE				:= 	mv
XCOPY				:= 	cp
MKDIR				:=	mkdir -p
REMOVE				:=	rm -rfv

# ============================================================================
# Build Flags
# ============================================================================
ARCH    := -mthumb-interwork -mthumb
RARCH   := -mthumb-interwork -mthumb -mlong-calls
IARCH   := -mthumb-interwork -marm -mlong-calls

# === Main flags ===

LDFLAGS		:=

ifeq ($(strip $(bDEBUG)), 2)
  CFLAGS	:= -mcpu=arm7tdmi -mtune=arm7tdmi -O3
  CFLAGS	+= -Wall -Wextra -Werror
  CFLAGS	+= $(INCLUDE)
  CFLAGS	+=

  CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions

  ASFLAGS	:= $(ARCH)
else ifeq ($(strip $(bDEBUG)), 1)
  CFLAGS	:= -mcpu=arm7tdmi -mtune=arm7tdmi -O3
  CFLAGS	+= -Wall -Wextra -Werror
  CFLAGS	+= $(INCLUDE)
  CFLAGS	+=

  CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions

  ASFLAGS	:= $(ARCH)
else
  CFLAGS	:= -mcpu=arm7tdmi -mtune=arm7tdmi -O2
  CFLAGS	+= -Wall -Wextra -Werror
  CFLAGS	+= $(INCLUDE)
  CFLAGS	+= -fno-inline -ffast-math -fno-strict-aliasing

  CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions
  ASFLAGS	:= $(ARCH)
endif

# --- Save temporary files ? ---
ifeq ($(strip $(bTEMPS)), 1)
  CFLAGS	+= -save-temps
  CXXFLAGS	+= -save-temps
endif

# --- Debug info ? ---

ifeq ($(strip $(bDEBUG)), 2)
  CFLAGS	+= -DNDEBUG
  CXXFLAGS	+= -DNDEBUG
  ASFLAGS	+= -DNDEBUG
else ifeq ($(strip $(bDEBUG)), 1)
  CFLAGS	+= -DDEBUG -g
  CXXFLAGS	+= -DDEBUG -g
  ASFLAGS	+= -DDEBUG -g
else
  CFLAGS	+= -DNDEBUG
  CXXFLAGS	+= -DNDEBUG
  ASFLAGS	+= -DNDEBUG
endif

# ============================================================================
# Sources
# ============================================================================
SYMBOL_FILE			:= $(OBJ_DIR)/symbol_list.sym
tmp_ld	  			:= tmp.ld
main_obj			:= $(OBJ_DIR)/linked.o
all_obj				:=

# Do not fill in libs here, use the modules for that
libraries			:=
# ============================================================================
# Rules
# ============================================================================

%.a :
	@echo $(notdir $@)
	@rm -f $@
	$(AR) -crs $@ $^

# === Object Rules ===
$(OBJ_DIR)/%.iwram.o : %.iwram.cpp
	@echo $(notdir $<)
	@[ -d $(dir $@) ] || $(MKDIR) -p $(dir $@)
	$(CXX) -MMD -MP -MF $(DEPS_DIR)/$*.d $(CXXFLAGS) $(IARCH) -c $< -o $@
	
$(OBJ_DIR)/%.iwram.o : %.iwram.c
	@echo $(notdir $<)
	@[ -d $(dir $@) ] || $(MKDIR) -p $(dir $@)
	$(CC) -std=gnu11 -MMD -MP -MF $(DEPS_DIR)/$*.d $(CFLAGS) $(IARCH) -c $< -o $@

$(OBJ_DIR)/%.o : %.cpp
	@echo $(notdir $<)
	@[ -d $(dir $@) ] || $(MKDIR) -p $(dir $@)
	$(CXX) -MMD -MP -MF $(DEPS_DIR)/$*.d $(CXXFLAGS) $(RARCH) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	@echo $(notdir $<)
	@[ -d $(dir $@) ] || $(MKDIR) -p $(dir $@)
	@$(CC) -std=gnu11 -MMD -MP -MF $(DEPS_DIR)/$*.d $(CFLAGS) $(RARCH) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	@echo $(notdir $<)
	@[ -d $(dir $@) ] || $(MKDIR) -p $(dir $@)
	@$(CC) -MMD -MP -MF $(DEPS_DIR)/$*.d -x assembler-with-cpp $(ASFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.S
	@echo $(notdir $<)
	@[ -d $(dir $@) ] || $(MKDIR) -p $(dir $@)
	@$(CC) -MMD -MP -MF $(DEPS_DIR)/$*.d -x assembler-with-cpp $(ASFLAGS) -c $< -o $@

# ============================================================================
# Targets
# ============================================================================
.PHONY:	all
all:

include src/core/module.mk
include res/gfx/module.mk

all: $(DF_ROM)


$(DF_ROM): main.asm patches.asm $(main_obj)
	@[ -d $(BIN_DIR) ] || $(MKDIR) -p $(BIN_DIR)
	@$(ARMIPS) $<
	@$(NM) $(main_obj) -n -g --defined-only | \
		sed -e '{s/^/0x/g};{/.*\sA\s.*/d};{s/\sT\s/ /g}' > $(SYMBOL_FILE)
	@echo "=====| Build process was successful |====="

$(main_obj): $(all_obj) $(libraries)
	@echo "INPUT($^)" > $(tmp_ld)
	$(LD) $(LDFLAGS) -T linker.ld -T bprd_symbols.ld --whole-archive -r -o $@ -T $(tmp_ld)
	@rm -f $(tmp_ld)

.PHONY: clean
clean:
	$(REMOVE) $(OBJ_DIR) $(libraries)

.PHONY: clean_src
clean_src:
	$(REMOVE) $(OBJ_DIR)/$(SRC_DIR) $(CORE_LIB)

.PHONY: clean_core
clean_core:
	$(REMOVE) $(OBJ_DIR)/$(CORE_DIR) $(CORE_LIB)

.PHONY: clean_res
clean_res:
	$(REMOVE) $(OBJ_DIR)/$(RES_DIR) $(GFX_LIB) $(GFX_HDR)

.PHONY: clean_gfx
clean_gfx:
	$(REMOVE) $(OBJ_DIR)/$(GFX_DIR) $(GFX_LIB) $(GFX_HDR)
