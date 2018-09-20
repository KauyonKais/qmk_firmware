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
    _CTL,
    _FUN
};
// Windows based definitions.
#define MD_SPC MT(MOD_LSFT, KC_BSPC)
#define MD_Z MT(MOD_LCTL, DE_Z)
#define MD_X MT(MOD_LGUI,DE_X)
#define MD_C MT(MOD_LALT,DE_C)
#define LK_SPC LT(_SYB, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BSE] = LAYOUT( /* Base */
  KC_ESC,  DE_GRV,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    TG(_GAM),   DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, TG(_CAR),
  KC_TAB,  DE_Q,    DE_G,    DE_E,    DE_R,    DE_W,    DE_LBRC,          DE_RBRC, DE_Y,    DE_M,    DE_U,    DE_L,    DE_SCLN,    DE_BSLS,
  KC_NO,   DE_D,    DE_S,    DE_T,    DE_F,    DE_A,    KC_HOME,          KC_PGUP, DE_I,    DE_J,    DE_N,    DE_O,    DE_H, DE_QUOT,
  KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    KC_END,  KC_DEL,  KC_PGDN, DE_K,    DE_P,    DE_COMM, DE_DOT,  DE_SLSH, KC_NO,
  KC_LCTL,   KC_LGUI, KC_LALT, KC_ENT,                   MD_SPC, KC_RALT,  LK_SPC,          TG(_QWY),KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
[_QWY] = LAYOUT( /* Base */
        KC_ESC,  DE_GRV,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    TG(_GAM),   DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, DE_PLUS,
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    KC_LBRC,          KC_RBRC, DE_Y,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
        KC_NO,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    KC_HOME,          KC_PGUP, DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, KC_ENT,
        KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    KC_END,  KC_DEL,  KC_PGDN, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_RSFT,
        KC_LCTL,  KC_LGUI, KC_LALT, KC_ENT,                   KC_TRNS, KC_RALT,  KC_TRNS,          TG(_QWY),KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),
[_SYB] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, RESET,   KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______,
  _______, DE_LPRN , DE_RPRN, DE_ASTR, DE_AMPR, DE_GRV, _______,          _______,   DE_PLUS ,  DE_7  ,  DE_8  ,  DE_9  ,  DE_0 , _______,
  _______, DE_LBRC , DE_CIRC, DE_PERC, DE_DLR ,DE_PIPE, _______,          _______,    DE_EQL  ,  DE_4  ,  DE_5  ,  DE_6 , DE_RBRC, _______,
  _______,DE_LCBR , DE_HASH, DE_AT  , DE_EXLM, DE_TILD, _______, _______, _______,    DE_MINS ,  DE_1  ,  DE_2  ,  DE_3 , DE_RCBR, _______,
  _______, _______, _______, _______,                   _______, _______, _______,            _______, _______, _______, _______, _______
    ),
[_GAM] = LAYOUT( /* Base */
        KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    KC_TRNS    ,DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, DE_PLUS,KC_NO,
        KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_LBRC,          DE_RBRC, DE_Y,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
        KC_LSFT,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    KC_HOME,          KC_PGUP, DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, KC_ENT,
        KC_CAPS, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    KC_END,  KC_BSPC,  KC_PGDN, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_RSFT,
        KC_LCTL,   KC_LCTL, KC_LALT, KC_LALT,                   KC_SPC, KC_ENT,  KC_TRNS,          KC_NO,KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),
};

