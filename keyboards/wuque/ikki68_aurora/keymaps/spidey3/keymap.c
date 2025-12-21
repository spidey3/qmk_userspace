// Copyright 2025 Joshua Diamond josh@windowoffire.com (@spidey3)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spidey3.h"

extern rgblight_config_t rgblight_config;

bool logo_enabled = true;

bool process_record_user_keymap(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed && (keycode == UG_TOGG)) {
        if (rgblight_config.enable) {
            if (logo_enabled) {
                logo_enabled = false;
                rgblight_set_effect_range(0, 16);
                rgblight_setrgb_range(0, 0, 0, 16, 20);
            } else {
                rgblight_disable();
            }
        } else {
            logo_enabled = true;
            rgblight_set_effect_range(0,20);
            rgblight_enable();
        }
        return false;
    }

    return true;
}
