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
static uint8_t twoaxis_as_dpad(struct ta_axis values){//TODO the detection here is shitty
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

static void ta_scroll(struct ta_axis axis) {
    return;
}
static void ta_mouse( struct ta_axis axis) {
    return;
}
static uint8_t last_dpad_state = 0;
static void ta_dpad(struct ta_axis axis) {
    switch (last_dpad_state){
        case 0:
            break;
        case DPAD_U:
            matrix[4] |= ~(1<<6);
            break;
        case DPAD_D:
            matrix[6] |= ~(1<<6);
            break;
        case DPAD_L:
            matrix[5] |= ~(1<<5);
            break;
        case DPAD_R:
            matrix[5] |= ~(1<<0);
            break;
    }
    uint8_t dpad_state = 0;
    dpad_state = twoaxis_as_dpad(axis);
    last_dpad_state = dpad_state;
    switch (dpad_state){
        case 0:
            break;
        case DPAD_U:
            matrix[4] |= (1<<6);
            break;
        case DPAD_D:
            matrix[6] |= (1<<6);
            break;
        case DPAD_L:
            matrix[5] |= (1<<5);
            break;
        case DPAD_R:
            matrix[5] |= (1<<0);
            break;
    }


    return;
}
#define TA_NONE 0
#define TA_MOUSE 2
#define TA_SCROLL 3
void twoaxis(int8_t x, int8_t y){
    struct ta_axis axis = {x, y};

    //expected way of things, not how they are rn
    switch(10){//TODO read from keymap
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