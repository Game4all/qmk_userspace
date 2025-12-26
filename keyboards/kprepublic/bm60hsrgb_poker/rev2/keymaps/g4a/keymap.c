#include QMK_KEYBOARD_H

enum keymap_layer {
    keymap_layer_base = 0,
    keymap_layer_function,
    keymap_layer_rgb
}; 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [keymap_layer_base] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT,  MO(keymap_layer_function),  KC_RGUI,       KC_RCTL
    ),
    [keymap_layer_function] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______,
        _______,            KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,
        _______,   _______,   _______,                      MO(keymap_layer_rgb),                              KC_LEFT,   _______,  KC_DOWN,   KC_RIGHT
    ),
    [keymap_layer_rgb] = LAYOUT_60_ansi(
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,   _______,  KC_DEL,
        _______,     RM_TOGG , RM_PREV, RM_NEXT, RM_HUED, RM_HUEU, RM_SATD, RM_SATU, RM_SATD, RM_VALU, RM_SPDU, RM_SPDD, _______, _______,
        _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   _______,   _______,                       _______,                              _______,   _______,  _______,   _______
    ),
};

bool rgb_matrix_indicators_user() {
    // indicator for caps lock.
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(28, 0x00, 0xFF, 0x00);
    } else {
        rgb_matrix_set_color(28, 0xFF, 0x00, 0x00);
    }
    return false;
}