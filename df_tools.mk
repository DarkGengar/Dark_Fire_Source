ifeq ($(strip $(DEVKITARM)),)
	$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/base_tools

ARMIPS		:= armips
GRIT		:= grit
MIDI2AGB	:= midi2agb
LD			:= $(PREFIX)ld
