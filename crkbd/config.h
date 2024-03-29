#pragma once

//#define UNICODE_SELECTED_MODES UC_LNX
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define DIODE_DIRECTION COL2ROW

#define MASTER_LEFT

/* ws2812 RGB LED */
#define RGB_DI_PIN      D3

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 12 // Number of LEDs
    #undef RGBLED_SPLIT
    #define RGBLED_SPLIT { 6, 6 }
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_DEFAULT_HUE  21   // Orange
#endif

#define TAPPING_TERM 175
#define TAPPING_TOGGLE 2
#define RGBLIGHT_LAYERS 8
#define OLED_TIMEOUT 600000  //ten minutes

#ifdef RGB_MATRIX_ENABLE
#define SPLIT_LAYER_STATE_ENABLE yes
#endif
