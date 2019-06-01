GFX_HDR			:= $(INC_DIR)/gfx.h
GFX_DIR			:= $(RES_DIR)/gfx
GFX_LIB			:= lib/libgfx.a

local_png_src		:= $(call rwildcard,$(GFX_DIR),*.png)
local_bmp_src		:= $(call rwildcard,$(GFX_DIR),*.bmp)

gfx_inc_src			:= 	$(local_png_src:%.png=%.h)	\
						$(local_bmp_src:%.bmp=%.h)

gfx_objs			:= 	$(local_png_src:%.png=$(OBJ_DIR)/%.o) \
						$(local_bmp_src:%.bmp=$(OBJ_DIR)/%.o)

libraries			+= $(GFX_LIB)

DEPENDS	:=	$(local_obj:.o=.d)

# ============================================================================
# Rules
# ============================================================================

# --- With separate .grit file ---

%.s %.h	: %.png %.grit
	$(GRIT) $< -o$* -fts
	
%.s %.h	: %.bmp %.grit
	$(GRIT) $< -o$* -fts

%.s %.h	: %.pcx %.grit
	$(GRIT) $< -o$* -fts

%.s /%.h : %.jpg %.grit
	$(GRIT) $< -o$* -fts

# --- Without .grit file ; uses dirname/dirname.grit for options ---

%.s %.h	: %.png
	$(GRIT) $< -o$* -fts -ff $(<D)/$(notdir $(<D)).grit

%.s %.h	: %.bmp
	$(GRIT) $< -o$* -fts -ff $(<D)/$(notdir $(<D)).grit

%.s %.h	: %.pcx
	$(GRIT) $< -o$* -fts -ff $(<D)/$(notdir $(<D)).grit

%.s %.h	: %.jpg
	$(GRIT) $< -o$* -fts -ff $(<D)/$(notdir $(<D)).grit

# ============================================================================
# Targets
# ============================================================================

$(GFX_LIB) : $(gfx_objs) $(GFX_HDR)
	@echo $(notdir $@)
	@rm -f $@
	$(AR) -crs $@ $(gfx_objs)
	
$(GFX_HDR) : $(gfx_objs)
	@echo "Creating master header: $@"
	@$(call create-master-header,$@,$(gfx_inc_src),1)