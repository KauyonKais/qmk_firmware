#include "fnh.h"
#include "analog.h"


#ifndef TA_X_ADJUST
#define TA_X_ADJUST 0
#endif
#ifndef TA_Y_ADJUST
#define TA_Y_ADJUST 20
#endif



void twoaxis_task(void){
//mouseReport.x = 127 max -127 min
    int8_t x = ta_convert_10bit(analogRead(3));
//mouseReport.y = 127 max -127 min
    int8_t y = ta_convert_10bit(analogRead(2));

   twoaxis(-x + TA_X_ADJUST, y + TA_Y_ADJUST, 0);//calls twoaxis entry point, agnostic from here
   //-x because my x is mirrored for some reason. This might depend on the device used
}


#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {

  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4},
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7},
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3},
};
#endif