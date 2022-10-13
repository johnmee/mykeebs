#include QMK_KEYBOARD_H
//#include <stdio.h>


// Keys
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
    WM_RSET = SAFE_RANGE,
    WM_RCTR
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


// WM must be on the left hand (right is on the mouse?)
// Number pad on the right hand
// Need modifiers for letter layer!
// Need modifiers for function keys.
// Use thumbs; but not too much holding down!

// Third mod needs to be a switch? rather than a mod which is held down.

// where to put clt/alt/gui?!?
// where to put media keys?
// Base   = [qwerty + (?, func, wmnum)] & [qwerty + (edit, sym, ?)]
// Edit   = [arrows, pgupdn, space, delete, backspace, enter, shift, ctrl, cut/paste/x/z
// WMNum  = [left, right, center, scratch,   ]  &  [ numpad ]
// Symbol = symbols and unicodes
// Func   = funckeys and media/mods



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base Layer
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  KC_SPC,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(5),   MO(7),      MO(2),   MO(3), KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),

  // Shift layer.
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Editing.
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, KC_LCTL, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_LALT, KC_LCTL, KC_LSFT, _______,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      XXXXXXX,  C_LEFT, XXXXXXX,  C_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  // Symbols.
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_LPRN, KC_ASTR, KC_RPRN, KC_AMPR,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TILDE,X(NDASH), XXXXXXX, XXXXXXX, KC_MINS,  KC_EQL,                      XXXXXXX, KC_LBRC, KC_DQUO, KC_RBRC, KC_SCLN,S(KC_SCLN),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,X(MDASH), XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS,                      XXXXXXX, KC_LCBR, KC_QUOT, KC_RCBR, KC_BSLS, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  // Func.
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, KC_RALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,    KC_1,    KC_2,    KC_3,  KC_DOT, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, XXXXXXX, _______,       KC_0, KC_RSFT, KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),

  // PaperWM Layer
  [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      WM_PGUP, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),WM_SC_TG,                      XXXXXXX, KC_PGUP,  KC_UP,  KC_PGDN, XXXXXXX, KC_MPLY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      WM_PGDN, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT,WM_SC_VW,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, WM_LEFT, WM_CNTR, WM_RCTR, G(KC_R),                      XXXXXXX,  C_LEFT, XXXXXXX,  C_RGHT, XXXXXXX, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

};

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

//orange,rose,violet,azure,springgreen,chartreuse
void rgb_matrix_indicators_user(void) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 1:
                rgb_matrix_set_color_all(RGB_RED);
                break;
            case 2:
                rgb_matrix_set_color_all(RGB_MAGENTA);
                break;
            case 3:
                rgb_matrix_set_color_all(RGB_BLUE);
                break;
            case 5:
                rgb_matrix_set_color_all(RGB_CYAN);
                break;
            default:
                rgb_matrix_set_color_all(RGB_ORANGE);
                break;
        }
}
#endif


// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Auto center window when going right with paperwm.
    case WM_RCTR:
      if (record->event.pressed) {
        tap_code16(G(KC_DOT));
        tap_code16(G(KC_C));
      }
      break;

    // Reset gnome display manager.
    case WM_RSET:
      if (record->event.pressed) {
        tap_code16(A(KC_F2));
        SEND_STRING(SS_DELAY(700) "r" SS_TAP(X_ENT));
      }
      break;

  }
  return true;
};


// Gnome Layer
//  [1] = LAYOUT_split_3x6_3(
//  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______,                      _______, KC_PGUP,  KC_UP,  KC_PGDN, _______, KC_MPLY,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//    G(KC_TAB), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, KC_VOLU,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B),                      _______,  C_LEFT, _______,  C_RGHT, _______, KC_VOLD,
//  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          _______, _______, _______,    _______, _______, _______
//                                      //`--------------------------'  `--------------------------'
//  ),

//#ifdef RGBLIGHT_ENABLE
//// Light LEDs according to keyboard layer active
//const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 12, HSV_ORANGE}
//);
//const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 12, HSV_BLUE}
//);
//
//// Now define the array of layers. Later layers take precedence
//const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//    my_layer0_layer,
//    my_layer1_layer
//);
//
//void keyboard_post_init_user(void) {
//    // Enable the LED layers
//    rgblight_layers = my_rgb_layers;
//}
//
//layer_state_t default_layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
//    return state;
//}
//
//layer_state_t layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
//    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
//    return state;
//}
//#endif

//this is a macro, which goes inside process_record_user
//#ifdef OLED_ENABLE
//  if (record->event.pressed) {
//    set_keylog(keycode, record);
//  }
//#endif

//#ifdef OLED_ENABLE
//oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//  if (!is_keyboard_master()) {
//    return OLED_ROTATION_90;
//  }
//  return rotation;
//}
//
//void oled_render_corne(void) {
//    static const char PROGMEM crkbd_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//        0};
//    oled_write_P(crkbd_logo, false);
//}
//
//static void oled_render_qmk(void) {
//    static const char PROGMEM qmk_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4,
//        0x00};
//    oled_write_P(qmk_logo, false);
//}
//
//void oled_render_layer_state(void) {
//    switch (get_highest_layer(layer_state)) {
//        case 1:
//            oled_render_qmk();
//            break;
//        case 2:
//            oled_write_ln_P(PSTR("Symbols"), false);
//            break;
//        default:
//            oled_render_corne();
//    }
//}
//
//
//bool oled_task_user(void) {
//    oled_render_layer_state();
//    //oled_render_keylog();
//    //oled_render_logo();
//    return true;
//}
//#endif
