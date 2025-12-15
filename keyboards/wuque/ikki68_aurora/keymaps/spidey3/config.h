// Copyright 2022 Joshua Diamond josh@windowoffire.com (@spidey3)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define NO_ACTION_ONESHOT
#undef LOCKING_SUPPORT_ENABLE

#define LAYER_STATE_8BIT
#define MAX_LAYER 4

// LED map
// 
//            back
//   7   6   5   4   3   2   1
//   8                       0
//   9  10  11  12  13  14  15
//            front
//   
// LEDs 16-19 illuminate the top logo

#define LRGB_CORNER_BR(color) { 1, 1, color }
#define LRGB_CORNER_BL(color) { 7, 1, color }
#define LRGB_CORNER_FL(color) { 8, 2, color }
#define LRGB_CORNER_FR(color) { 0, 1, color }, { 15, 1, color }
#define LRGB_CORNERS(color) { 0, 2, color }, { 7, 3, color }, { 15, 1, color }
#define LRGB_FRONT(inset, color) { 9+inset, 15-inset, color }
#define LRGB_BACK(inset, color) { 1+inset, 7-inset, color }
#define LRGB_ACK(color) { 16, 4, color }
