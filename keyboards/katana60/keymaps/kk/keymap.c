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

enum fnh_layers {
    _BSE,
    _QWY,
    _USD,
    _GAM,
    _SYB,
    _CTL,
    _FUN
};
// Windows based definitions.
#define MD_SPC MT(MOD_LSFT, KC_BSPC)
#define MD_Z MT(MOD_LCTL, KC_Z)
#define MD_X MT(MOD_LGUI,KC_X)
#define MD_C MT(MOD_LALT,KC_C)
#define LK_SPC LT(_SYB, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BSE] = LAYOUT( /* Base */
  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_GAM),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,
  KC_TAB,  KC_Q,    KC_G,    KC_E,    KC_R,    KC_W,    KC_LBRC,          KC_RBRC, KC_Y,    KC_M,    KC_U,    KC_L,    KC_SCLN,    KC_BSLS,
  KC_NO,   KC_D,    KC_S,    KC_T,    KC_F,    KC_A,    KC_HOME,          KC_PGUP, KC_I,    KC_J,    KC_N,    KC_O,    KC_H, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
  KC_LCTL,   KC_LGUI, KC_LALT, KC_ENT,                   MD_SPC, KC_RALT,  LK_SPC,          TG(_QWY),KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
[_QWY] = LAYOUT( /* Base */
        KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_GAM),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_DEL,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,   KC_LGUI, KC_LALT, KC_ENT,                   KC_TRNS, KC_RALT,  KC_TRNS,          TG(_QWY),KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),
[_SYB] = LAYOUT(
  _______, RGB_TOG, RGB_MOD, RGB_TOG, _______, _______, _______, RESET,   KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______,
  _______, KC_LPRN , KC_RPRN, KC_ASTR, KC_AMPR, KC_GRV, RGB_HUI,          RGB_HUD,   KC_PLUS ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0 , _______,
  _______, KC_LBRC , KC_CIRC, KC_PERC, KC_DLR ,KC_PIPE, RGB_SAI,          RGB_SAD,    KC_EQL  ,  KC_4  ,  KC_5  ,  KC_6 , KC_RBRC, _______,
  _______,KC_LCBR , KC_HASH, KC_AT  , KC_EXLM, KC_TILD, RGB_VAI, _______, RGB_VAD,    KC_MINS ,  KC_1  ,  KC_2  ,  KC_3 , KC_RCBR, _______,
  _______, _______, _______, _______,                   _______, _______, _______,            KC_PDOT, KC_PENT, _______, _______, _______
    ),
[_GAM] = LAYOUT( /* Base */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_TRNS    ,KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,          KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_BSPC,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,   KC_LCTL, KC_LALT, KC_LALT,                   KC_SPC, KC_ENT,  KC_TRNS,          KC_NO,KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),
};

