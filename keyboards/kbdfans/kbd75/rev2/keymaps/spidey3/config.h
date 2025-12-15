#pragma once

#define NO_ACTION_ONESHOT
#undef LOCKING_SUPPORT_ENABLE

#define LAYER_STATE_8BIT
#define MAX_LAYER 3

// Define corners for rgblight layer indicators
#define LRGB_CORNER_BL(color) { 0, 1, color }
#define LRGB_CORNER_BR(color) { RGBLIGHT_LED_COUNT / 2 - 1, 1, color }
#define LRGB_CORNER_FR(color) { RGBLIGHT_LED_COUNT / 2, 1, color }
#define LRGB_CORNER_FL(color) { RGBLIGHT_LED_COUNT - 1, 1, color }
#define LRGB_CORNERS(color) {0, 1, color}, {RGBLIGHT_LED_COUNT / 2 - 1, 2, color}, { RGBLIGHT_LED_COUNT - 1, 1, color }
#define LRGB_FRONT(inset, color) { RGBLIGHT_LED_COUNT / 2 + inset, RGBLIGHT_LED_COUNT / 2 - 2 * inset, color }
#define LRGB_BACK(inset, color) { inset, RGBLIGHT_LED_COUNT / 2 - 2 * inset, color }
#define LRGB_ACK(color) { RGBLIGHT_LED_COUNT / 2 + 1, RGBLIGHT_LED_COUNT / 2 - 2, color }
