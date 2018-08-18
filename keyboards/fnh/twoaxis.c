//
// Created by Kauyon Kais on 19.06.2018.
//

#include "twoaxis.h"
#include "pointing_device.h"
#include "report.h"
#include "action.h"
#include "analog.h"
#include "matrix_share.h"
#include <print.h>
struct ta_axis{
    int8_t x;
    int8_t y;
};

static uint8_t ta_layer=0;

void set_ta_layer(uint8_t l){
    ta_layer=l;
}

static int8_t absolute(int8_t i){
    uint8_t temp = i >> 7;
    i ^= temp;
    i += temp & 1;
    return i;
}
static void print_val(int8_t val){
    if(val<0)
        print("-");
    val=absolute(val)/10;
    switch (val){
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
    }
}
static uint8_t twoaxis_as_dpad(struct ta_axis values){//TODO the detection here is shitty
    if(values.y > 36) {
        if(values.x > 36)
            return DPAD_UL;
        if(values.x < -36)
            return DPAD_UR;
        return DPAD_U;
    }
    if(values.y < -36) {
        if(values.x > 36)
            return DPAD_DL;
        if(values.x < -36)
            return DPAD_DR;
        return DPAD_D;
    }
    if(values.x > 36) {
        return DPAD_L;
    }
    if(values.x < -36) {
        return DPAD_R;
    }
    return  DPAD_C;
}

static void ta_scroll(struct ta_axis axis) {
    print_val(1); //TODO delet this
    return;
}
static void ta_mouse( struct ta_axis axis) {
    return;
}
static uint8_t count = 0;
static void ta_dpad(struct ta_axis axis) {
    if(count>253){
    print("x: ");
    print_val(axis.x);
    print(" y: ");
    print_val(axis.y);
    print("\n");
    count=0;
    }else{
        count++;
    }
    uint8_t row = 0;
    uint8_t dpad_state = 0;
    dpad_state = twoaxis_as_dpad(axis);
    switch (dpad_state){
        case 0:
            break;
        case DPAD_U:
            row |= 0b01000000;
            break;
        case DPAD_D:
            row |= 0b00000010;
            break;
        case DPAD_L:
            row |= 0b00010000;
            break;
        case DPAD_R:
            row |= 0b00001000;
            break;
    }

    matrix[8] = row;

    return;
}
#define TA_NONE 0
#define TA_MOUSE 2
#define TA_SCROLL 3
void twoaxis(int8_t x, int8_t y, uint8_t id){
    struct ta_axis axis = {x, y};

    //expected way of things, not how they are rn
    switch(10){//TODO figure out how to read ta_state. Extra array?
        case TA_NONE:
            return;
        case TA_MOUSE:
            ta_mouse(axis);
            break;
        case TA_SCROLL:
            ta_scroll(axis);
            break;
        default://Keycode
            ta_dpad(axis);
            break;
    }
}


/*
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
}*/