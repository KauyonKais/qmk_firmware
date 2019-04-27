#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#ifdef OLED_DRIVER_ENABLE
  #include "oled_driver.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

 enum fnh_layers {
    _BSE,
    _OLD,
    _USD,
    _GAM,
    _SYB,
    _CTL,
    _FUN
};
enum custom_keycodes {
    QWERTY = SAFE_RANGE
};

enum tappers {
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

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BSE] =
LAYOUT( \
    KC_NO,TD(QESC), KC_G, KC_M, KC_L, KC_W, KC_Y, KC_F, KC_U, KC_B, TD(SCBS),KC_NO, \
 KC_NO,KC_D, KC_S, KC_T, KC_N, KC_R, KC_I, KC_A, KC_E, KC_O, TD(HQT),KC_NO, \
 KC_NO,MD_Z, MD_X, MD_C, KC_V, KC_J, KC_K, KC_P, KC_COMM, KC_DOT, KC_SLSH,KC_NO, \
 MO(_CTL), MD_SPC, LK_ENT, KC_ESC, LK_SPC, KC_NO
),
[_OLD] =
LAYOUT( \
    KC_NO,TD(QESC), KC_G, KC_E, KC_R, KC_W, KC_Y, KC_M, KC_U, KC_L, TD(SCBS),KC_NO, \
 KC_NO,KC_D, KC_S, KC_T, KC_F, KC_A, KC_I, KC_J, KC_N, KC_O, TD(HQT),KC_NO, \
 KC_NO,MD_Z, MD_X, MD_C, KC_V, KC_B, KC_K, KC_P, KC_COMM, KC_DOT, KC_SLSH,KC_NO, \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_SYB] =
LAYOUT( \
    KC_NO,KC_LPRN, KC_RPRN, KC_ASTR, KC_AMPR, KC_GRV, KC_PLUS, KC_7, KC_8, KC_9, KC_0,KC_NO, \
 KC_NO,KC_LBRC, KC_CIRC, KC_PERC, KC_DLR, KC_PIPE, KC_EQL, KC_4, KC_5, KC_6, KC_RBRC,KC_NO, \
 KC_NO,KC_LCBR, KC_HASH, KC_AT, KC_EXLM, KC_TILD, KC_MINS, KC_1, KC_2, KC_3, KC_RCBR,KC_NO, \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_TRNS, KC_NO
),
[_GAM] =
LAYOUT( \
    KC_NO,KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,\
 KC_NO,KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,KC_NO, \
 KC_NO,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,KC_NO, \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_TRNS, KC_NO
),
[_CTL] =

LAYOUT( \
    KC_NO,RALT(KC_TAB), KC_NO, KC_NO, KC_NO, DEBUG, LCTL(KC_Y), KC_PGUP, KC_UP, KC_PGDN, KC_NO,KC_NO, \
 KC_NO,KC_TAB, LCTL(KC_S), KC_NO, LCTL(KC_F), KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,KC_NO, \
 KC_NO,LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_NO, KC_BTN1, KC_BTN3, KC_BTN2, KC_NO, KC_NO,\
 KC_TRNS, KC_LCTL, KC_TRNS, KC_4, KC_LSFT, KC_NO

),
[_FUN] =
LAYOUT( \
    KC_NO,RESET, RGB_SAI, RGB_MOD, RGB_HUI, KC_NO, KC_Y, KC_F7, KC_F8, KC_F9, TG(_OLD),KC_NO, \
KC_NO, KC_A, RGB_SAD, RGB_RMOD, RGB_HUD, KC_NO, KC_H, KC_F4, KC_F5, KC_F6, KC_SCLN, KC_NO,\
 KC_NO,KC_Z, RGB_VAI, RGB_VAD, RGB_TOG, KC_NO, KC_N, KC_F1, KC_F2, KC_F3, KC_SLSH,KC_NO, \
 KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_TRNS, KC_NO
)
};


//TapDance

qk_tap_dance_action_t tap_dance_actions[] = {
        [HQT] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_QUOT),
        [SCBS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_BSLS),
        [DTAB] = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_TAB),
        [QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};


int RGB_current_mode;

void matrix_init_keymap(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef OLED_DRIVER_ENABLE
        oled_init(!has_usb());   // turns on the display
    #endif //OLED_DRIVER_ENABLE
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef OLED_DRIVER_ENABLE

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_keymap(void) {
   oled_task();
}

void matrix_render_user(void) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}

void oled_task_user(void) {
  matrix_render_user();
}
#endif //OLED_DRIVER_ENABLE

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
    oled_on();
#endif //OLED_DRIVER_ENABLE
    // set_timelog();
  }

  return true;
}