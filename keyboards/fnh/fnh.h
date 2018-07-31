#ifndef FNH_H
#define FNH_H

// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT( \
    L00, L01, L02, L03, L04,                           R00, R01, R02, R03, R04, R05, R06, R07, \
    L10, L11, L12, L13, L14,                           R10, R11, R12, R13, R14, R15, R16, R17, \ \
    L20, L21, L22, L23, L24,                           R20, R21, R22, R23, R24, R15, R16, R17, \ \
                    L32, L33, L34,                         R30, R31, R32 \
    ) \
    { \
        { L00, L01, L02, L03, L04 }, \
        { L10, L11, L12, L13, L14 }, \
        { L20, L21, L22, L23, L24 }, \
        { KC_NO, KC_NO, L32, L33, L34 }, \
        { R04, R03, R02, R01, R00 }, \
        { R14, R13, R12, R11, R10 }, \
        { R24, R23, R22, R21, R20 }, \
        { KC_NO, KC_NO, R32, R31, R30 } \
    }
#include "quantum.h"

#endif
