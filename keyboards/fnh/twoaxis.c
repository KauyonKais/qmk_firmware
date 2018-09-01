//
// Created by Kauyon Kais on 19.06.2018.
//

#include "twoaxis.h"
#include "report.h"
#include "matrix_share.h"
#include "pointing_device.h"
#include <print.h>
struct ta_axis{
    int8_t x;
    int8_t y;
};
/*
static int8_t absolute(int8_t i){
    uint8_t temp = i >> 7;
    i ^= temp;
    i += temp & 1;
    return i;
}
static void print_val(int8_t val){
    if(val<0)
        print("-");
    val=absolute(val);//10;
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
}*/
static uint8_t dpad_detect(struct ta_axis values){
    /*if(values.x < 60 && values.x > -60 && values.y < 60 && values.y > -60){
        return DPAD_C;
    }*/
    if(values.y > (127-TA_DPAD_CORNER)) {
        if(values.x > (127-TA_DPAD_CORNER))
            return DPAD_UL;
        if(values.x < -(127-TA_DPAD_CORNER))
            return DPAD_UR;
        if(values.y > (127-TA_DPAD_SIDE))
            return DPAD_U;
    }
    if(values.y < -(127-TA_DPAD_CORNER)) {
        if(values.x > (127-TA_DPAD_CORNER))
            return DPAD_DL;
        if(values.x < -(127-TA_DPAD_CORNER))
            return DPAD_DR;
        if(values.x > (127-TA_DPAD_SIDE))
            return DPAD_D;
    }
    if(values.x > (127-TA_DPAD_SIDE)) {
        return DPAD_L;
    }
    if(values.x < -(127-TA_DPAD_SIDE)) {
        return DPAD_R;
    }
    return DPAD_C;
}

static void ta_scroll(struct ta_axis axis) {
    print("I'm a scroll roll\n");
    return;
}
static void ta_mouse( struct ta_axis axis) {
    report_mouse_t currentReport = {};
    currentReport = pointing_device_get_report();
    //shifting and transferring the info to the mouse report variable
    currentReport.x = axis.x / TA_MOUSE_THROTTLE;
    currentReport.y = axis.y / TA_MOUSE_THROTTLE;
//    currentReport.x &= 0b11100000;
//    currentReport.y &= 0b11100000;
    pointing_device_set_report(currentReport);
    pointing_device_send();
    return;
}/*
static void ta_dpad(struct ta_axis axis) {

}*/
static uint8_t ta_mode = TA_NONE;

void ta_setmode(uint8_t mode){
    ta_mode=mode;
}

void twoaxis(int8_t x, int8_t y, uint8_t id){
    if(!(id<TA_INPUTS))
        return;

    if(x < TA_DEADZONE && x > -TA_DEADZONE)
        x=0;
    if(y < TA_DEADZONE && y > -TA_DEADZONE)
        y=0;
    struct ta_axis axis = {x, y};
    //print_val(ta_mode);
    uint8_t row = 0;
    //expected way of things, not how they are rn
    switch(ta_mode){
        case TA_NONE:
            return;
        case TA_MOUSE:
            ta_mouse(axis);
            break;
        case TA_SCROLL:
            ta_scroll(axis);
            break;
        case TA_DPAD:
            row |= dpad_detect(axis);
            matrix[MATRIX_ROWS - TA_INPUTS + id] = row;
            break;
        default:
            return;
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