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
                                          KC_LALT,   MO(9),   TT(1),     KC_SPC,   MO(2), KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),
  // Navigation Layer
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     WM_SC_VW,WM_SC_TG, WM_LEFT, WM_CNTR, WM_RGHT, G(KC_R),                      XXXXXXX, KC_PGUP,  KC_UP,  KC_PGDN, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,                      XXXXXXX,  C_LEFT, XXXXXXX,  C_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  // Symbols Layer
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TILDE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_LPRN, KC_ASTR, KC_RPRN, KC_AMPR,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,  KC_EQL,                      XXXXXXX, KC_LBRC, KC_DQUO, KC_RBRC, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS,                      XXXXXXX, KC_LCBR, KC_QUOT, KC_RCBR, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MPLY, KC_VOLD, KC_VOLU,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // Function Layer
  [9] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, KC_RALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RALT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_RCTL
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

void rgb_matrix_indicators_user(void) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 1:
                rgb_matrix_set_color_all(RGB_BLUE);
                break;
            case 2:
                rgb_matrix_set_color_all(RGB_AZURE);
                break;
            default:
                rgb_matrix_set_color_all(RGB_ORANGE);
                break;
        }
}
#endif

#ifdef RGBLIGHT_ENABLE
// Light LEDs according to keyboard layer active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    return state;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_90;
  }
  return rotation;
}

void oled_render_corne(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

static void oled_render_qmk(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4,
        0x00};
    oled_write_P(qmk_logo, false);
}

void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case 1:
            oled_render_qmk();
            break;
        case 2:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        default:
            oled_render_corne();
    }
}


bool oled_task_user(void) {
    oled_render_layer_state();
    //oled_render_keylog();
    //oled_render_logo();
    return true;
}
#endif

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//#ifdef OLED_ENABLE
//  if (record->event.pressed) {
//    set_keylog(keycode, record);
//  }
//#endif
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


  // Function Layer... multimedia. lights.
//  [3] = LAYOUT_split_3x6_3(
//  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX, XXXXXXX, WM_RSET,                       KC_F10,   KC_F7,   KC_F8,   KC_F9, KC_RGUI, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_RALT, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//        MO(5), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F12,   KC_F1,   KC_F2,   KC_F3, KC_RCTL, KC_RSFT,
//  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
//                                      //`--------------------------'  `--------------------------'
//  ),
  // PaperWM (left) Numpad (right) Layer
//  [4] = LAYOUT_split_3x6_3(
//  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      KC_LGUI, XXXXXXX,   WM_UP, WM_PGUP, WM_DOWN, WM_FULL,                      XXXXXXX,    KC_7,    KC_8,    KC_9, KC_RGUI, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//    G(KC_TAB), WM_MONL, WM_LEFT, WM_CNTR, WM_RGHT, WM_MONR,                      XXXXXXX,    KC_4,    KC_5,    KC_6, KC_RALT, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//     WM_SC_VW,WM_SC_TG, G(KC_I), WM_PGDN, G(KC_O), G(KC_R),                       KC_DOT,    KC_1,    KC_2,    KC_3, KC_RCTL, KC_RSFT,
//  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          XXXXXXX, XXXXXXX, XXXXXXX,       KC_0,    KC_0,  KC_DOT
//                                      //`--------------------------'  `--------------------------'
//  ),
  // Emoji Layer
//  [5] = LAYOUT_split_3x6_3(
//  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     X(NDASH),X(THUMB),X(SMILE), XXXXXXX, XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     X(MDASH),   X(OK), X(ROFL), X(WINK), XXXXXXX, XXXXXXX,
//  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
//                                      //`--------------------------'  `--------------------------'
//  ),

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
