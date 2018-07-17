#include "fnh.h"
#include "twoaxis.h"
#include "pointing_device.h"
#include "report.h"
#include "action.h"
#include "analog.h"
#include <print.h>

static uint8_t deadzone = 2; //adjust as needed
static int8_t readaxis(uint16_t axis){
    int8_t reaxis = ((axis) >> 5);
    if(reaxis < 0){
        if(reaxis < - deadzone ){
            return reaxis + deadzone;
        }else{
            return 0;
        }
    }else if(reaxis > 0){
        if(reaxis > deadzone ){
            return reaxis - deadzone;
        }else{
            return 0;
        }
    }
    //return 0;
    return reaxis;
}
static void read_stick_values(void){
//mouseReport.x = 127 max -127 min
    int8_t x = readaxis(analogRead(3));
//mouseReport.y = 127 max -127 min
    int8_t y = readaxis(analogRead(2));
    twoaxis(x, y);//calls twoaxis entry point, agnostic from here
}
void pointing_device_task(void){
    read_stick_values();
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