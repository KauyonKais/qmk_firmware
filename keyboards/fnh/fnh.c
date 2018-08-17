#include "fnh.h"
#include "twoaxis.h"
#include "pointing_device.h"
#include "report.h"
#include "action.h"
#include "analog.h"
#include <print.h>
/*static void print_val(uint8_t val){
    switch (val/10){
        case 0:
            print("0");
            break;
        case 1:
            print("10");
            break;
        case 2:
            print("20");
            break;
        case 3:
            print("30");
            break;
        case 4:
            print("40");
            break;
        case 5:
            print("50");
            break;
        case 6:
            print("60");
            break;
        case 7:
            print("70");
            break;
        case 8:
            print("80");
            break;
        case 9:
            print("90");
            break;
        case 10:
            print("100");
            break;
        case 11:
            print("110");
            break;
        case 12:
            print("120");
            break;
        case 13:
            print("130");
            break;
        case 14:
            print("140");
            break;
        case 15:
            print("150");
            break;
        case 16:
            print("160");
            break;
        case 17:
            print("170");
            break;
        case 18:
            print("180");
            break;
        case 19:
            print("190");
            break;
        case 20:
            print("200");
            break;
        case 21:
            print("210");
            break;
        case 22:
            print("220");
            break;
        case 23:
            print("230");
            break;
        case 24:
            print("240");
            break;
        case 25:
            print("250");
            break;
        case 26:
            print("260");
            break;
        case 27:
            print("270");
            break;
    }
}*/
static uint8_t deadzone = 2; //adjust as needed
static int8_t readaxis(uint16_t axis){
    int8_t reaxis = (axis >> 2)-128;
    //uint8_t test_val = axis >> 2;
    //print_val(test_val);
    //print("\n");

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
   // x=y;
   // y=x;
//   char temp [5];
//   sprintf(temp, "%i", x);
//   print(temp);
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