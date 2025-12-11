// Copyright 2025 Joshua Diamond josh@windowoffire.com (@spidey3)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "os_detection.h"

bool process_record_os_detect_debug(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_os_detect_debug_kb(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case OS_DETECT_PRINT_SETUPS:
            if (record->event.pressed) {
                dprintf("os detect: print setups\n");
                print_stored_setups();
            }
            return false;
    }

    return true;
}
