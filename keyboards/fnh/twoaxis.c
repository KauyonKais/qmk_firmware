//
// Created by Kauyon Kais on 19.06.2018.
//

#include "twoaxis.h"
#include "pointing_device.h"
#include "report.h"
#include "action.h"
#include "analog.h"

#include <print.h>
struct ta_axis{
    int8_t x;
    int8_t y;
};
/*
enum twoaxis_modes{
    ta_mouse,
    ta_scroll,
    ta_dpad,
    ta_number_of_modes //needed as last element, add new ones above
};

static uint8_t twoaxis_mode=0;
void setmode(uint8_t mode){
    if(mode>ta_number_of_modes-1)
        return;
    twoaxis_mode = mode;
}
*/
#define TA_MULT 2
static uint8_t deadzone = 2; //adjust as needed
static int8_t readaxis(uint16_t axis){
    int8_t reaxis = ((axis - 16) >> 5) - 15;
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
    return 0;
    //return reaxis;
}
//uint8_t counter_ax = 0;
static struct ta_axis read_stick_values(void){
//mouseReport.x = 127 max -127 min
    int8_t mx = readaxis(analogRead(3));
    if(mx>127/TA_MULT){
        mx=127;
    }else if (mx < -127/TA_MULT){
        mx=-127;
    }else{
        mx=mx*TA_MULT;
    }
    mx=mx*-1;
    //modify as needed

//mouseReport.y = 127 max -127 min
    int8_t my = readaxis(analogRead(2));
    if(my>127/TA_MULT){
        my=127;
    }else if (my < -127/TA_MULT){
         my=-127;
    }else{
        my=my*TA_MULT;
    }
    //my=my*-1
    //modify as needed
    /*if(counter_ax<20){
        counter_ax=counter_ax+1;
    }else{
        counter_ax=0;
    print("y: ");
        for (int i = 0; i < 8; ++i) {
            if((my >> i)&0x1){
                print("1");
            }else{
                print("0");
            }
        }print("\t");
    print("x: ");
    for (int i = 0; i < 8; ++i) {
        if((mx >> i)&0x1){
            print("1");
        }else{
            print("0");
        }
    }print("\n");*/

    struct ta_axis r = {mx,my};
    return r;
    //TODO add DEF IF for raw/stretched/curved output
    //TODO add DEF IF for mirroring x/y
}

void twoaxis_as_mouse(void){
    struct ta_axis  values = read_stick_values();
    report_mouse_t currentReport = {};
    currentReport = pointing_device_get_report();
    //shifting and transferring the info to the mouse report variable
    currentReport.x=values.x;
    currentReport.y=values.y;
    currentReport.buttons = 0x00;
    pointing_device_set_report(currentReport);
    pointing_device_send();
}

void twoaxis_as_scroll(void){
    struct ta_axis  values = read_stick_values();
    report_mouse_t currentReport = {};
    currentReport = pointing_device_get_report();
    //shifting and transferring the info to the mouse report variable
    currentReport.h=values.x;
    currentReport.v=values.y;
    currentReport.buttons = 0x00;
    pointing_device_set_report(currentReport);
    pointing_device_send();
}

static int8_t absolute(int8_t i){
    uint8_t temp = i >> 7;
    i ^= temp;
    i += temp & 1;
    return i;
}



uint8_t twoaxis_as_dpad(void){
    struct ta_axis  values = read_stick_values();
    if(absolute(values.x)<5 && values.y>5) {
        return DPAD_U;
    }
     if(absolute(values.x)>5 && values.y<-5) {
        return DPAD_D;
    }
    if(values.x<-5 && absolute(values.y)<5) {
        return DPAD_L;
    }
    if(values.x>5 && absolute(values.y)<5) {
        return DPAD_R;
    }
    return  0;
}


static uint8_t joymap[6][4] = {
        {KC_U, KC_L, KC_R, KC_D},
        {},
        {KC_W, KC_A, KC_S, KC_D},
        {},{},{}
};
static uint8_t ta_layer=0;
void set_ta_layer(uint8_t l){
    ta_layer=l;
}

void dpad(void){
    static uint8_t ta_state=0;
    ta_state = twoaxis_as_dpad();
    switch (ta_state){
        case DPAD_U:
            register_code(joymap[ta_layer][0]);
            register_code(joymap[ta_layer][0]);
            break;
        case DPAD_R:
            register_code(joymap[ta_layer][1]);
            register_code(joymap[ta_layer][1]);
            break;
        case DPAD_L:
            register_code(joymap[ta_layer][2]);
            register_code(joymap[ta_layer][2]);
            break;
        case DPAD_D:
            register_code(joymap[ta_layer][3]);
            register_code(joymap[ta_layer][3]);
            break;
        case DPAD_DEAD:
            break;
        default:
            break;
    }
}