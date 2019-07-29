/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS


#define USE_SERIAL_PD2
#define OLED_FONT_H "drifterfont.c"

//#define TAPPING_FORCE_HOLD

#ifdef RGBLIGHT_ENABLE
//#define RGBLIGHT_ANIMATIONS
#undef RGBLED_NUM
#define RGBLED_NUM 54
#define RGBLED_SPLIT { 27, 27 }

#define RGBLIGHT_LIMIT_VAL 100
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10

#endif

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_SPLIT { 27, 27 }
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

#undef USE_I2C
