//
// Created by Kauyon Kais on 19.06.2018.
//

#pragma once

#include <stdint.h>

#define DPAD_C  0b00000000
#define DPAD_UL 0b10000000
#define DPAD_U  0b01000000
#define DPAD_UR 0b00100000
#define DPAD_L  0b00010000
#define DPAD_R  0b00001000
#define DPAD_DL 0b00000100
#define DPAD_D  0b00000010
#define DPAD_DR 0b00000001

#define TA_NONE 0
#define TA_MOUSE 2
#define TA_SCROLL 3
#define TA_DPAD 4
#define TA_ROTARY 5

void twoaxis(int8_t x, int8_t y, uint8_t id);
enum twoaxis_modes;
void dpad(void);
void twoaxis_as_scroll(void);
void twoaxis_as_mouse(void);
