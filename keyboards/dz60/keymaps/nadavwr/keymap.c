#include QMK_KEYBOARD_H

#define __extern__

#include "action_layer.h"
//#include "hypertap.h"

#ifndef PROGMEM
#define PROGMEM
#endif

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c ┊0e     │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │10   ┊12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d ┊     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┘     │
 * │20    ┊22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      ┊
 * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───────┤
 * │30     ┊32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3c │3d     ┊
 * ├────┬──┴─┬─┴──┬┴───┴───┬───┴┬──┴───┴───┼───┼───┼───┼───┬───┤
 * │40  │41  ┊43  │44      ┊46  ┊48        ┊4a │4b │4c │4d │4e │
 * └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
 */

#define LAYOUT_nadavwr( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,      k0e, \
    k10,      k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d,      \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d,      \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d,      \
    k40, k41,      k43, k44,      k46,      k48,      k4a, k4b, k4c, k4d, k4e  \
) { \
    { k00,  k01,   k02,   k03,  k04,  k05,   k06,  k07,   k08,  k09,   k0a,  k0b,  k0c,  KC_NO, k0e   }, \
    { k10,  KC_NO, k12,   k13,  k14,  k15,   k16,  k17,   k18,  k19,   k1a,  k1b,  k1c,  k1d,   KC_NO }, \
    { k20,  KC_NO, k22,   k23,  k24,  k25,   k26,  k27,   k28,  k29,   k2a,  k2b,  k2c,  k2d,   KC_NO }, \
    { k30,  k30,   k32,   k33,  k34,  k35,   k36,  k37,   k38,  k39,   k3a,  k3b,  k3c,  k3d,   KC_NO }, \
    { k40,  k41,   KC_NO, k43,  k44,  KC_NO, k46,  KC_NO, k48,  KC_NO, k4a,  k4b,  k4c,  k4d,   k4e   }  \
}

enum {
    _QWERTY = 0,
    _COLEMAK_DH,
    _LOCK,
    _PINKY,
    _NAV,
    _SYM,
    _FN
};

enum {
    KC_FN = SAFE_RANGE,
};

//enum {
//    HYPERTAP
//} tap_dance_enum;
//
//qk_tap_dance_action_t tap_dance_actions[] = {
//    HYPERTAP_ACTIONS(HYPERTAP)
//};

//#define L_THUMB  TD(HYPERTAP)
#define R_THUMB  LT(_NAV, KC_SPC)
#define L_THUMB  LGUI_T(KC_SPC)
#define LOCK     MO(_LOCK)
#define PINKY(x) LT(_PINKY, KC_ ## x)
#define HOMECTL  LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, PINKY(SCLN),KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,          KC_RSFT,
        KC_FN,   KC_LCTL, KC_LALT,                   KC_SPC,  LOCK,    R_THUMB,          KC_HYPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

    [_COLEMAK_DH] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,   PINKY(O), KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,          KC_RSFT,
        KC_FN,   KC_LCTL, KC_LALT,                   KC_SPC,  LOCK,    R_THUMB,          KC_HYPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

    [_LOCK] = LAYOUT_nadavwr(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        HOMECTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   L_THUMB, _______, _______,          _______, _______, _______, _______, _______),

    [_PINKY] = LAYOUT_nadavwr(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______),

    [_NAV] = LAYOUT_nadavwr(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______),

    [_SYM] = LAYOUT_nadavwr(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_LPRN, KC_RPRN, KC_DLR,  _______, _______, KC_UNDS, KC_MINS, KC_EQL,  _______, _______, _______,
        _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______, KC_BSPC, KC_QUOT, KC_DQT,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_BSLS, _______, _______, _______,          _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______),

    //ASETNIOP_LAYERS

};

size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);

static bool _fn_pressed = false;
#define IF_FN(x) if (_fn_pressed) { x; return false; }; break

#define CODE_HANDLER(x)   record->event.pressed ? register_code(x)   : unregister_code(x)
#define CODE_HANDLER16(x) record->event.pressed ? register_code16(x) : unregister_code16(x)

#define SEND_FN(x) IF_FN(CODE_HANDLER(x))

void _set_keymap(uint8_t layer) {
    bool lock = layer_state_is(_LOCK);
    layer_move(layer);
    if (lock) layer_on(_LOCK);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOCK, _PINKY, _SYM);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    //PROCESS_RECORD_ASETNIOP(_ASETNIOP, keycode, record);

    switch (keycode) {
        case KC_FN:    _fn_pressed = record->event.pressed; return false;
        case KC_UP:    SEND_FN(KC_PGUP);
        case KC_DOWN:  SEND_FN(KC_PGDN);
        case KC_LEFT:  SEND_FN(KC_HOME);
        case KC_RGHT:  SEND_FN(KC_END);
        case KC_BSPC:  SEND_FN(KC_DEL);
        case KC_0:     SEND_FN(KC_MUTE);
        case KC_MINS:  SEND_FN(KC_VOLD);
        case KC_EQL:   SEND_FN(KC_VOLU);
        case KC_Q:     IF_FN(_set_keymap(_QWERTY));
        case KC_A:     IF_FN(_set_keymap(_COLEMAK_DH));
    };

    return true;
}

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;
    backlight_disable();
    rgblight_disable();
}
