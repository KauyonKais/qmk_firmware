/*
This is the keymap for the keyboard

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

#include QMK_KEYBOARD_H
#include "fnh.h"
#include "twoaxis.h"
//#include <print.h>
#include "rgblight.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum fnh_layers {
  _BSE,
  _USD,
  _SYB,
  _GAM,
  _CTL,
  _FUN
};
enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

enum tappers{
  HQT = 0,
  SCBS,
  DTAB,
  QESC
};
//uint8_t ta_layer=0;
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MD_SPC MT(MOD_LSFT, KC_BSPC)
#define MD_Z MT(MOD_LCTL, KC_Z)
#define MD_X MT(MOD_LGUI,KC_X)
#define MD_C MT(MOD_LALT,KC_C)
#define LK_SPC LT(_SYB, KC_SPC)
#define LK_ENT LT(_FUN, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BSE] = LAYOUT( \
    TD(QESC),  KC_G  ,  KC_E  ,  KC_R  ,  KC_W  ,             KC_Y    ,  KC_M  ,  KC_U  ,  KC_L  ,TD(SCBS),   \
    KC_D    ,  KC_S  ,  KC_T  ,  KC_F  ,  KC_A  ,             KC_I    ,  KC_J  ,  KC_N  ,  KC_O  , TD(HQT), \
    MD_Z    ,  MD_X  ,  MD_C  ,  KC_V  ,  KC_B  ,             KC_K    ,  KC_P  , KC_COMM,  KC_DOT, KC_SLSH, \
                      MO(_CTL), MD_SPC , LK_ENT ,             KC_ESC  , LK_SPC ,  KC_NO
  ),
  [_SYB] = LAYOUT( \
    KC_LPRN , KC_RPRN, KC_ASTR, KC_AMPR, KC_GRV ,             KC_PLUS ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,\
    KC_LBRC , KC_CIRC, KC_PERC, KC_DLR , KC_PIPE,             KC_EQL  ,  KC_4  ,  KC_5  ,  KC_6  , KC_RBRC, \
    KC_LCBR , KC_HASH, KC_AT  , KC_EXLM, KC_TILD,             KC_MINS ,  KC_1  ,  KC_2  ,  KC_3  , KC_RCBR, \
                       KC_TRNS, KC_TRNS, KC_TRNS,             KC_4    , KC_TRNS,  KC_NO
  ),
  [_GAM] = LAYOUT( \
    KC_Q    ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,            KC_Y     ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,   \
    KC_A    ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,            KC_H     ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, \
    KC_Z    ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,            KC_N     ,  KC_M  , KC_COMM,  KC_DOT, KC_SLSH, \
                       KC_TRNS, KC_TRNS, KC_TRNS,            KC_4     , KC_TRNS,  KC_NO
  ),
  [_CTL] = LAYOUT( \
    RALT(KC_TAB),  KC_NO ,  KC_NO ,  KC_NO ,  DEBUG ,        LCTL(KC_Y),    KC_PGUP,    KC_UP,    KC_PGDN,    KC_NO,   \
    KC_TAB  ,LCTL(KC_S),KC_NO,LCTL(KC_F),KC_NO,              KC_HOME,    KC_LEFT,     KC_DOWN,    KC_RIGHT,    KC_END, \
    LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_NO,       KC_NO,    KC_BTN1,    KC_BTN3, KC_BTN2,  KC_NO, \
    KC_TRNS,KC_LCTL,  KC_TRNS,                                                  KC_4,    KC_LSFT,    KC_NO
  ),
[_FUN] = LAYOUT( \
    RESET   ,RGB_SAI,RGB_MOD,  RGB_HUI  ,  KC_NO  ,            KC_Y    ,  KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_P  ,   \
    KC_A    ,RGB_SAD,RGB_RMOD,  RGB_HUD  ,  KC_NO  ,            KC_H    ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_SCLN, \
    KC_Z    ,RGB_VAI,RGB_VAD,RGB_TOG,  KC_NO  ,            KC_N    ,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_SLSH, \
                       KC_TRNS, KC_TRNS, KC_TRNS,            KC_4    , KC_TRNS,  KC_NO
  )
};


//TapDance

 qk_tap_dance_action_t tap_dance_actions[] = {
   [HQT] = ACTION_TAP_DANCE_DOUBLE (KC_H, KC_QUOT),
   [SCBS] = ACTION_TAP_DANCE_DOUBLE (KC_SCLN, KC_BSLS),
   [DTAB] = ACTION_TAP_DANCE_DOUBLE (KC_D, KC_TAB),
   [QESC] = ACTION_TAP_DANCE_DOUBLE (KC_Q, KC_ESC)
 };

void matrix_init_user(void) {
};
//static uint8_t ta_state=0;
//static uint16_t kc2 = KC_NO;
void matrix_scan_user(void){
}


uint32_t layer_state_set_user(uint32_t state) {
    uint8_t temp=biton32(state);
    set_ta_layer(temp);
    switch (biton32(state)) {//biton32 returns highest significant bit
    case _BSE:
        clear_mods();
        break;
    case _USD:
        break;
    case _SYB:
        break;
    case _CTL:
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  //return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
} 

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	return true;
}