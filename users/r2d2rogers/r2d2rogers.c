/*
Copyright 2018 Rob Rogers <r2d2rogers@gmail.com> @r2d2rogers
Copyright 2018 Christopher Courtney <drashna@live.com> @drashna

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

#include "r2d2rogers.h"
#include "rgb_stuff.h"

userspace_config_t userspace_config;

//  Helper Functions


// This block is for all of the gaming macros, as they were all doing
// the same thing, but with differring text sent.
bool send_game_macro(const char *str, keyrecord_t *record, bool override) {
  if (!record->event.pressed || override) {
    uint16_t keycode;
    if (userspace_config.is_overwatch) {
      keycode = KC_BSPC;
    } else {
      keycode = KC_ENTER;
    }
    clear_keyboard();
    tap(keycode);
    wait_ms(50);
    send_string_with_delay(str, MACRO_TIMER);
    wait_ms(50);
    tap(KC_ENTER);
  }
  if (override) wait_ms(3000);
  return false;
}

bool mod_key_press_timer (uint16_t code, uint16_t mod_code, bool pressed) {
  static uint16_t this_timer;
  if(pressed) {
      this_timer= timer_read();
  } else {
      if (timer_elapsed(this_timer) < TAPPING_TERM){
          register_code(code);
          unregister_code(code);
      } else {
          register_code(mod_code);
          register_code(code);
          unregister_code(code);
          unregister_code(mod_code);
      }
  }
  return false;
}

bool mod_key_press (uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer) {
  if(pressed) {
      this_timer= timer_read();
  } else {
      if (timer_elapsed(this_timer) < TAPPING_TERM){
          register_code(code);
          unregister_code(code);
      } else {
          register_code(mod_code);
          register_code(code);
          unregister_code(code);
          unregister_code(mod_code);
      }
  }
  return false;
}

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__ ((weak))
void matrix_init_keymap(void) {}

__attribute__ ((weak))
void startup_keymap(void) {}

__attribute__ ((weak))
void shutdown_keymap(void) {}

__attribute__ ((weak))
void suspend_power_down_keymap(void) {}

__attribute__ ((weak))
void suspend_wakeup_init_keymap(void) {}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}


__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

__attribute__ ((weak))
uint32_t default_layer_state_set_keymap (uint32_t state) {
  return state;
}

__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}



// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
  userspace_config.raw = eeprom_read_byte(EECONFIG_USERSPACE);

#ifdef AUDIO_CLICKY
  clicky_enable = userspace_config.clicky_enable;
#endif

#ifdef BOOTLOADER_CATERINA
  DDRD &= ~(1<<5);
  PORTD &= ~(1<<5);

  DDRB &= ~(1<<0);
  PORTB &= ~(1<<0);
#endif


#if (defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE))
	set_unicode_input_mode(UC_WINC);
#endif //UNICODE_ENABLE
  matrix_init_keymap();
}

void startup_user (void) {
  #ifdef RGBLIGHT_ENABLE
    matrix_init_rgb();
  #endif //RGBLIGHT_ENABLE
  startup_keymap();
}

void shutdown_user (void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(1);
  rgblight_setrgb_red();
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
  rgb_led led;
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    led = g_rgb_leds[i];
    if (led.matrix_co.raw < 0xFF) {
      rgb_matrix_set_color( i, 0xFF, 0x00, 0x00 );
    }
  }
#endif //RGB_MATRIX_ENABLE
  shutdown_keymap();
}

void suspend_power_down_user(void)
{
    suspend_power_down_keymap();
}

void suspend_wakeup_init_user(void)
{
  suspend_wakeup_init_keymap();
  #ifdef KEYBOARD_ergodox_ez
  wait_ms(10);
  #endif
}


// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {
  static bool has_ran_yet;
  if (!has_ran_yet) {
    has_ran_yet = true;
    startup_user();
  }

#ifdef RGBLIGHT_ENABLE
  matrix_scan_rgb();
#endif // RGBLIGHT_ENABLE

  matrix_scan_keymap();
}




// Defines actions tor my global custom keycodes. Defined in r2d2rogers.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
  xprintf("KL: row: %u, column: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif //KEYLOGGER_ENABLE

  switch (keycode) {
  case KC_QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;

  case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
    if (!record->event.pressed) {
#if !defined(KEYBOARD_viterbi)
      uint8_t temp_mod = get_mods();
      uint8_t temp_osm = get_oneshot_mods();
      clear_mods(); clear_oneshot_mods();
#endif
      send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), 10);
      if (temp_mod & MODS_SHIFT_MASK || temp_osm & MODS_SHIFT_MASK ) {
#if defined(__arm__)
        send_string_with_delay_P(PSTR(":dfu-util"), 10);
#elif defined(BOOTLOADER_DFU)
        send_string_with_delay_P(PSTR(":dfu"), 10);
#elif defined(BOOTLOADER_HALFKAY)
        send_string_with_delay_P(PSTR(":teensy"), 10);
#elif defined(BOOTLOADER_CATERINA)
        send_string_with_delay_P(PSTR(":avrdude"), 10);
#endif // bootloader options

      }
      if (temp_mod & MODS_CTRL_MASK || temp_osm & MODS_CTRL_MASK) { send_string_with_delay_P(PSTR(" -j8 --output-sync"), 10);  }
      send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), 10);
      set_mods(temp_mod);

    }
    break;

  case EPRM: // Resets EEPROM
    if (record->event.pressed) {
      eeconfig_init();
      default_layer_set(1UL<<eeconfig_read_default_layer());
      layer_state_set(layer_state);
    }
    return false;
    break;
  case VRSN: // Prints firmware version
    if (record->event.pressed) {
      send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), MACRO_TIMER);
    }
    return false;
    break;

    case USER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYMAP);
    }

#ifdef MACROS_ENABLED
  case KC_SHOV:
    return send_game_macro("Good, Bad, I'm the man with the shovel.", record, false);
#endif // MACROS_ENABLED

  case CLICKY_TOGGLE:
#ifdef AUDIO_CLICKY
    userspace_config.clicky_enable = clicky_enable;
    eeprom_update_byte(EECONFIG_USERSPACE, userspace_config.raw);
#endif
    break;
#ifdef UNICODE_ENABLE
  case UC_FLIP: // (╯°□°)╯ ︵ ┻━┻
    if (record->event.pressed) {
      register_code(KC_RSFT);
      tap(KC_9);
      unregister_code(KC_RSFT);
      process_unicode((0x256F | QK_UNICODE), record); // Arm
      process_unicode((0x00B0 | QK_UNICODE), record); // Eye
      process_unicode((0x25A1 | QK_UNICODE), record); // Mouth
      process_unicode((0x00B0 | QK_UNICODE), record); // Eye
      register_code(KC_RSFT);
      tap(KC_0);
      unregister_code(KC_RSFT);
      process_unicode((0x256F | QK_UNICODE), record); // Arm
      tap(KC_SPC);
      process_unicode((0x0361 | QK_UNICODE), record); // Flippy
      tap(KC_SPC);
      process_unicode((0x253B | QK_UNICODE), record); // Table
      process_unicode((0x2501 | QK_UNICODE), record); // Table
      process_unicode((0x253B | QK_UNICODE), record); // Table
    }
    return false;
    break;
#endif // UNICODE_ENABLE

  }
  return process_record_keymap(keycode, record) &&
#ifdef RGBLIGHT_ENABLE
    process_record_user_rgb(keycode, record) &&
#endif // RGBLIGHT_ENABLE
    process_record_secrets(keycode, record);
}



// Runs state check and changes underglow color and animation
// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef RGBLIGHT_ENABLE
  state = layer_state_set_rgb(state);
#endif // RGBLIGHT_ENABLE
  return layer_state_set_keymap (state);
}


uint32_t default_layer_state_set_kb(uint32_t state) {
  return default_layer_state_set_keymap (state);
}


// Any custom LED code goes here.
// So far, I only have keyboard specific code,
// So nothing goes here.
void led_set_user(uint8_t usb_led) {
  led_set_keymap(usb_led);
}
