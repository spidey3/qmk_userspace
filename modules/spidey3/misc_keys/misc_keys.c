// Copyright 2025 Joshua Diamond josh@windowoffire.com (@spidey3)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "os_detection.h"

bool process_record_misc_keys(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_misc_keys_kb(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case KC_PRINT_SCREEN: {
            if (record->event.pressed) {
                os_variant_t os   = detected_host_os();
                uint8_t      mods = get_mods();
#ifndef NO_ACTION_ONESHOT
                uint8_t osm = get_oneshot_mods();
#else
                uint8_t osm = 0;
#endif

                switch (os) {
                    case OS_MACOS:
                    case OS_IOS:
                        if ((mods | osm) & MOD_MASK_ALT) {
                            // Window screenshot
                            clear_mods();
#ifndef NO_ACTION_ONESHOT
                            clear_oneshot_mods();
#endif
                            tap_code16(LSFT(LGUI(KC_4)));
                            wait_ms(100);
                            tap_code(KC_SPC);
                            set_mods(mods);
                            return false;
                        } else if ((mods | osm) & MOD_MASK_SHIFT) {
                            // Full screenshot
                            tap_code16(LSFT(LGUI(KC_3)));
                            return false;
                        } else {
                            // Partial screenshot
                            tap_code16(LSFT(LGUI(KC_4)));
                            return false;
                        }
                        break;

                    case OS_WINDOWS:
                        if ((mods | osm) & MOD_MASK_ALT) {
                            // Window screenshot
                            // Alt+PrintScreen should work as is
                        } else if ((mods | osm) & MOD_MASK_SHIFT) {
                            // Full screenshot
                            // PrintScreen should work as is
                        } else {
                            // Partial screenshot
                            tap_code16(LGUI(LSFT(KC_S)));
                            return false;
                        }
                        break;

                    case OS_LINUX:
                    default:
                        if ((mods | osm) & MOD_MASK_ALT) {
                            // Window screenshot
                            tap_code16(LCTL(LALT(KC_F5)));
                            return false;
                        } else if ((mods | osm) & MOD_MASK_SHIFT) {
                            // Full screenshot
                            tap_code16(LCTL(KC_F5));
                            return false;
                        } else {
                            // Partial screenshot
                            tap_code16(LCTL(LSFT(KC_F5)));
                            return false;
                        }
                        break;
                }
                break;
            }
        } break;

        case MISC_KEYS_00:
            if (record->event.pressed) {
                tap_code(KC_KP_0);
#if TAP_CODE_DELAY > 0
                wait_ms(TAP_CODE_DELAY);
#endif
                register_code(KC_KP_0);
                return false;
            } else {
                unregister_code(KC_KP_0);
                return false;
            }
    }

    return true;
}
