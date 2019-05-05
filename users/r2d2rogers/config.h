#pragma once


#ifdef AUDIO_ENABLE
//#define AUDIO_CLICKY
#define STARTUP_SONG SONG(MARIO_MUSHROOM)
#define GOODBYE_SONG  SONG(MARIO_GAMEOVER)
#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND), \
                                  SONG(OVERWATCH_THEME) \
                                }

#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.5f
#ifdef RGBLIGHT_ENABLE
#define NO_MUSIC_MODE
#endif //RGBLIGHT_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP

#undef RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_EFFECT_BREATHING // 1972
#define RGBLIGHT_EFFECT_SNAKE // 270
#define RGBLIGHT_EFFECT_KNIGHT // 246
//#define RGBLIGHT_EFFECT_ALTERNATING // 180
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL // 173
//#define RGBLIGHT_EFFECT_RGB_TEST // 132
#define RGBLIGHT_EFFECT_RAINBOW_MOOD // 126
//#define RGBLIGHT_EFFECT_CHRISTMAS // 120
#define RGBLIGHT_EFFECT_STATIC_GRADIENT // 0
#endif // RGBLIGHT_ENABLE



#ifndef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2
#endif // !ONESHOT_TAP_TOGGLE

#ifndef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 3000
#endif// !ONESHOT_TIMEOUT

#ifndef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 4
#endif // !QMK_KEYS_PER_SCAN



// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#undef  PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
// #define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING

#define FORCE_NKRO

#ifndef TAPPING_TOGGLE
#define TAPPING_TOGGLE  1
#endif

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 175


// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define DISABLE_LEADER

#define MACRO_TIMER 5

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

