BOOTMAGIC_ENABLE = yes    # Enable Bootmagic Lite
CONSOLE_ENABLE = yes      # Console for debug
OS_DETECTION_ENABLE = yes # Experimental OS detection
BACKLIGHT_ENABLE = no     # Enable keyboard backlight functionality
UNICODEMAP_ENABLE = yes   # Enable unicode

NKRO_ENABLE = yes
LTO_ENABLE = yes

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  DEFERRED_EXEC_ENABLE = yes
endif

SRC += init.c
SRC += spidey3.c

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += layer_rgb.c
endif
ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
  SRC += spidey3_unicode.c
endif
