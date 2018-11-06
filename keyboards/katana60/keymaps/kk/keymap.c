/* Copyright 2017 Baris Tosun
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum fnh_layers {
    _BSE,
    _QWY,
    _GAM,
    _SYB,
	
	_DBS,
	_DQW,
	_DSF,
	_DSY,
	
    _CTL,
    _FUN
};


// Windows based definitions.
#define MD_SPC MT(MOD_LSFT, KC_BSPC)
#define MD_DSP LT(LM(_DSF, KC_LSFT), KC_BSPC)
#define MD_Z MT(MOD_LCTL, KC_Z)
#define MD_X MT(MOD_LGUI,KC_X)
#define MD_C MT(MOD_LALT,KC_C)
#define SY_SPC LT(_SYB, KC_SPC)
#define SY_DSP LT(_DSY, KC_SPC)
#define CT_ENT LT(_CTL, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BSE] = LAYOUT( /* CarpalxBase */
  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_GAM),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, TG(_DBS),
  KC_TAB,  KC_Q,    KC_G,    KC_E,    KC_R,    KC_W,    KC_LBRC,          KC_RBRC, KC_Y,    KC_M,    KC_U,    KC_L,    KC_SCLN,    KC_BSLS,
  KC_NO,   KC_D,    KC_S,    KC_T,    KC_F,    KC_A,    KC_HOME,          KC_PGUP, KC_I,    KC_J,    KC_N,    KC_O,    KC_H, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
  KC_LCTL,   KC_LGUI, KC_LALT, CT_ENT,                   MD_SPC, KC_RALT,  SY_SPC,          TG(_QWY),KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
[_QWY] = LAYOUT( /* QwertyBase */
        KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_GAM),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,   KC_LGUI, KC_LALT, KC_ENT,                   KC_TRNS, KC_RALT,  KC_TRNS,          TG(_QWY),KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),
[_SYB] = LAYOUT(/*Symbols and Numbers*/
  _______, _______, _______, _______, _______, _______, _______, RESET,   KC_PSLS, KC_PAST , KC_PMNS, _______, _______, _______, _______,
  _______, KC_LPRN, KC_RPRN, KC_ASTR, KC_AMPR, KC_GRV , RGB_HUI,          RGB_HUD, KC_PLUS ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , _______,
  _______, KC_LBRC, KC_CIRC, KC_PERC, KC_DLR , KC_PIPE, RGB_SAI,          RGB_SAD, KC_EQL  ,  KC_4  ,  KC_5  ,  KC_6  , KC_RBRC, _______,
  _______, KC_LCBR, KC_HASH, KC_AT  , KC_EXLM, KC_TILD, RGB_VAI, _______, RGB_VAD, KC_MINS ,  KC_1  ,  KC_2  ,  KC_3  , KC_RCBR, _______,
  _______, _______, _______, _______,                   _______, _______, _______,           KC_PDOT, KC_PENT, _______, _______, _______
    ),
[_DBS] = LAYOUT( /* GermanCarpalxBase */
  KC_ESC , DE_GRV ,  DE_1  ,  DE_2  ,  DE_3  ,  DE_4  ,  DE_5  , _______,  DE_6  ,  DE_7 ,  DE_8  ,  DE_9  ,  DE_0  , DE_MINS, TG(_DBS),
  KC_TAB ,  DE_Q  ,  DE_G  ,  DE_E  ,  DE_R  ,  DE_W  , DE_LBRC,          DE_RBRC,  DE_Y ,  DE_M  ,  DE_U  ,  DE_L  , DE_SCLN, DE_BSLS ,
  KC_NO  ,  DE_D  ,  DE_S  ,  DE_T  ,  DE_F  ,  DE_A  , KC_HOME,          KC_PGUP,  DE_I ,  DE_J  ,  DE_N  ,  DE_O  ,  DE_H  , DE_QUOT ,
  KC_LSFT,  DE_Z  ,  DE_X  ,  DE_C  ,  DE_V  ,  DE_B  , KC_END , KC_DEL ,  KC_PGDN, DE_K ,  DE_P  , DE_COMM, DE_DOT , DE_SLSH,  KC_NO  ,
  KC_LCTL, KC_LGUI, KC_LALT, KC_ENT,                    MD_DSP , KC_RALT,  SY_DSP,        TG(_DQW), KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT
    ),
[_DQW] = LAYOUT( /* GermanQwertyBase */
  KC_ESC,  DE_GRV,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    TG(_GAM),   DE_6, DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, DE_PLUS,
  KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    KC_LBRC,          KC_RBRC, DE_Y,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
  KC_NO,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    KC_HOME,          KC_PGUP, DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, KC_ENT,
  KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    KC_END,  KC_DEL,  KC_PGDN, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_RSFT,
  KC_LCTL,  KC_LGUI, KC_LALT, KC_ENT,                   KC_TRNS, KC_RALT,  KC_TRNS,         TG(_DQW),KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),
[_DSF] = LAYOUT( /*Shifted Layer for German*/
  _______, _______, DE_EXLM, DE_AT  , DE_HASH, DE_DLR , DE_PERC, _______, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, 	      _______, _______, _______, _______, _______, _______, DE_DQOT,
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_LESS, DE_MORE, DE_QST , _______,
  _______, _______, _______, _______,					_______, _______, _______,			_______, _______, _______, _______, _______
    ),
[_DSY] = LAYOUT(/*German Symbols and Numbers*/
  _______, _______, _______, _______, _______, _______, _______, RESET,   KC_PSLS,   KC_PAST , KC_PMNS, _______, _______, _______, _______,
  _______, DE_LPRN , DE_RPRN, DE_ASTR, DE_AMPR, DE_GRV, _______,          _______,   DE_PLUS ,  DE_7  ,  DE_8  ,  DE_9  ,  DE_0 , _______,
  _______, DE_LBRC , DE_CIRC, DE_PERC, DE_DLR ,DE_PIPE, _______,          _______,   DE_EQL  ,  DE_4  ,  DE_5  ,  DE_6  , DE_RBRC, _______,
  _______,DE_LCBR , DE_HASH, DE_AT  , DE_EXLM, DE_TILD, _______, _______, _______,   DE_MINS ,  DE_1  ,  DE_2  ,  DE_3  , DE_RCBR, _______,
  _______, _______, _______, _______,                   _______, _______, _______,             _______, _______, _______, _______, _______
    ),
[_CTL] = LAYOUT( /*Navigation*/
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,		  _______, _______, KC_PGUP, KC_UP  , KC_PGDN, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,		  _______, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT, KC_END , _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,					_______, _______, _______, 			_______, _______, _______, _______, _______
    ),
[_GAM] = LAYOUT( /* Gaming */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_TRNS    ,KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_BSPC,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,   KC_LCTL, KC_LALT, KC_LALT,                   KC_SPC, KC_ENT,  KC_TRNS,          KC_NO,KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _GAM:
        rgblight_setrgb(20,0,0);
        break;
	case _QWY:
		rgblight_setrgb(0,0,20);
		break;
	case _DBS:
	case _DSF:
	case _DSY:
		rgblight_setrgb(0,40,0);
		break;
	case _DQW:
		rgblight_setrgb(20,40,0);
		break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0,  0, 0);
        break;
    }
  return state;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case KC_NUBS:
				set_mods(get_mods()&(~MOD_BIT(KC_LSFT)));
                //unshift, key
                return false;
        }
	}
	else{
		switch(keycode) {
			case KC_NUBS:
				set_mods(get_mods()|MOD_BIT(KC_LSFT));
			//reshift
			return false;
		}
	}
    
    return true;
};

