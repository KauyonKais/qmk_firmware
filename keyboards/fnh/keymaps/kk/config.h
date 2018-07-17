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


#define RGBLIGHT_LIMIT_VAL 200

#include "config_common.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

#define MATRIX_ROWS 4
#define MATRIX_COLS 10

// wiring of each half


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
