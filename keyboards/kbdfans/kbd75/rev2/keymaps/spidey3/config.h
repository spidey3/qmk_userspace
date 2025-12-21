#pragma once

#define NO_ACTION_ONESHOT
#undef LOCKING_SUPPORT_ENABLE

#define LAYER_STATE_8BIT
#define MAX_LAYER 3

// LED map
// 
//            back
//   0   1   2   3   4   5   6   7
// 
//   15  13  13  12  11  10  9   8
//            front

#define LRGB_CORNER_BL(color) { 0, 1, color }
#define LRGB_CORNER_BR(color) { 7, 1, color }
#define LRGB_CORNER_FR(color) { 8, 1, color }
#define LRGB_CORNER_FL(color) { 15, 1, color }
#define LRGB_CORNERS(color) {0, 1, color}, {7, 2, color}, { 15, 1, color }
#define LRGB_FRONT(inset, color) { 8 + inset, 8 - 2 * inset, color }
#define LRGB_BACK(inset, color) { inset, 8 - 2 * inset, color }
#define LRGB_ACK(color) { 9, 6, color }
