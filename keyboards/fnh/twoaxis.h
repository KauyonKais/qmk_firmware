//
// Created by Kauyon Kais on 19.06.2018.
//

#pragma once

#include <stdint.h>
//DPAD positions
#define DPAD_C  0b00000000
#define DPAD_UL 0b10000000
#define DPAD_U  0b01000000
#define DPAD_UR 0b00100000
#define DPAD_L  0b00010000
#define DPAD_R  0b00001000
#define DPAD_DL 0b00000100
#define DPAD_D  0b00000010
#define DPAD_DR 0b00000001
// Twoaxis modes
#define TA_NONE 0
#define TA_MOUSE 2
#define TA_SCROLL 3
#define TA_DPAD 4
#define TA_ROTARY 5
//standard values
#ifndef TA_DEADZONE
#   define TA_DEADZONE 20
#endif
#ifndef TA_DPAD_CORNER
#   define TA_DPAD_CORNER 90
#endif
#ifndef TA_DPAD_SIDE
#   define TA_DPAD_SIDE 75
#endif
#ifndef TA_MOUSE_THROTTLE
# define TA_MOUSE_THROTTLE 3
#endif

void twoaxis_task(void);
void twoaxis(int8_t x, int8_t y, uint8_t id);
void ta_setmode(uint8_t ta_mode);
void dpad(void);
void twoaxis_as_scroll(void);
void twoaxis_as_mouse(void);

// TODO:
// rework matrix so it doesn't break everything
// deadzone
// mouse and scroll
// rotary
// document everything (HAH AS IF)

// DONE  hitboxes for dpad8