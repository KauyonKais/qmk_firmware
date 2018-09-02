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
    report_mouse_t currentReport = {};
    currentReport = pointing_device_get_report();
    //shifting and transferring the info to the mouse report variable
    currentReport.h =  axis.x / TA_SCROLL_THROTTLE;
    currentReport.v = -axis.y / TA_SCROLL_THROTTLE;
    pointing_device_set_report(currentReport);
    pointing_device_send();
    return;
}
static void ta_mouse( struct ta_axis axis) {
    report_mouse_t currentReport = {};
    currentReport = pointing_device_get_report();
    //shifting and transferring the info to the mouse report variable
    currentReport.x = axis.x / TA_MOUSE_THROTTLE;
    currentReport.y = axis.y / TA_MOUSE_THROTTLE;
    pointing_device_set_report(currentReport);
    pointing_device_send();
}

static void ta_rotary(struct ta_axis axis){
    return;
}

static uint8_t ta_mode = TA_NONE;

void ta_setmode(uint8_t mode){
    ta_mode=mode;
}

void twoaxis(int8_t x, int8_t y, uint8_t id){
    //To make sure we don't start writing in weird places
    if(!(id<TA_INPUTS))
        return;

    static uint8_t row;
    //
    if(x < TA_DEADZONE && x > -TA_DEADZONE)
        x=0;
    if(y < TA_DEADZONE && y > -TA_DEADZONE)
        y=0;

    struct ta_axis axis = {x, y};
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
            row = 0;
            row |= dpad_detect(axis);
            matrix[MATRIX_ROWS - TA_INPUTS + id] = row;
            break;
        case TA_ROTARY:
            ta_rotary(axis);
        default:
            return;
    }
}
