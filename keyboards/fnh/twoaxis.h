//
// Created by Kauyon Kais on 19.06.2018.
//

#pragma once

#include <stdint.h>

#define DPAD_C 8
#define DPAD_UL 0
#define DPAD_U 1
#define DPAD_UR 2
#define DPAD_L 3
#define DPAD_R 4
#define DPAD_DL 5
#define DPAD_D 6
#define DPAD_DR 7

void twoaxis(int8_t x, int8_t y, uint8_t id);
enum twoaxis_modes;
void dpad(void);
void twoaxis_as_scroll(void);
void twoaxis_as_mouse(void);
void set_ta_layer(uint8_t);
