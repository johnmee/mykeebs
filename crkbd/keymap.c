/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include <stdio.h>

// Keys
#define SPC_CTL LCTL_T(KC_SPC)  // tap space, hold ctrl
#define SPC_SFT RSFT_T(KC_SPC)  // tap space, hold shift
#define SFT_ENT RSFT_T(KC_ENT)  // tap enter, hold shift
#define C_RGHT  C(KC_RGHT)      // control(word) right
#define C_LEFT  C(KC_LEFT)      // control(word) left
#define C_CUT   C(KC_X)
#define C_PSTE  C(KC_V)
#define C_COPY  C(KC_C)
#define C_UNDO  C(KC_Z)

// Window Manager (Gnome PaperWM)
#define WM_LEFT  G(KC_LEFT)
#define WM_MONL  G(S(KC_LEFT))
#define WM_RGHT  G(KC_RGHT)
#define WM_MONR  G(S(KC_RGHT))
#define WM_UP    G(KC_UP)
#define WM_DOWN  G(KC_DOWN)
#define WM_PGUP  G(KC_PGUP)
#define WM_PGDN  G(KC_PGDN)
#define WM_CNTR  G(KC_C)
#define WM_FULL  G(S(KC_F))     // Full screen
#define WM_VIEW  G(KC_TAB)
#define WM_SC_VW G(S(KC_ESC))   // Scratch View
#define WM_SC_TG G(C(KC_ESC))   // Scratch Toggle

enum custom_keycodes {
    WM_RSET = SAFE_RANGE
};

enum unicode_names {
    MDASH, NDASH, SMILE, THUMB, ROFL, WINK, OK
};
const uint32_t PROGMEM unicode_map[] = {
    [MDASH] = 0x2014,
    [NDASH] = 0x2013,
    [SMILE] = 0x1F642,
    [ROFL] = 0x1F923,
    [THUMB] = 0x1F44D,
    [WINK] = 0x1F609,
    [OK] = 0x1F44C
};

//  // New Layer
//  [99] = LAYOUT_split_3x6_3(
//  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
//                                      //`--------------------------'  `--------------------------'
//  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base Layer
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(3),   MO(2),   MO(1),     KC_SPC,   MO(1), KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),
  // Editing. Needs mods.
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_HOME,  C_LEFT,   KC_UP,  C_RGHT,  KC_END,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  C_UNDO,   C_CUT,  C_COPY,  C_PSTE, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),
  // PaperWM and numpad.
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     WM_SC_VW,WM_SC_TG,   WM_UP, WM_PGUP, WM_DOWN, WM_FULL,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, WM_MONL, WM_LEFT, WM_PGDN, WM_RGHT, WM_MONR,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, XXXXXXX, G(KC_I), WM_CNTR, G(KC_O), G(KC_R),                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),
  // Symbols.
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TILDE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  C_UNDO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRAVE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_EQL, KC_UNDS, KC_DQUO, KC_LBRC, KC_RBRC, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS, KC_MINS, KC_QUOT, KC_LCBR, KC_RCBR, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
//  // "Adjust" Layer... multimedia? lights?
//  [4] = LAYOUT_split_3x6_3(
//  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WM_RSET,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     X(NDASH),X(THUMB),X(SMILE), XXXXXXX, XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     X(MDASH),   X(OK), X(ROFL), X(WINK), XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          _______, _______, _______,    XXXXXXX, XXXXXXX, XXXXXXX
//                                      //`--------------------------'  `--------------------------'
//  )
};


// OLED Displays
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

//#define L_BASE 0
//#define L_EDIT 1
//#define L_SYMB 2
//#define L_DESK 3
//#define L_ADJUST 9
//
//void oled_render_layer_state(void) {
//    oled_write_P(PSTR("Layer: "), false);
//    switch (layer_state) {
//        case L_BASE:
//            oled_write_ln_P(PSTR("Default"), false);
//            break;
//        case L_EDIT:
//            oled_write_ln_P(PSTR("Editing"), false);
//            break;
//        case L_SYMB:
//            oled_write_ln_P(PSTR("Symbols"), false);
//            break;
//        case L_DESK:
//            oled_write_ln_P(PSTR("Desktop"), false);
//            break;
//        case L_ADJUST:
//        case L_ADJUST|L_EDIT:
//        case L_ADJUST|L_DESK:
//        case L_ADJUST|L_EDIT|L_DESK:
//            oled_write_ln_P(PSTR("Adjust"), false);
//            break;
//    }
//}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
//        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}
#endif

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
#endif
  switch (keycode) {
    // Reset gnome display manager for paperwm.
    case WM_RSET:
      if (record->event.pressed) {
        tap_code16(A(KC_F2));
        SEND_STRING(SS_DELAY(700) "r" SS_TAP(X_ENT));
      }
      break;
  }
  return true;
};
