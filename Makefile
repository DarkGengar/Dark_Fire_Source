#=====CMD Commands========================
MKDIR		:=	@mkdir -p
REMOVE		:=	@rm --force --recursive

#=====Directories=========================
PYGBATOOLCHAINDIR	:=	tools/py_gba_tools/src
RHRPATCHERDIR		:=	tools/rhr_patcher/console
BASEROMDIR			:=	base
DFROMDIR			:=	game_build
DFROMPATCHDIR		:=	$(DFROMDIR)/rom_patch
GFX_SUB_DIR			:=	asset/gfx
MUSIC_SUB_DIR		:=	asset/music
STRING_SUB_DIR		:= 	asset/strings
SRC_BUILD_SUB_DIR	:=	src
DOXY_SUB_DIR		:=	doc

#=====Tools===============================
MAKE				:=	@make
PYTHON				:=	@python
RHRPATCHER			:=	@$(RHRPATCHERDIR)/rhr-patcher

#=====Patch-Systems=======================
RHRPS				:=	rhrps
UPS					:=	ups
IPS					:=	ips

#=====Game================================
BASEROM		:=	$(BASEROMDIR)/BPRD_0.gba
DFROM		:=	$(DFROMDIR)/df_rom.gba
DFROMPATCH	:=	$(DFROMPATCHDIR)/df_rom_patch.rhr
LANGUAGE	:=	deu

#=====Sub-Makefiles=======================
GFX_SUB				:=	$(GFX_SUB_DIR)/gfx.sub
MUSIC_SUB			:= 	$(MUSIC_SUB_DIR)/music.sub
STRING_SUB			:=	$(STRING_SUB_DIR)/strings.sub
SRC_BUILD_SUB		:=	$(SRC_BUILD_SUB_DIR)/src_build.sub
DOXY_SUB			:=	doxy.sub

#=====Make Targets========================
.PHONY: all
all: prebuild build

.PHONY: prebuild
prebuild:
	$(MAKE) -f $(GFX_SUB) all
	$(MAKE) -f $(MUSIC_SUB) all
	$(MAKE) -f $(STRING_SUB) all
	$(MAKE) -C $(DOXY_SUB_DIR) -f $(DOXY_SUB) all


.PHONY: patch
patch:
	$(MKDIR) $(DFROMPATCHDIR)
	$(RHRPATCHER) -c $(RHRPS) $(BASEROM) $(DFROM) -o $(DFROMPATCH)
	
.PHONY: build
build:
	$(MAKE) -f $(SRC_BUILD_SUB) all
	
	
.PHONY: clean
clean:
	$(MAKE) -f $(GFX_SUB) clean
	$(MAKE) -f $(MUSIC_SUB) clean
	$(MAKE) -f $(STRING_SUB) clean
	$(MAKE) -f $(SRC_BUILD_SUB) clean
	$(MAKE) -C $(DOXY_SUB_DIR) -f $(DOXY_SUB) clean
	$(REMOVE) $(DFROMPATCHDIR)
	$(REMOVE) $(DFROM)
	