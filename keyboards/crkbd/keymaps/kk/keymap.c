#include QMK_KEYBOARD_H
#include "bootloader.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

#ifdef OLED_DRIVER_ENABLE
#include "oled_driver.h"
#endif

#include "keymap_german.h"
extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum fnh_layers {
    //US Intl
    _BSE,
    _GAM,
    _SYB,
    //German layout
    _DBS,
    _DSF,
    _DSY,
    //General layers
    _CTL,
    _FUN
};

enum tappers {
    HQT = 0,
    SCBS,
    DTAB,
    QESC,
    
    DSHQ,
    DHQT,
    DSCB,
    DSSC
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

#define MD_DSP LT(_DSF, KC_BSPC)
#define SY_DSP LT(_DSY, KC_SPC)

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BSE] =
LAYOUT( 
    KC_NO, TD(QESC), KC_G, KC_M, KC_L, KC_W, KC_Y, KC_F, KC_U, KC_B, TD(SCBS), KC_NO, \
 KC_NO, KC_D, KC_S, KC_T, KC_N, KC_R, KC_I, KC_A, KC_E, KC_O, TD(HQT), KC_NO, \
 KC_NO, MD_Z, MD_X, MD_C, KC_V, KC_J, KC_K, KC_P, KC_COMM, KC_DOT, KC_SLSH, KC_NO, \
 MO(_CTL), MD_SPC, LK_ENT, KC_ESC, LK_SPC, KC_F13
),
[_SYB] =
LAYOUT( 
    KC_NO, KC_LPRN, KC_RPRN, KC_ASTR, KC_AMPR, KC_GRV, KC_PLUS, KC_7, KC_8, KC_9, KC_0, KC_NO, \
 KC_NO, KC_LBRC, KC_CIRC, KC_PERC, KC_DLR, KC_PIPE, KC_EQL, KC_4, KC_5, KC_6, KC_RBRC, KC_NO, \
 KC_NO, KC_LCBR, KC_HASH, KC_AT, KC_EXLM, KC_TILD, KC_MINS, KC_1, KC_2, KC_3, KC_RCBR, KC_NO, \
  _______, _______, _______,			_______, _______, _______
),
[_GAM] =
LAYOUT( 
    KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,\
 KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_NO,\
 KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,\
 _______, _______, _______,			_______, _______, _______
),
//German layout
[_DBS] =
LAYOUT( 
    KC_NO,  DE_Q  ,  DE_G  ,  DE_M  ,  DE_L  ,  DE_W  ,  DE_Y ,  DE_F  ,  DE_U  ,  DE_B  , TD(DSCB), KC_NO,\
KC_NO,  DE_D  ,  DE_S  ,  DE_T  ,  DE_N  ,  DE_R  ,  DE_I ,  DE_A  ,  DE_E  ,  DE_O  , TD(DHQT), KC_NO,\
KC_NO,  DE_Z  ,  DE_X  ,  DE_C  ,  DE_V  ,  DE_J  ,  DE_K ,  DE_P  ,  DE_COMM  ,  DE_DOT  , DE_SLSH, KC_NO,\
_______, MD_DSP, _______,			_______, SY_DSP, _______

),
//German shifted
[_DSF] =
LAYOUT( 
    KC_NO, _______, _______, _______, _______, _______, 	  _______, _______, _______, _______, TD(DSSC), KC_NO,\
KC_NO,  _______, _______, _______, _______, _______, 	      _______, _______, _______, _______, TD(DSHQ),KC_NO,\
KC_NO, _______, _______, _______, _______, _______,        _______, _______, DE_LESS, DE_MORE, DE_QST, KC_NO,\
 _______, _______, _______,			_______, _______, _______

),
//German symbols
[_DSY] =
LAYOUT( 
    KC_NO, DE_LPRN , DE_RPRN, DE_ASTR, DE_AMPR, DE_GRV,     DE_PLUS ,  DE_7  ,  DE_8  ,  DE_9  ,  DE_0, KC_NO, \
KC_NO,  DE_LBRC , DE_CIRC, DE_PERC, DE_DLR ,DE_PIPE,       DE_EQL  ,  DE_4  ,  DE_5  ,  DE_6  , DE_RBRC, KC_NO,\
KC_NO, DE_LCBR , DE_HASH, DE_AT  , DE_EXLM, DE_TILD,       DE_MINS ,  DE_1  ,  DE_2  ,  DE_3  , DE_RCBR, KC_NO,\
_______, _______, _______,			_______, _______, _______

),

[_CTL] =
LAYOUT( 
    KC_NO, RALT(KC_TAB), KC_NO, KC_NO, KC_NO, DEBUG, LCTL(KC_Y), KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_NO,\
 KC_NO, KC_TAB, LCTL(KC_S), KC_NO, LCTL(KC_F), KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_NO,\
 KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_NO, LCTL(KC_LEFT), KC_BTN3, LCTL(KC_RIGHT), KC_NO, KC_NO, \
 KC_TRNS, KC_LCTL, KC_TRNS, KC_4, KC_LSFT, KC_NO

),
[_FUN] =
LAYOUT( 
    KC_NO, RESET, RGB_SAI, RGB_MOD, RGB_HUI, KC_NO, KC_Y, KC_F7, KC_F8, KC_F9, RESET, KC_NO, \
 KC_NO, KC_A, RGB_SAD, RGB_RMOD, RGB_HUD, KC_NO, KC_H, KC_F4, KC_F5, KC_F6, KC_SCLN, KC_NO, \
 KC_NO, KC_Z, RGB_VAI, RGB_VAD, RGB_TOG, KC_NO, KC_N, KC_F1, KC_F2, KC_F3, KC_SLSH, KC_NO, \
 TG(_DBS), KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO
)
};


//TapDance
bool shifted = false;
void dance_dhqt_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (DE_H);
  } else {
      // shift? ' : "
      if (shifted) {
            register_code(KC_LSFT);
            register_code(DE_2);
      } else{
            register_code(KC_LSFT);
            register_code(DE_HASH);
      }
    }
}

void dance_dhqt_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (DE_H);
  } else {
      // shift? ' : "
      if (shifted) {
            unregister_code(DE_2);
            unregister_code(KC_LSFT);
      } else{
           unregister_code(DE_HASH);
            unregister_code(KC_LSFT);
      }
  }
}

void dance_dssc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
      //shift ? ; : :
      if (shifted) {
            register_code(KC_LSFT);
            register_code(KC_DOT);
        }else{
            register_code(KC_LSFT);
            register_code(KC_COMM);
        }
  } else {
      // shift ? \ : |
      if (shifted) {
            register_code(KC_RALT);
            register_code(DE_LESS);
        }else{
            register_code(KC_RALT);
            register_code(DE_SS);
        }
  }
}

void dance_dssc_reset (qk_tap_dance_state_t *state, void *user_data) {
if (state->count == 1) {
      //shift ? ; : :
      if (shifted) {
            unregister_code(KC_DOT);
            unregister_code(KC_LSFT);
        }else{
            unregister_code(KC_COMM);
            unregister_code(KC_LSFT);
        }
  } else {
      // shift ? \ : |
      if (shifted) {
            unregister_code(DE_LESS);
            unregister_code(KC_RALT);
        }else{
            unregister_code(DE_SS);
            unregister_code(KC_RALT);
        }
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [HQT] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_QUOT),
        [SCBS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_BSLS),
        [DTAB] = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_TAB),
        [QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
        [DHQT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dhqt_finished, dance_dhqt_reset),            // h  '
        [DSHQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dhqt_finished, dance_dhqt_reset),  // H  "
        [DSCB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dssc_finished, dance_dssc_reset),         // ;  /
        [DSSC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dssc_finished, dance_dssc_reset),        // :  |
};


int RGB_current_mode;

void matrix_init_keymap(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef OLED_DRIVER_ENABLE
    oled_init(0);   // turns on the display
#endif //OLED_DRIVER_ENABLE
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef OLED_DRIVER_ENABLE

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(int16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
void add_keylog(int16_t keycode);
void update_log(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   oled_task();
   update_log();
}

void matrix_render_user(void) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);

    //const char keylog_st[4] = {'H','o', '!','\0'};
    //const char *kkts = keylog_st;
    oled_write(read_keylog() , false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    //oled_write(read_keylog() , false);
    //oled_write_P(read_logo(), false);
  }
}

void oled_task_user(void) {
  matrix_render_user();
}
#endif //OLED_DRIVER_ENABLE

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t mods = get_mods();
    uint8_t shift = MOD_BIT(KC_LSFT);
    switch (biton32(state)) {
    
	case _DSF:
        set_mods(mods|shift);
        shifted = true;
        break;
	case _DBS:
	case _DSY:
        set_mods(mods&~shift);
        shifted = false;
		break;
    default:
        shifted = false;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    uint8_t shift = MOD_BIT(KC_LSFT);
    
    if (record->event.pressed) {
        add_keylog(keycode);
        oled_on();
        switch(keycode){
            case DE_LESS:
                //unshift key
                set_mods(mods&~shift);
                return true;
        }
    }
	else{
		switch(keycode) {
			case DE_LESS:
			//reshift
                set_mods(mods|shift);
			return true;
		}
	}

    return true;
}