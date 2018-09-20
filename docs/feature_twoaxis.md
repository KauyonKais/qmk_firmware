## Two axis Input Support

This feature makes it easy to use any two axis input with qmk. This is mostly designed for joysticks, but will support anything that delivers two values.  

### Configuration and Use

Assuming the keyboard is set up for use with a two axis input, it can be turned on by setting `TWOAXIS_ENABLE = yes` in `rules.mk`.

#### Modes

Two axis input currently supports three modes: 
* `TA_MOUSE`, which interprets the input as mouse movement
* `TA_SCROLL`, allowing for horizontal and vertical scrolling
* `TA_DPAD`, which maps the input to a special set of keys in `keymap.c`

To switch modes, `ta_setmode(mode)` is used, where `mode` can be any of the listed modes or `TA_NONE` to ignore any input.  
As the mode will be set to `TA_NONE` as default, something like this is needed to set the mode on boot up:

```c
void matrix_init_user(void) {
    ta_setmode(TA_DPAD);
};
```

The mode can easily be set on layer changer using `layer_state_set_user`:

```c
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case FOO:
        ta_setmode(TA_DPAD);
        break;
    case BAR:
        ta_setmode(TA_MOUSE);
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
} 
```

Or as part of a custom key:

```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FOO:
        if (record->event.pressed) {
            ta_setmode(TA_SCROLL);
        } else {
            ta_setmode(TA_MOUSE);
        }
```

#### Mouse and Scroll behaviour

The mouse and scroll speed can be adjusted by setting `TA_MOUSE_THROTTLE` and `TA_SCROLL_THROTTLE` respectively. A higher value results in a lower speed. Default values are `3` for the mouse and `40` for the scrolling.

#### Hitboxes and Deadzone

A general Deadzone is defined by `#define TA_DEADZONE` with a default of `20`.
There is a hitbox in each corner with a size of `TA_DPAD_CORNER` (default `90`) and a hitbox for each side, which is usually kept smaller, defined by `TA_DPAD_SIDE` with default `70`. All these values have a maximum of `127`.

### For Makers

For a custom keyboard to 