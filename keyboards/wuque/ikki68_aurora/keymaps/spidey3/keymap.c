// Copyright 2025 Joshua Diamond josh@windowoffire.com (@spidey3)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spidey3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base
    [_BASE] = LAYOUT_68_ansi(
        QK_GESC,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,    KC_EQL,    KC_BSPC,       KC_HOME,   KC_PGUP,
        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,    KC_RBRC,   KC_BSLS,       KC_END,    KC_PGDN,
        KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,           KC_ENT,
        KC_LSFT,              KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,           KC_RSFT,           KC_UP,
        KC_LCTL,   KC_LGUI,   KC_LALT,                                    KC_SPC,                                     KC_RALT,   MO(_FN),    KC_RCTL,       KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
    // Numpad
    [_NUMPAD] = LAYOUT_68_ansi(
        XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_NUM,    XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_KP_7,   KC_KP_8,   KC_KP_9,   KC_KP_0,   KC_PMNS,    KC_PEQL,   _______,       _______,   _______,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_KP_4,   KC_KP_5,   KC_KP_6,   KC_PCMM,   _______,    _______,   _______,       _______,   _______,
        KC_NUM,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_KP_1,   KC_KP_2,   KC_KP_3,   KC_PPLS,   KC_PAST,           KC_PENT,
        _______,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_KP_0,   MK_00,     KC_PDOT,   KC_PSLS,   _______,           _______,           _______,
        _______,   _______,   _______,                                    _______,                                    _______,   _______,    _______,       _______,   _______,   _______
    ),
    // FN
    [_FN] = LAYOUT_68_ansi(
        KC_GRV,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,     KC_F12,     KC_INS,       KC_PSCR,   KC_BRIU,
        XXXXXXX,   UG_TOGG,   UG_NEXT,   UG_HUED,   UG_HUEU,   UG_SATD,   UG_SATU,   UG_VALD,   UG_VALU,   XXXXXXX,   VK_TOGG,   CH_SUSP,    KC_SLEP,    KC_CPNL,      KC_PWR,    KC_BRID,
        MO(_GLYPH),XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_KP_1,   KC_KP_2,   KC_KP_3,   KC_PPLS,   KC_PAST,           KC_PENT,
        _______,              XXXXXXX,   UC_EMAC,   UC_WINC,   UC_NEXT,   NK_TOGG,   TG(_NUMPAD),UC_MAC,   XXXXXXX,   XXXXXXX,   DB_TOGG,           _______,           KC_VOLU,
        _______,   _______,   _______,                                    KC_MPLY,                                    KC_APP,    _______,    KC_ASST,       KC_MPRV,   KC_VOLD,   KC_MNXT
    ),
    // Glyph Transformation
    [_GLYPH] = LAYOUT_68_ansi(
        QK_BOOT,   UM(SAD),   UM(MEH),   UM(HAPPY), UM(ANGRY), UM(THUMBD),UM(THUMBU),UM(SPIDER),X_BUL,     UM(LOL),   UM(SURPR), X_DASH,    CH_GFLK,     XXXXXXX,       XXXXXXX,   KC_SCRL,
        EE_CLR,    GR_NORM,   GR_WIDE,   GR_SCRI,   GR_BLOC,   GR_CIRC,   GR_SQUA,   GR_PARE,   GR_FRAK,   GR_BOLD,   GR_MATH,   XXXXXXX,   XXXXXXX,     XXXXXXX,       XXXXXXX,   XXXXXXX,
        _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,           XXXXXXX,
        XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   UM(LARR),  UM(RARR),  XXXXXXX,           XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,                                    XXXXXXX,                                    XXXXXXX,   _______,   XXXXXXX,          XXXXXXX,  XXXXXXX,   XXXXXXX
    )
};

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
