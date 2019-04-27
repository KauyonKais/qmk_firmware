#include "r2d2rogers.h"
#include "rgb_stuff.h"
#include "eeprom.h"

extern rgblight_config_t rgblight_config;
extern userspace_config_t userspace_config;

#ifdef RGBLIGHT_ENABLE
void rgblight_sethsv_default_helper(uint8_t index) {
  rgblight_sethsv_at(rgblight_config.hue, rgblight_config.sat, rgblight_config.val, index);
}

//// IS31FL3731 RGB filled matrix, dual board for a total of 72 RGB LEDs
//const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
///* Refer to IS31 manual for these locations
// *   driver
// *   |  R location
// *   |  |      G location
// *   |  |      |      B location
// *   |  |      |      | */
//    {0, C1_3,  C2_3,  C3_3},
//    {0, C1_4,  C2_4,  C3_4},
//    {0, C1_5,  C2_5,  C3_5},
//    {0, C1_6,  C2_6,  C3_6},
//    {0, C1_7,  C2_7,  C3_7},
//    {0, C1_8,  C2_8,  C3_8},
//
//    {0, C4_1,  C5_1,  C6_1},
//    {0, C4_2,  C5_2,  C6_2},
//    {0, C4_3,  C5_3,  C6_3},
//
//    {0, C4_6,  C5_6,  C6_6},
//    {0, C4_7,  C5_7,  C6_7},
//    {0, C4_8,  C5_8,  C6_8},
//
//    {0, C7_1,  C8_1,  C9_1},
//    {0, C7_2,  C8_2,  C9_2},
//    {0, C7_3,  C8_3,  C9_3},
//    {0, C7_4,  C8_4,  C9_4},
//    {0, C7_5,  C8_5,  C9_5},
//    {0, C7_6,  C8_6,  C9_6},
//
//    {0, C1_11,  C2_11,  C3_11},
//    {0, C1_12,  C2_12,  C3_12},
//    {0, C1_13,  C2_13,  C3_13},
//    {0, C1_14,  C2_14,  C3_14},
//    {0, C1_15,  C2_15,  C3_15},
//    {0, C1_16,  C2_16,  C3_16},
//
//    {0, C4_9,  C5_9,  C6_9},
//    {0, C4_10,  C5_10,  C6_10},
//    {0, C4_11,  C5_11,  C6_11},
//
//    {0, C4_14,  C5_14,  C6_14},
//    {0, C4_15,  C5_15,  C6_15},
//    {0, C4_16,  C5_16,  C6_16},
//
//    {0, C7_9,  C8_9,  C9_9},
//    {0, C7_10,  C8_10,  C9_10},
//    {0, C7_11,  C8_11,  C9_11},
//    {0, C7_12,  C8_12,  C9_12},
//    {0, C7_13,  C8_13,  C9_13},
//    {0, C7_14,  C8_14,  C9_14},
//
//    {1, C1_3,  C2_3,  C3_3},
//    {1, C1_4,  C2_4,  C3_4},
//    {1, C1_5,  C2_5,  C3_5},
//    {1, C1_6,  C2_6,  C3_6},
//    {1, C1_7,  C2_7,  C3_7},
//    {1, C1_8,  C2_8,  C3_8},
//
//    {1, C4_1,  C5_1,  C6_1},
//    {1, C4_2,  C5_2,  C6_2},
//    {1, C4_3,  C5_3,  C6_3},
//    {1, C4_6,  C5_6,  C6_6},
//    {1, C4_7,  C5_7,  C6_7},
//    {1, C4_8,  C5_8,  C6_8},
//
//    {1, C7_1,  C8_1,  C9_1},
//    {1, C7_2,  C8_2,  C9_2},
//    {1, C7_3,  C8_3,  C9_3},
//    {1, C7_4,  C8_4,  C9_4},
//    {1, C7_5,  C8_5,  C9_5},
//    {1, C7_6,  C8_6,  C9_6},
//
//    {1, C1_11,  C2_11,  C3_11},
//    {1, C1_12,  C2_12,  C3_12},
//    {1, C1_13,  C2_13,  C3_13},
//    {1, C1_14,  C2_14,  C3_14},
//    {1, C1_15,  C2_15,  C3_15},
//    {1, C1_16,  C2_16,  C3_16},
//
//    {1, C4_9,  C5_9,  C6_9},
//    {1, C4_10,  C5_10,  C6_10},
//    {1, C4_11,  C5_11,  C6_11},
//
//    {1, C4_14,  C5_14,  C6_14},
//    {1, C4_15,  C5_15,  C6_15},
//    {1, C4_16,  C5_16,  C6_16},
//
//    {1, C7_9,  C8_9,  C9_9},
//    {1, C7_10,  C8_10,  C9_10},
//    {1, C7_11,  C8_11,  C9_11},
//    {1, C7_12,  C8_12,  C9_12},
//    {1, C7_13,  C8_13,  C9_13},
//    {1, C7_14,  C8_14,  C9_14},
//};
//
//const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
//
//    /*{row | col << 4}
//      |             {x=0..224, y=0..64}
//      |              |                 modifier
//      |              |                 | */
//    {{0|(0<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(0<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(0<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(0<<4)},   {20.36*3, 21.33*0}, 0},
//    {{4|(0<<4)},   {20.36*4, 21.33*0}, 0},
//    {{5|(0<<4)},   {20.36*5, 21.33*0}, 0},
//
//    {{0|(1<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(1<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(1<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(1<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(1<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(1<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(2<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(2<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(2<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(2<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(2<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(2<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(3<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(3<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(3<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(3<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(3<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(3<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(4<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(4<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(4<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(4<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(4<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(4<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(5<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(5<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(5<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(5<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(5<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(5<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(6<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(6<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(6<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(6<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(6<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(6<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(7<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(7<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(7<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(7<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(7<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(7<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(8<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(8<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(8<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(8<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(8<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(8<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(9<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(9<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(9<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(9<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(9<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(9<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(10<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(10<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(10<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(10<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(10<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(10<<4)},   {20.36*5, 21.33*1}, 0},
//
//    {{0|(11<<4)},   {20.36*0, 21.33*0}, 0},
//    {{1|(11<<4)},   {20.36*1, 21.33*0}, 0},
//    {{2|(11<<4)},   {20.36*2, 21.33*0}, 0},
//    {{3|(11<<4)},   {20.36*3, 21.33*1}, 0},
//    {{4|(11<<4)},   {20.36*4, 21.33*1}, 0},
//    {{5|(11<<4)},   {20.36*5, 21.33*1}, 0}
//
//};

#endif // RGBLIGHT_ENABLE

#ifdef INDICATOR_LIGHTS
uint8_t last_mod;
uint8_t last_led;
uint8_t last_osm;
uint8_t current_mod;
uint8_t current_led;
uint8_t current_osm;


void set_rgb_indicators(uint8_t this_mod, uint8_t this_led, uint8_t this_osm) {
  if (userspace_config.rgb_layer_change && biton32(layer_state) == 0) {
    if (this_mod & MODS_SHIFT_MASK || this_led & (1<<USB_LED_CAPS_LOCK) || this_osm & MODS_SHIFT_MASK) {
      #ifdef SHFT_LED1
        rgblight_sethsv_at(120, 255, 255, SHFT_LED1);
      #endif // SHFT_LED1
      #ifdef SHFT_LED2
        rgblight_sethsv_at(120, 255, 255, SHFT_LED2);
      #endif // SHFT_LED2
    } else {
      #ifdef SHFT_LED1
        rgblight_sethsv_default_helper(SHFT_LED1);
      #endif // SHFT_LED1
      #ifdef SHFT_LED2
        rgblight_sethsv_default_helper(SHFT_LED2);
      #endif // SHFT_LED2
    }
    if (this_mod & MODS_CTRL_MASK || this_osm & MODS_CTRL_MASK) {
      #ifdef CTRL_LED1
        rgblight_sethsv_at(0, 255, 255, CTRL_LED1);
      #endif // CTRL_LED1
      #ifdef CTRL_LED2
        rgblight_sethsv_at(0, 255, 255, CTRL_LED2);
      #endif // CTRL_LED2
    } else {
      #ifdef CTRL_LED1
        rgblight_sethsv_default_helper(CTRL_LED1);
      #endif // CTRL_LED1
      #ifdef CTRL_LED2
        rgblight_sethsv_default_helper(CTRL_LED2);
      #endif // CTRL_LED2
    }
    if (this_mod & MODS_GUI_MASK || this_osm & MODS_GUI_MASK) {
      #ifdef GUI_LED1
        rgblight_sethsv_at(51, 255, 255, GUI_LED1);
      #endif // GUI_LED1
      #ifdef GUI_LED2
        rgblight_sethsv_at(51, 255, 255, GUI_LED2);
      #endif // GUI_LED2
    } else {
      #ifdef GUI_LED1
        rgblight_sethsv_default_helper(GUI_LED1);
      #endif // GUI_LED1
      #ifdef GUI_LED2
        rgblight_sethsv_default_helper(GUI_LED2);
      #endif // GUI_LED2
    }
    if (this_mod & MODS_ALT_MASK || this_osm & MODS_ALT_MASK) {
      #ifdef ALT_LED1
        rgblight_sethsv_at(240, 255, 255, ALT_LED1);
      #endif // ALT_LED1
      #ifdef GUI_LED2
        rgblight_sethsv_at(240, 255, 255, ALT_LED2);
      #endif // GUI_LED2
    } else {
      #ifdef GUI_LED1
        rgblight_sethsv_default_helper(ALT_LED1);
      #endif // GUI_LED1
      #ifdef GUI_LED2
        rgblight_sethsv_default_helper(ALT_LED2);
      #endif // GUI_LED2
    }
  }
}

void matrix_scan_indicator(void) {
  current_mod = get_mods();
  current_led = host_keyboard_leds();
  current_osm = get_oneshot_mods();

  set_rgb_indicators(current_mod, current_led, current_osm);

  last_mod = current_mod;
  last_led = current_led;
  last_osm = current_osm;

}
#endif //INDICATOR_LIGHTS

#ifdef RGBLIGHT_TWINKLE
static rgblight_fadeout lights[RGBLED_NUM];

__attribute__ ((weak))
bool rgblight_twinkle_is_led_used_keymap(uint8_t index) { return false; }

bool rgblight_twinkle_is_led_used(uint8_t index) {
  switch (index) {
#ifdef INDICATOR_LIGHTS
#ifdef SHFT_LED1
    case SHFT_LED1:
      return true;
#endif //SHFT_LED1
#ifdef SHFT_LED2
    case SHFT_LED2:
      return true;
#endif //SHFT_LED2
#ifdef CTRL_LED1
    case CTRL_LED1:
      return true;
#endif //CTRL_LED1
#ifdef CTRL_LED2
    case CTRL_LED2:
      return true;
#endif //CTRL_LED2
#ifdef GUI_LED1
    case GUI_LED1:
      return true;
#endif //GUI_LED1
#ifdef GUI_LED2
    case GUI_LED2:
      return true;
#endif //GUI_LED2
#ifdef ALT_LED1
    case ALT_LED1:
      return true;
#endif //ALT_LED1
#ifdef ALT_LED2
    case ALT_LED2:
      return true;
#endif //ALT_LED2
#endif //INDICATOR_LIGHTS
    default:
    return rgblight_twinkle_is_led_used_keymap(index);
  }
}

void scan_rgblight_fadeout(void) { // Don't effing change this function .... rgblight_sethsv is supppppper intensive
  bool litup = false;
  for (uint8_t light_index = 0 ; light_index < RGBLED_NUM ; ++light_index ) {
    if (lights[light_index].enabled && timer_elapsed(lights[light_index].timer) > 10) {
      rgblight_fadeout *light = &lights[light_index];
      litup = true;

      if (light->life) {
        light->life -= 1;
        if (biton32(layer_state) == 0) {
          sethsv(light->hue + rand() % 0xF, 255, light->life, (LED_TYPE *)&led[light_index]);
        }
        light->timer = timer_read();
      }
      else {
        if (light->enabled && biton32(layer_state) == 0) { rgblight_sethsv_default_helper(light_index); }
        litup = light->enabled = false;
      }
    }
  }
  if (litup && biton32(layer_state) == 0) {
    rgblight_set();
  }
}

void start_rgb_light(void) {

    uint8_t indices[RGBLED_NUM];
    uint8_t indices_count = 0;
    uint8_t min_life = 0xFF;
    uint8_t min_life_index = -1;
    for (uint8_t index = 0 ; index < RGBLED_NUM ; ++index ) {
      if (rgblight_twinkle_is_led_used(index)) { continue; }
      if (lights[index].enabled) {
        if (min_life_index == -1 ||
          lights[index].life < min_life)
        {
          min_life = lights[index].life;
          min_life_index = index;
        }
        continue;
      }

      indices[indices_count] = index;
      ++indices_count;
    }

    uint8_t light_index;
    if (!indices_count) {
        light_index = min_life_index;
    }
    else {
      light_index = indices[rand() % indices_count];
    }

    rgblight_fadeout *light = &lights[light_index];
    light->enabled = true;
    light->timer = timer_read();
    light->life = 0xC0 + rand() % 0x40;

    light->hue = rgblight_config.hue + (rand() % 0xB4) - 0x54;

    rgblight_sethsv_at(light->hue, 255, light->life, light_index);
}
#endif


bool process_record_user_rgb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef RGBLIGHT_TWINKLE
    case KC_A ... KC_SLASH:
    case KC_F1 ... KC_F12:
    case KC_INSERT ... KC_UP:
    case KC_KP_SLASH ... KC_KP_DOT:
    case KC_F13 ... KC_F24:
    case KC_AUDIO_MUTE ... KC_MEDIA_REWIND:
      if (record->event.pressed) { start_rgb_light(); }
      return true; break;
#endif // RGBLIGHT_TWINKLE
  case KC_RGB_T:  // This allows me to use underglow as layer indication, or as normal
#ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      userspace_config.rgb_layer_change ^= 1;
      xprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
      eeprom_update_byte(EECONFIG_USERSPACE, userspace_config.raw);
      if (userspace_config.rgb_layer_change) {
        layer_state_set(layer_state); // This is needed to immediately set the layer color (looks better)
      }
    }
#endif // RGBLIGHT_ENABLE
    return false; break;
#ifdef RGBLIGHT_ENABLE
  case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT: // quantum_keycodes.h L400 for definitions
    if (record->event.pressed) { //This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
      if (userspace_config.rgb_layer_change) {
        userspace_config.rgb_layer_change = false;
        xprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
        eeprom_update_byte(EECONFIG_USERSPACE, userspace_config.raw);
      }
    }
    return true; break;
#endif // RGBLIGHT_ENABLE
  }
    return true;
}



void matrix_init_rgb(void) {
#ifdef INDICATOR_LIGHTS
  current_mod = last_mod = get_mods();
  current_led = last_led = host_keyboard_leds();
  current_osm = last_osm = get_oneshot_mods();
#endif

  if (userspace_config.rgb_layer_change) {
    rgblight_enable_noeeprom();
    switch (biton32(eeconfig_read_default_layer())) {
      case _COLEMAK:
        rgblight_sethsv_noeeprom_magenta(); break;
      case _DVORAK:
        rgblight_sethsv_noeeprom_springgreen(); break;
      case _WORKMAN:
        rgblight_sethsv_noeeprom_goldenrod(); break;
      default:
        rgblight_sethsv_noeeprom_cyan(); break;
    }
  }
}

void matrix_scan_rgb(void) {
#ifdef RGBLIGHT_TWINKLE
  scan_rgblight_fadeout();
#endif // RGBLIGHT_ENABLE

#ifdef INDICATOR_LIGHTS
  matrix_scan_indicator();
#endif

}


uint32_t layer_state_set_rgb(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  if (userspace_config.rgb_layer_change) {
    switch (biton32(state)) {
    case _RAISE:
      rgblight_sethsv_noeeprom_yellow();
      rgblight_mode_noeeprom(5);
      break;
    case _LOWER:
      rgblight_sethsv_noeeprom_green();
      rgblight_mode_noeeprom(5);
      break;
    case _ADJUST:
      rgblight_sethsv_noeeprom_red();
      rgblight_mode_noeeprom(23);
      break;
    default: //  for any other layers, or the default layer
      switch (biton32(default_layer_state)) {
        case _COLEMAK:
          rgblight_sethsv_noeeprom_magenta(); break;
        case _DVORAK:
          rgblight_sethsv_noeeprom_springgreen(); break;
        case _WORKMAN:
          rgblight_sethsv_noeeprom_goldenrod(); break;
        default:
          rgblight_sethsv_noeeprom_cyan(); break;
      }
      //biton32(state) == _MODS ? rgblight_mode_noeeprom(2) : rgblight_mode_noeeprom(1); // if _MODS layer is on, then breath to denote it
      break;
    }
//    layer_state_set_indicator(); // Runs every scan, so need to call this here .... since I can't get it working "right" anyhow
  }
#endif // RGBLIGHT_ENABLE

  return state;
}


