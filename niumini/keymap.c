#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _L1,
  _L2,
  _L3,
  _R1,
  _R2,
  _ADJUST
};


enum unicode_names {
    MDASH,
    SMILE,
    THUMB
};

const uint32_t PROGMEM unicode_map[] = {
    [MDASH] = 0x2014,
    [SMILE] = 0x1F642,
    [THUMB] = 0x1F44D
};


// Double-tap the left shift key for shift-lock, and brackets/braces for closing.
enum {
  TD_SFT_CAPS = 0,
  TD_BCBR,
  TD_BBRC,
  TD_BPRN,
  TD_BQUOT
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_BPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [TD_BBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [TD_BCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_BQUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, S(KC_QUOT))
};
#define SFTLOCK    TD(TD_SFT_CAPS)
#define TD_PRN     TD(TD_BPRN)
#define TD_BRC     TD(TD_BBRC)
#define TD_CBR     TD(TD_BCBR)
#define TD_QUOT    TD(TD_BQUOT)

#define TAPPING_TOGGLE 2

enum custom_keycodes {
    WM_LCENTER = SAFE_RANGE,
    WM_RCENTER,
    WM_RESET
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Auto center window left for paperwm.
    case WM_LCENTER:
      if (record->event.pressed) {
        tap_code16(G(KC_COMM));
        tap_code16(G(KC_C));
      }
      break;
    // Auto center window right for paperwm.
    case WM_RCENTER:
      if (record->event.pressed) {
        tap_code16(G(KC_DOT));
        tap_code16(G(KC_C));
      }
      break;
    // Reset gnome display manager for paperwm.
    case WM_RESET:
      if (record->event.pressed) {
        tap_code16(A(KC_F2));
        SEND_STRING(SS_DELAY(700) "r" SS_TAP(X_ENT));
      }
      break;
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_mit(
  KC_ESC,   KC_Q,     KC_W,      KC_E,      KC_R,      KC_T,     KC_Y,     KC_U,   KC_I,      KC_O,    KC_P,    KC_BSPC,
  KC_TAB,   KC_A,     KC_S,      KC_D,      KC_F,      KC_G,     KC_H,     KC_J,   KC_K,      KC_L,    KC_SCLN, KC_ENT,
  SFTLOCK,  KC_Z,     KC_X,      KC_C,      KC_V,      KC_B,     KC_N,     KC_M,   KC_COMM,   KC_DOT,  KC_SLSH, SFTLOCK,
  KC_LCTL,  KC_LALT,  TT(_L3), TT(_L2),  TT(_L1),    KC_SPC,            MO(_R1),   MO(_R2),  KC_LGUI,  KC_RALT, KC_RCTL
),

[_L1] = LAYOUT_planck_mit(
  KC_GRV,     C(KC_Z),    C(KC_X),  C(KC_C),    C(KC_V),      XXXXXXX,     _______,   KC_PGUP,    KC_UP,         KC_PGDN,    _______,  _______,
  _______,    KC_LGUI,    KC_LALT,  KC_LCTL,    KC_LSFT,      XXXXXXX,     KC_HOME,   KC_LEFT,    KC_DOWN,       KC_RGHT,    KC_END,   _______,
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______,   C(KC_LEFT), A(S(KC_COMM)), C(KC_RGHT), _______,  _______,
  _______,    _______,    _______,  XXXXXXX,   XXXXXXX,      KC_BSPC,                _______,    _______,       _______,    _______,  _______
),

[_L2] = LAYOUT_planck_mit(
 _______,    _______,   _______,   _______,   _______,          _______,     _______, KC_7,    KC_8,    KC_9,    KC_PAST, _______,
 _______,    _______,   _______,   _______,   _______,          _______,     _______, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
 _______,    _______,   _______,  _______,    _______,          _______,     _______, KC_1,    KC_2,    KC_3,    KC_PPLS, _______,
 _______,    _______,   _______,   _______,   _______,          _______,              KC_0,    KC_0,    KC_DOT,  KC_EQL,  _______
),

[_L3] = LAYOUT_planck_mit(
 _______,    _______,   _______,   _______,   _______,          _______, _______, KC_F7,   KC_F8,  KC_F9, _______, _______,
 _______,    _______,   _______,   _______,   _______,          _______, _______, KC_F4,   KC_F5,  KC_F6, _______, _______,
 _______,    _______,   _______,   _______,   _______,          _______, _______, KC_F1,   KC_F2,  KC_F3, _______, _______,
 _______,    _______,   XXXXXXX,   _______,   _______,          _______,          KC_F10, KC_F11, KC_F12, _______, _______
),

[_R1] = LAYOUT_planck_mit(
  KC_TILD,    S(KC_1),    S(KC_2),    S(KC_3),  S(KC_4),    S(KC_5),  S(KC_6),    S(KC_7),    S(KC_8),     KC_MINS,     KC_PLUS, _______,
  _______,   S(KC_QUOT),  KC_QUOT,    KC_UNDS,  KC_MINS,     KC_EQL,  _______,    X(MDASH),   X(SMILE),    X(THUMB),    KC_PIPE, _______,
  _______,    KC_LPRN,    KC_LBRC,    KC_LCBR,  KC_PLUS,    KC_ASTR,  _______,    _______,    KC_RCBR,     KC_RBRC,     KC_RPRN, KC_BSLS,
 G(C(KC_ESC)), _______,   _______,    _______,  _______,    KC_DEL,               _______,    _______,     _______,     _______, G(S(KC_ESC))
),

[_R2] = LAYOUT_planck_mit(
  _______, _______,  G(KC_R),   G(KC_PGUP), G(S(KC_F)),     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LGUI, WM_LCENTER, G(KC_PGDN), WM_RCENTER,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, A(KC_F12), G(KC_C), C(KC_ESC),          _______, _______, _______, _______, _______, _______, _______,
  _______, _______,  _______,  _______, _______,            _______,          _______, XXXXXXX, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_mit(
 _______,      _______, _______,    _______,  _______, _______, _______,    _______,   RGB_HUD,  RGB_SAD, RGB_VAD, WM_RESET,
 _______,      KC_MPLY, KC_VOLD,    KC_VOLU,  KC_MUTE, _______, _______,    RGB_MOD,   RGB_HUI,  RGB_SAI, RGB_VAI, _______,
 _______,      _______, _______,    _______,  _______, _______, _______,    _______,   _______,  _______, _______, _______,
 _______,      _______,   RESET,    _______,  _______, _______,             _______,   _______,  _______, _______, _______
)

};


// Two layer access to the ADJUST layer.
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _L1, _R1, _ADJUST);
    return state;
}
