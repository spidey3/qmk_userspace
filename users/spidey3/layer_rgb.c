// Copyright 2022 Joshua Diamond josh@windowoffire.com (@spidey3)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "spidey3.h"
#include <lib/lib8tion/lib8tion.h>

extern bool     chromeos_gflock;
extern uint16_t glyph_replace_mode;

// clang-format off

// Convenience macros
#define NONE { RGBLIGHT_END_SEGMENTS }
#define CORNER_BL(color) { 0, 1, color }
#define CORNER_BR(color) { RGBLIGHT_LED_COUNT / 2 - 1, 1, color }
#define CORNER_FR(color) { RGBLIGHT_LED_COUNT / 2, 1, color }
#define CORNER_FL(color) { RGBLIGHT_LED_COUNT - 1, 1, color }
#define CORNERS(color) {0, 1, color}, {RGBLIGHT_LED_COUNT / 2 - 1, 2, color}, { RGBLIGHT_LED_COUNT - 1, 1, color }
#define FRONT(inset, color) { RGBLIGHT_LED_COUNT / 2 + inset, RGBLIGHT_LED_COUNT / 2 - 2 * inset, color }
#define BACK(inset, color) { inset, RGBLIGHT_LED_COUNT / 2 - 2 * inset, color }

const rgblight_segment_t PROGMEM _none[] = NONE;

#define LAYER_OFFSET 0
// No indicator for base layer
const rgblight_segment_t PROGMEM _layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(CORNERS(HSV_MAGENTA));  // _NUMPAD
const rgblight_segment_t PROGMEM _layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(CORNERS(HSV_GREEN));    // _FN

#define LOCK_OFFSET 3
const rgblight_segment_t PROGMEM _numlock_layer[]    = RGBLIGHT_LAYER_SEGMENTS(FRONT(3, HSV_YELLOW));
const rgblight_segment_t PROGMEM _capslock_layer[]   = RGBLIGHT_LAYER_SEGMENTS(CORNER_FL(HSV_AZURE));
const rgblight_segment_t PROGMEM _scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(CORNER_FR(HSV_ORANGE));

#define MISC_OFFSET 6
const rgblight_segment_t PROGMEM _gflock_layer[]       = RGBLIGHT_LAYER_SEGMENTS(BACK(1, HSV_ORANGE));
const rgblight_segment_t PROGMEM _glyphreplace_layer[] = RGBLIGHT_LAYER_SEGMENTS(FRONT(1, HSV_ORANGE));

#define ACK_OFFSET 8
const rgblight_segment_t PROGMEM _no_layer[]     = RGBLIGHT_LAYER_SEGMENTS(FRONT(1, HSV_RED));
const rgblight_segment_t PROGMEM _yes_layer[]    = RGBLIGHT_LAYER_SEGMENTS(FRONT(1, HSV_GREEN));
const rgblight_segment_t PROGMEM _meh_layer[]    = RGBLIGHT_LAYER_SEGMENTS(FRONT(1, HSV_YELLOW));
const rgblight_segment_t PROGMEM _huh_layer[]    = RGBLIGHT_LAYER_SEGMENTS(CORNERS(HSV_YELLOW), FRONT(1, HSV_BLUE), BACK(1, HSV_BLUE));

#define UNICODE_OFFSET 12
const rgblight_segment_t PROGMEM _uc_mac_layer[]  = RGBLIGHT_LAYER_SEGMENTS(CORNER_BR(HSV_PURPLE));
// No indicator for UNICODE_MODE_LINUX
// UNICODE_MODE_WINDOWS disabled in config.h
// UNICODE_MODE_BSD not implemented
const rgblight_segment_t PROGMEM _uc_winc_layer[] = RGBLIGHT_LAYER_SEGMENTS(CORNER_BR(HSV_CYAN));
const rgblight_segment_t PROGMEM _uc_emacs_layer[] = RGBLIGHT_LAYER_SEGMENTS(CORNER_BR(HSV_GREEN));

// Now define the array of layers. Higher numbered layers take precedence.
const rgblight_segment_t *const PROGMEM _rgb_layers[] = {
    [LAYER_OFFSET + _BASE]   = _none,
    [LAYER_OFFSET + _NUMPAD] = _layer1_layer,
    [LAYER_OFFSET + _FN]     = _layer2_layer,

    [LOCK_OFFSET + 0] = _numlock_layer,
    [LOCK_OFFSET + 1] = _capslock_layer,
    [LOCK_OFFSET + 2] = _scrolllock_layer,

    [MISC_OFFSET + 0] = _gflock_layer,
    [MISC_OFFSET + 1] = _glyphreplace_layer,

    [ACK_OFFSET + ACK_NO]     = _no_layer,
    [ACK_OFFSET + ACK_YES]    = _yes_layer,
    [ACK_OFFSET + ACK_MEH]    = _meh_layer,
    [ACK_OFFSET + ACK_HUH]    = _huh_layer,

    [UNICODE_OFFSET + UNICODE_MODE_MACOS]      = _uc_mac_layer,
    [UNICODE_OFFSET + UNICODE_MODE_LINUX]      = _none,
    [UNICODE_OFFSET + UNICODE_MODE_WINDOWS]    = _none,
    [UNICODE_OFFSET + UNICODE_MODE_BSD]        = _none,
    [UNICODE_OFFSET + UNICODE_MODE_WINCOMPOSE] = _uc_winc_layer,
    [UNICODE_OFFSET + UNICODE_MODE_EMACS]      = _uc_emacs_layer,

    [UNICODE_OFFSET + UNICODE_MODE_COUNT] = NULL
};

// clang-format on

const uint8_t PROGMEM _n_rgb_layers = ARRAY_SIZE(_rgb_layers) - 1;

void clear_rgb_layers() {
    for (uint8_t i = 0; i < _n_rgb_layers; i++) {
        rgblight_set_layer_state(i, false);
    }
}

void do_rgb_layers(layer_state_t state, uint8_t start, uint8_t end) {
    for (uint8_t i = start; i < end; i++) {
        bool is_on = layer_state_cmp(state, i);
        rgblight_set_layer_state(LAYER_OFFSET + i, is_on);
    }
}

void do_rgb_unicode(uint8_t uc_mode) {
    for (uint8_t i = 0; i < UNICODE_MODE_COUNT; i++) {
        bool is_on = i == uc_mode;
        rgblight_set_layer_state(UNICODE_OFFSET + i, is_on);
    }
}

void do_rgb_all(void) {
    do_rgb_layers(default_layer_state, LAYER_BASE_DEFAULT, LAYER_BASE_REGULAR);
    do_rgb_layers(layer_state, LAYER_BASE_REGULAR, LAYER_BASE_END);
    do_rgb_unicode(get_unicode_input_mode());
    rgblight_set_layer_state(MISC_OFFSET + 0, chromeos_gflock);
    rgblight_set_layer_state(MISC_OFFSET + 1, glyph_replace_mode != GLYPH_REPLACE_MODE_NORMAL);
}

extern rgblight_config_t rgblight_config;

void keyboard_post_init_user_rgb(void) {
    // Enable the LED layers
    rgblight_layers = _rgb_layers;
    do_rgb_all();
}

void shutdown_user_rgb(void) {
    clear_rgb_layers();
}

layer_state_t default_layer_state_set_user_rgb(layer_state_t state) {
    do_rgb_layers(state, LAYER_BASE_DEFAULT, LAYER_BASE_REGULAR);
    return state;
}

layer_state_t layer_state_set_user_rgb(layer_state_t state) {
    do_rgb_layers(state, LAYER_BASE_REGULAR, LAYER_BASE_END);
    return state;
}

bool led_update_user_rgb(led_t led_state) {
    rgblight_set_layer_state(LOCK_OFFSET + 0, led_state.num_lock);
    rgblight_set_layer_state(LOCK_OFFSET + 1, led_state.caps_lock);
    rgblight_set_layer_state(LOCK_OFFSET + 2, led_state.scroll_lock);

    return true;
}

#if defined(UNICODE_COMMON_ENABLE)
void unicode_input_mode_set_user_rgb(uint8_t input_mode) {
    rgb_layer_ack(ACK_MEH);
    do_rgb_unicode(input_mode);
}
#endif

void rgb_layer_ack_yn(bool yn) {
    rgb_layer_ack(yn ? ACK_YES : ACK_NO);
}

void rgb_layer_ack(layer_ack_t n) {
    uint8_t layer = ACK_OFFSET + n;
    rgblight_blink_layer(layer, RGB_LAYER_ACK_DURATION);
}

extern keymap_config_t   keymap_config;

void post_process_record_user_rgb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Acks follow...
        case QK_DEBUG_TOGGLE:
            if (debug_matrix || debug_keyboard)
                rgb_layer_ack(ACK_HUH);
            else if (debug_enable)
                rgb_layer_ack(ACK_YES);
            else
                rgb_layer_ack(ACK_NO);
            break;

        case CHROMEOS_GUI_FKEY_LOCK:
            rgb_layer_ack_yn(chromeos_gflock);
            rgblight_set_layer_state(MISC_OFFSET + 0, chromeos_gflock);
            break;

        case GLYPH_REPLACE_MODE_NORMAL ... GLYPH_REPLACE_MODE_MATH:
            rgb_layer_ack_yn(glyph_replace_mode != GLYPH_REPLACE_MODE_NORMAL);
            rgblight_set_layer_state(MISC_OFFSET + 1, glyph_replace_mode != GLYPH_REPLACE_MODE_NORMAL);
            break;

        case UG_TOGG:
            // Hack - we only get called on the press for UG_TOGG,
            // but the flag is only flipped on the release...
            rgb_layer_ack_yn(!rgblight_config.enable);
            break;

#ifdef VELOCIKEY_ENABLE
        case QK_VELOCIKEY_TOGGLE:
            rgb_layer_ack_yn(rgblight_velocikey_enabled());
            break;
#endif

#ifdef NKRO_ENABLE
        case NK_TOGG:
        case NK_ON:
        case NK_OFF:
            rgb_layer_ack_yn(keymap_config.nkro);
            break;
#endif
    }
}
