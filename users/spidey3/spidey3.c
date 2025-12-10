// Copyright 2022 Joshua Diamond josh@windowoffire.com (@spidey3)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "spidey3.h"
#include "version.h"
#include <stdlib.h>

static bool rand_seeded = false;

#if defined(CONSOLE_ENABLE) && !defined(NO_DEBUG)
#    if defined(SPI_DEBUG_SCAN_RATE)
static uint32_t matrix_scan_count = 0;
static uint32_t matrix_timer      = 0;

void matrix_scan_user(void) {
    matrix_scan_count++;
    if (debug_enable) {
        uint32_t timer_now = timer_read32();
        if (matrix_timer == 0) {
            matrix_timer      = timer_now;
            matrix_scan_count = 0;
        } else if (TIMER_DIFF_32(timer_now, matrix_timer) > SPI_SCAN_RATE_INTERVAL * 1000) {
            matrix_timer = timer_now;
            uprintf("scan rate: %lu/s\n", matrix_scan_count / SPI_SCAN_RATE_INTERVAL);
            matrix_scan_count = 0;
        }
    } else {
        matrix_timer = 0;
    }
}
#    endif
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!rand_seeded) {
        srand(record->event.time % keycode);
        rand_seeded = true;
    }

    uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
    uint8_t osm = get_oneshot_mods();
#else
    uint8_t osm = 0;
#endif

    switch (keycode) {

#ifdef SHIFT_BACKSPACE_DELETE
        case KC_BSPC: {
            static bool delkey_registered;
            if (record->event.pressed) {
                if ((mods | osm) & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
#    ifndef NO_ACTION_ONESHOT
                    clear_oneshot_mods();
#    endif
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mods);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
        }
#endif

    }

#ifdef RGBLIGHT_ENABLE
    return process_record_user_rgb(keycode, record);
#else
    return true;
#endif
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_ENABLE
    post_process_record_user_rgb(keycode, record);
#endif
    return;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    return default_layer_state_set_user_rgb(state);
#else
    return state;
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    return layer_state_set_user_rgb(state);
#else
    return state;
#endif
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_ENABLE
    return led_update_user_rgb(led_state);
#else
    return true;
#endif
}

#if defined(UNICODE_COMMON_ENABLE)
void unicode_input_mode_set_user(uint8_t input_mode) {
#    ifdef RGBLIGHT_ENABLE
    unicode_input_mode_set_user_rgb(input_mode);
#    endif
}
#endif
