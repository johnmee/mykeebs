#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NUM,
  _RAISE,
  _ADJUST,
  _NAV,
  _GUI,
  _MOUSE,
  _TRAIN,
  _FUNCT
};

#define LT_NUM     LT(_NUM, KC_D)
#define LT_GUI     LT(_GUI, KC_C)
#define RAISE      MO(_RAISE)
#define NUM        MO(_NUM)
#define ADJUST     MO(_ADJUST)
#define NAV        MO(_NAV)
#define GUI        MO(_GUI)
#define FUNCT      MO(_FUNCT)
#define MOUSE      MO(_MOUSE)

// Tap Dance: double tap the left shift key for shift-lock
enum {
  TD_SFT_CAPS = 0
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};
#define SFTLOCK    TD(TD_SFT_CAPS)


enum custom_keycodes {
    WM_LCENTER = SAFE_RANGE,
    WM_RCENTER
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
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_mit(
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,  KC_U,   KC_I,     KC_O,    KC_P,    KC_BSPC,
  KC_TAB,   KC_A,    KC_S,    LT_NUM,  KC_F,    KC_G,     KC_H,  KC_J,   KC_K,     KC_L,    KC_SCLN, KC_ENT,
  SFTLOCK,  KC_Z,    KC_X,    LT_GUI,  KC_V,    KC_B,     KC_N,  KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, SFTLOCK,
  KC_LCTL,  KC_LALT, GUI,     KC_LGUI, NAV,     KC_SPC,          RAISE,  FUNCT,    KC_RGUI, KC_RALT, KC_RCTL
),

[_NUM] = LAYOUT_planck_mit(
  _______, _______, _______,    _______,  _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PAST, _______,
  _______, _______, _______,    _______,  _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
  _______, _______, _______,    _______,  _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_PPLS, _______,
  _______, _______, _______,    _______,  _______, _______,          KC_0,    KC_0,    KC_DOT,  KC_EQL,  _______
),

[_RAISE] = LAYOUT_planck_mit(
  KC_TILD, S(KC_1), S(KC_2), S(KC_3),  S(KC_4),    S(KC_5),  S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
  _______, KC_LCBR, KC_RCBR, KC_UNDS,  KC_MINS,    KC_EQL,   XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, KC_PIPE, _______,
  _______, _______, _______, KC_QUOT,  S(KC_QUOT), KC_PLUS,  XXXXXXX, KC_LBRC, KC_RBRC, _______, KC_BSLS, _______,
  _______, _______, _______, _______, _______,     KC_DEL,            XXXXXXX, _______, _______, _______, _______
),

[_FUNCT] = LAYOUT_planck_mit(
  KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   _______, _______, _______,   _______,  _______, _______, _______,
  KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  _______, _______, _______,   _______,  _______, _______, _______,
  KC_F11,  KC_F12,   _______, _______, _______, _______, _______, _______,   _______,  _______, _______, _______,
  _______, _______,  _______, _______, _______, _______,          _______,   XXXXXXX,  _______, _______, _______
),

[_NAV] = LAYOUT_planck_mit(
 KC_GRV,  C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, KC_PGUP,    KC_UP,   KC_PGDN,    _______,  _______,
 KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, KC_LSFT, _______, KC_HOME, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_END,   _______,
 _______, _______, _______, _______, _______, _______, _______, C(KC_LEFT), _______, C(KC_RGHT), _______,  _______,
 _______, _______, _______, _______, _______, KC_BSPC,          _______,    _______, _______,    _______,  _______
),

[_GUI] = LAYOUT_planck_mit(
 _______,   _______, _______, _______, _______, _______, G(KC_W),    G(KC_O),    G(KC_PGUP), G(KC_I),    G(KC_T),   _______,
 _______,   _______, _______, _______, _______, _______, G(KC_COMM), WM_LCENTER, G(KC_PGDN), WM_RCENTER, G(KC_DOT), _______,
 _______,   KC_LALT, KC_LCTL, XXXXXXX, KC_LSFT, _______, _______,    G(KC_R),    G(KC_C),    G(KC_ESC),  C(KC_ESC), _______,
 _______,   _______, _______, _______, _______, _______,             _______,    _______,    _______,    _______,   _______
),

[_ADJUST] = LAYOUT_planck_mit(
 _______, _______, S(KC_PSCR), G(KC_L),    _______, _______, _______,  TG(_TRAIN),  RGB_HUD,  RGB_SAD, RGB_VAD, _______,
 _______, _______, _______,    _______,    _______, _______, _______,    RGB_MOD,   RGB_HUI,  RGB_SAI, RGB_VAI, _______,
 _______, _______, _______,    _______,    _______, _______, _______,    KC_MPLY,   KC_VOLD,  KC_VOLU, KC_MUTE, _______,
 _______, _______,   RESET,    _______,    _______, _______,             _______,   _______,  _______, _______, _______
),

[_TRAIN] = LAYOUT_planck_mit(
  _______, _______, _______,  _______, _______, _______, _______,    _______,   _______,  _______, _______, _______,
  _______, _______, _______,  KC_D,    _______, _______, _______,    _______,   _______,  _______, _______, _______,
  _______, _______, _______,  KC_C,    KC_V,    _______, _______,    _______,   _______,  _______, _______, _______,
  _______, _______, _______,  _______, _______, _______,             _______,   _______,  _______, _______, _______
),

[_MOUSE] = LAYOUT_planck_mit(
  _______, _______, _______, _______, _______, _______, _______,    KC_WH_U, KC_MS_U,  KC_WH_D, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_WH_L,    KC_MS_L, KC_MS_D,  KC_MS_R, KC_WH_R, _______,
  _______, _______, _______, _______, _______, _______, _______,    KC_BTN1, KC_BTN2,  KC_BTN3, _______, _______,
  _______, _______, _______, _______, _______, _______,             _______, _______,  _______, _______, _______
),

/* Blank
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+-------------+------+------+------+------|------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------|------+------+------+------+------|------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------|------|
* |      |      |      |      |      |             |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[12] = LAYOUT_planck_mit(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
)

};

int led_level = 50;

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _RAISE, _ADJUST);
    return state;
}
