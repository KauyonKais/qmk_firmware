/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define RGB_DI_PIN D4    // The pin the LED strip is connected to
#define RGBLED_NUM 26     // Number of LEDs in your strip
#define RGBLIGHT_LIMIT_VAL 125
#define RGBLIGHT_ANIMATIONS

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    KauyonKais
#define PRODUCT         FNH36
#define DESCRIPTION     Fingers Not Hands
#define TAPPING_TERM 200

//PRO MICRO
#define MATRIX_ROW_PINS { B3, B2, B6, B1 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5 }
//#define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4, D7 }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif


#endif
