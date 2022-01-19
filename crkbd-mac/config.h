#pragma once

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define DIODE_DIRECTION COL2ROW

#define MASTER_LEFT

/* ws2812 RGB LED */
#define RGB_DI_PIN      D3

#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 12 // Number of LEDs
#    define RGBLED_SPLIT { 6, 6 }
#    define RGBLIGHT_SPLIT
#endif
