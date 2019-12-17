#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MACNAV,
  _MACGUI,
  _GAME,
  _MOUSE,
  _FUNCT
};

#define LT_NAV     LT(_MACNAV, KC_D)
#define LT_GUI     LT(_MACGUI, KC_V)
#define RAISE      MO(_RAISE)
#define LOWER      MO(_LOWER)
#define ADJUST     MO(_ADJUST)
#define NAV        MO(_MACNAV)
#define GUI        MO(_MACGUI)
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_mit(
  KC_ESC,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,  KC_U,   KC_I,     KC_O,    KC_P,    KC_BSPC,
  KC_TAB,   KC_A,     KC_S,    LT_NAV,  KC_F,    KC_G,     KC_H,  KC_J,   KC_K,     KC_L,    KC_SCLN, KC_ENT,
  SFTLOCK,  KC_Z,     KC_X,    KC_C,    LT_GUI,  KC_B,     KC_N,  KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, SFTLOCK,
  KC_LCTL,  MOUSE,    GUI,     KC_LGUI, LOWER,   KC_SPC,          RAISE,  FUNCT,    KC_DOWN, KC_RALT, KC_RCTL
),

[_LOWER] = LAYOUT_planck_mit(
  KC_GRV,  KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,  KC_8,  KC_9,   KC_0,    _______,
  _______, _______, _______,  _______,  _______, _______, _______, KC_4,  KC_5,  KC_6,   KC_MINS, _______,
  _______, _______, _______,  _______,  _______, _______, _______, KC_1,  KC_2,  KC_3,   KC_PLUS, _______,
  _______, _______, _______,  _______, XXXXXXX, KC_BSPC,           KC_0,  KC_0,  KC_DOT, _______, _______
),

[_RAISE] = LAYOUT_planck_mit(
  KC_TILD, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
  _______, KC_PPLS, KC_EQL,  KC_UNDS, KC_MINS, KC_QUOT,    KC_LABK, KC_LPRN, KC_LBRC, KC_LCBR, KC_PIPE, _______,
  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), S(KC_QUOT), KC_RABK, KC_RPRN, KC_RBRC, KC_RCBR, KC_BSLS, _______,
  _______, _______, _______, _______, _______, KC_DEL,              XXXXXXX, _______, _______, _______, _______
),

[_FUNCT] = LAYOUT_planck_mit(
  _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   _______, _______,   _______,  _______, _______, _______,
  _______, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  _______, _______,   _______,  _______, _______, _______,
  _______, KC_F11,  KC_F12,   _______, _______, _______, _______, _______,   _______,  _______, _______, _______,
  _______, _______,  _______, _______, _______, _______,          _______,   XXXXXXX,  _______, _______, _______
),

[_MACNAV] = LAYOUT_planck_mit(
 _______, _______, _______, _______, _______, _______, _______, KC_PGUP,    KC_UP,   KC_PGDN,     _______, _______,
 _______, KC_LGUI, KC_LCTL, XXXXXXX, KC_LSFT, _______, KC_HOME, KC_LEFT,    KC_DOWN, KC_RGHT,     KC_END,  _______,
 _______, _______, _______, _______, _______, _______, _______, A(KC_LEFT), _______, A(KC_RIGHT), _______, _______,
 _______, _______, _______, _______, _______, _______,          _______,    _______, _______,     _______, _______
),

[_MACGUI] = LAYOUT_planck_mit(
 _______, _______, _______,  _______,      _______,  _______,   G(S(KC_F)), G(KC_C),    G(KC_UP),   G(C(KC_ESC)), _______, G(KC_UP),
 _______, _______, _______,  S(G(KC_TAB)), _______,  _______,   _______,    G(KC_LEFT), G(KC_DOWN), G(KC_RGHT),   _______, G(KC_DOWN),
 _______, _______, KC_LCTL,  KC_LSFT,      XXXXXXX,  _______,   _______,    G(KC_I),    G(KC_O),    _______,      _______, _______,
 _______, _______, _______,  _______,      _______,  _______,               _______,    _______,    _______,      _______, _______
),

[_ADJUST] = LAYOUT_planck_mit(
  _______, _______, S(KC_PSCR),  _______, _______, _______, _______,    TG(_GAME), RGB_HUD,  RGB_SAD, RGB_VAD, G(C(KC_Q)),
  _______, _______, _______,     _______, _______, _______, _______,    RGB_MOD,   RGB_HUI,  RGB_SAI, RGB_VAI, _______,
  _______, _______, _______,     _______, _______, _______, _______,    KC_MPLY,   KC_VOLD,  KC_VOLU, KC_MUTE, _______,
  _______, _______,   RESET,     _______, _______, _______,             _______,   _______,  _______, _______, _______
),

[_GAME] = LAYOUT_planck_mit(
  _______, _______, _______,  _______, _______, _______, _______,    _______,   _______,  _______, _______, _______,
  _______, _______, _______,  KC_D,    _______, _______, _______,    _______,   _______,  _______, _______, _______,
  _______, _______, _______,  _______, KC_V,    _______, _______,    _______,   _______,  _______, _______, _______,
  _______, _______, _______,  _______, _______, _______,             _______,   _______,  _______, _______, _______
),

[_MOUSE] = LAYOUT_planck_mit(
  _______, _______, _______, _______, _______, _______, _______,    KC_WH_U, KC_MS_U,  KC_WH_D, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_WH_L,    KC_MS_L, KC_MS_D,  KC_MS_R, KC_WH_R, _______,
  _______, _______, _______, _______, _______, _______, _______,    KC_BTN1, KC_BTN2,  KC_BTN3, _______, _______,
  _______, _______, _______, _______, _______, _______,             _______, _______,  _______, _______, _______
),

[11] = LAYOUT_planck_mit(
 _______, _______, C(KC_LEFT),   KC_UP, C(KC_RGHT), _______, _______, _______, _______,    KC_PGUP, C(KC_PGUP), _______,
 _______, KC_HOME,    KC_LEFT, KC_DOWN,    KC_RGHT,  KC_END, _______, _______, KC_LSFT,    KC_PGDN, C(KC_PGDN), _______,
 _______, _______,    _______, _______,    _______, _______, _______, _______, _______,    _______,    _______, _______,
 _______, _______,    _______, _______,    _______, _______, _______,          _______,    _______,    _______, _______
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
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    switch (get_highest_layer(state)) {
    case _LOWER:
      planck_ez_left_led_level(led_level);
      planck_ez_right_led_level(0);
      break;
    case _RAISE:
      planck_ez_left_led_level(0);
      planck_ez_right_led_level(led_level);
      break;
    case _ADJUST:
      planck_ez_left_led_level(led_level);
      planck_ez_right_led_level(led_level);
      break;
    default: //  for any other layers, or the default layer
      planck_ez_left_led_level(0);
      planck_ez_right_led_level(0);
      break;
    }
  return state;
}
