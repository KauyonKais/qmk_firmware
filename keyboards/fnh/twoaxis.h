//
// Created by Kauyon Kais on 19.06.2018.
//

#ifndef QMK_FIRMWARE_PSPSTICK_H
#define QMK_FIRMWARE_PSPSTICK_H

#define DPAD_DEAD 0
#define DPAD_U 1
#define DPAD_L 2
#define DPAD_D 3
#define DPAD_R 4

#include "twoaxis.c"

uint8_t twoaxis_as_dpad(void);
void dpad(void);
void twoaxis_as_scroll(void);
void twoaxis_as_mouse(void);
void set_ta_layer(uint8_t);


#endif //QMK_FIRMWARE_PSPSTICK_H
