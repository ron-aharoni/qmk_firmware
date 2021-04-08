#include QMK_KEYBOARD_H

#define __extern__

#include "action_layer.h"

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
    k40, k41,      k43, k44,      k46,      k48,      k4a,      k4c, k4d, k4e  \
) { \
    { k00,  k01,   k02,   k03,  k04,  k05,   k06,  k07,   k08,  k09,   k0a,  k0b,   k0c,  KC_NO, k0e   }, \
    { k10,  KC_NO, k12,   k13,  k14,  k15,   k16,  k17,   k18,  k19,   k1a,  k1b,   k1c,  k1d,   KC_NO }, \
    { k20,  KC_NO, k22,   k23,  k24,  k25,   k26,  k27,   k28,  k29,   k2a,  k2b,   k2c,  k2d,   KC_NO }, \
    { k30,  k30,   k32,   k33,  k34,  k35,   k36,  k37,   k38,  k39,   k3a,  k3b,   k3c,  k3d,   KC_NO }, \
    { k40,  k41,   KC_NO, k43,  k44,  KC_NO, k46,  KC_NO, k48,  KC_NO, k4a,  KC_NO, k4c,  k4d,   k4e   }  \
}

enum {
    _QWERTY_EXT = 0,
    _QWERTY,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FN
};

enum {
    KC_FN = SAFE_RANGE,
};

#define R_THUMB  LT(_NAV, KC_SPC)
#define L_THUMB  LGUI_T(KC_SPC)
#define SYM(x) LT(_SYM, KC_ ## x)
#define HOMECTL  LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY_EXT] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        HOMECTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   SYM(SCLN),KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,          KC_RSFT,
        KC_FN,   KC_LCTL, KC_LALT,                   L_THUMB, KC_FN,   R_THUMB,                   KC_RGUI, KC_RALT, KC_RCTL, KC_MENU),

    [_QWERTY] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,          KC_RSFT,
        KC_FN,   KC_LCTL, KC_LALT,                   KC_SPC,  KC_FN,   R_THUMB,                   KC_RGUI, KC_RALT, KC_RCTL, KC_MENU),

    [_COLEMAK_DH] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,
        HOMECTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    SYM(O),  KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,          KC_RSFT,
        KC_FN,   KC_LCTL, KC_LALT,                   L_THUMB, KC_FN,   R_THUMB,                   KC_RGUI, KC_RALT, KC_RCTL, KC_MENU),

    [_NAV] = LAYOUT_nadavwr(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, RGB_TOG, RGB_MOD, RGB_VAI, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______,          _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______),

    [_SYM] = LAYOUT_nadavwr(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_LPRN, KC_RPRN, KC_DLR,  _______, _______, KC_UNDS, KC_MINS, KC_EQL,  _______, _______, _______,
        _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______, KC_BSPC, KC_DEL,  KC_QUOT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______),

};

static bool _fn_pressed = false;
#define IF_FN(x) if (_fn_pressed) { x; return false; }; break

#define CODE_HANDLER(x)   record->event.pressed ? register_code(x)   : unregister_code(x)
#define CODE_HANDLER16(x) record->event.pressed ? register_code16(x) : unregister_code16(x)

#define SEND_FN(x) IF_FN(CODE_HANDLER(x))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

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
        case KC_Q:     IF_FN(layer_move(_QWERTY_EXT));
        case KC_A:     IF_FN(layer_move(_QWERTY));
        case KC_Z:     IF_FN(layer_move(_COLEMAK_DH));
    };

    return true;
}
