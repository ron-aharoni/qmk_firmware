/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "action_layer.h"
#include "process_auto_shift.h"
#include "common/print.h"

#ifdef STENO_ENABLE
#  include "keymap_steno.h"
#endif

#ifndef PROGMEM
#  define PROGMEM
#endif

#define LAYOUT_nadavwr( \
    k00,  k01,  k02,  k03,  k04,  k05,  k06,  k07,  k08,  k09,  k0a,  k0b,  k0c,  k0d, \
    k10,  k11,  k12,  k13,  k14,  k15,  k16,  k17,  k18,  k19,  k1a,  k1b,  k1c,  k1d, \
    k20,  k21,  k22,  k23,  k24,  k25,  k26,  k27,  k28,  k29,  k2a,  k2b,  k2c,  k2d, \
    k30,  k31,  k32,  k33,  k34,  k35,  k36,  k37,  k38,  k39,  k3a,  k3b,  k3c,  k3d, \
    k40,  k41,  k42,  k43,  k44,  k45,  k46,  k47,  k48,  k49,  k4a,  k4b,  k4c,  k4d  \
) \
{ \
  { k00,  k01,  k02,  k03,  k04,  k05,  k06,  k07,  k08,  k09,  k0a,  k0b,  k0c,  k0d }, \
  { k10,  k11,  k12,  k13,  k14,  k15,  k16,  k17,  k18,  k19,  k1a,  k1b,  k1c,  k1d }, \
  { k20,  k21,  k22,  k23,  k24,  k25,  k26,  k27,  k28,  k29,  k2a,  k2b,  k2c,  k2d }, \
  { k30,  k31,  k32,  k33,  k34,  k35,  k36,  k37,  k38,  k39,  k3a,  k3b,  k3c,  k3d }, \
  { k40,  k41,  k42,  k43,  k44,  k45,  k46,  k47,  k48,  k49,  k4a,  k4b,  k4c,  k4d }  \
}

// Layer shorthand
enum layer_names {
    _QWERTY_EXT,
    _QWERTY,
    _COLEMAK,
#ifdef STENO_ENABLE
    _BOLT,
    _GEMINI,
#else
    _STENO_QWERTY,
#endif
    _NAV,
    _SYM,
    _FN,
};


#ifdef STENO_ENABLE
#  define _STENO _BOLT
#  define STENO_MODE STENO_MODE_BOLT
#else
#  define _STENO _STENO_QWERTY
#endif

enum {
    KC_FN = SAFE_RANGE,
    KC_CUSTOM1,
    KC_CUSTOM2,
};

#define R_THUMB  LT(_NAV, KC_SPC)
#define L_THUMB  LGUI_T(KC_SPC)
#define SYM(x)   LT(_SYM, KC_ ## x)
#define HOMECTL  LCTL_T(KC_ESC)

#define _MT(m, x) MT(m, KC_ ## x)
#define _LS(x) _MT(MOD_LSFT, x)
#define _RS(x) _MT(MOD_RSFT, x)
#define _LA(x) _MT(MOD_LALT, x)
#define _RA(x) _MT(MOD_RALT, x)
#define _LC(x) _MT(MOD_LCTL, x)
#define _RC(x) _MT(MOD_RCTL, x)
#define _LG(x) _MT(MOD_LGUI, x)
#define _RG(x) _MT(MOD_RGUI, x)
#define _LM(x) _MT(MOD_LSFT | MOD_LALT | MOD_LCTL, x)
#define _RM(x) _MT(MOD_RSFT | MOD_RALT | MOD_RCTL, x)
#define _LH(x) _MT(MOD_LSFT | MOD_LALT | MOD_LCTL | MOD_LGUI, x)
#define _RH(x) _MT(MOD_RSFT | MOD_RALT | MOD_RCTL | MOD_RGUI, x)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY_EXT] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        HOMECTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   SYM(SCLN),KC_QUOT, KC_ENT,  KC_CUSTOM1,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_CUSTOM2,
        KC_FN,   KC_LCTL, KC_HYPR, KC_LALT, L_THUMB, L_THUMB, KC_HYPR, R_THUMB, R_THUMB, KC_RGUI, KC_HYPR, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_QWERTY] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_CUSTOM1,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_CUSTOM2,
        KC_FN,   KC_LCTL, KC_HYPR, KC_LALT, KC_SPC,  KC_SPC,  KC_HYPR, R_THUMB, R_THUMB, KC_RGUI, KC_HYPR, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_COLEMAK] = LAYOUT_nadavwr(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        HOMECTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    SYM(O),  KC_QUOT, KC_ENT,  KC_CUSTOM1,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_CUSTOM2,
        KC_FN,   KC_LCTL, KC_HYPR, KC_LALT, L_THUMB, L_THUMB, KC_HYPR, R_THUMB, R_THUMB, KC_RGUI, KC_HYPR, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_NAV] = LAYOUT_nadavwr(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_nadavwr(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_LPRN, KC_RPRN, KC_DLR,  _______, _______, KC_UNDS, KC_MINS, KC_EQL,  _______, _______, _______, _______,
        _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_BSPC, KC_DEL,  KC_QUOT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

#ifdef STENO_ENABLE
    [_GEMINI] = LAYOUT_nadavwr(
        _______, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,  _______,
        _______, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  _______, _______,
        _______, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, STN_A,   STN_A,   STN_O,   STN_E,   STN_U,   STN_U,   _______, _______, _______, _______, _______
    ),

    [_BOLT] = LAYOUT_nadavwr(
        _______, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, _______,
        _______, STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_STR, STN_STR, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  _______, _______,
        _______, STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_STR, STN_STR, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, STN_A,   STN_A,   STN_O,   STN_E,   STN_U,   STN_U,   _______, _______, _______, _______, _______
    ),
#else
    [_STENO_QWERTY] = LAYOUT_nadavwr(
        _______, KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    XXXXXXX, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, XXXXXXX, _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, KC_C,    KC_V,    KC_V,    KC_N,    KC_M,    KC_M,    _______, _______, _______, _______, _______
    ),
#endif

};

static bool _fn_pressed = false;
#define IF_FN(x) if (_fn_pressed) { x; return false; }; break

#define CODE_HANDLER(x)   (record->event.pressed ? register_code(x)   : unregister_code(x))
#define CODE_HANDLER16(x) (record->event.pressed ? register_code16(x) : unregister_code16(x))

#define SEND_FN(x) IF_FN(CODE_HANDLER(x))
#define PLOVER_PREFIX(action)      action(X_E) action(X_R) action(X_F) action(X_V)
#define PLOVER_POSTFIX_ON(action)  action(X_I) action(X_K)
#define PLOVER_POSTFIX_OFF(action) action(X_Y) action(X_U)
#define PLOVER_CHORD_DELAY //SS_DELAY(100)
#define PLOVER_CHORD_ON  PLOVER_PREFIX(SS_DOWN) PLOVER_POSTFIX_ON(SS_DOWN)  PLOVER_CHORD_DELAY PLOVER_POSTFIX_ON(SS_UP)  PLOVER_PREFIX(SS_UP)
#define PLOVER_CHORD_OFF PLOVER_PREFIX(SS_DOWN) PLOVER_POSTFIX_OFF(SS_DOWN) PLOVER_CHORD_DELAY PLOVER_POSTFIX_OFF(SS_UP) PLOVER_PREFIX(SS_UP)

uint32_t layer_state_set_user(uint32_t state) {
    switch(get_highest_layer(state)) {
        case _QWERTY:
        case _STENO:
            autoshift_disable();
            break;
        case _QWERTY_EXT:
        case _COLEMAK:
            autoshift_enable();
    }
    return state;
}

void _set_keymap(uint8_t layer) {
    bool from_steno = layer_state_is(_STENO);
    bool to_steno = (layer == _STENO);
    if      (!from_steno &&  to_steno) SEND_STRING(PLOVER_CHORD_ON);
    else if (from_steno  && !to_steno) SEND_STRING(PLOVER_CHORD_OFF);
    layer_move(layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_FN:       _fn_pressed = record->event.pressed; return false;
        case KC_UP:       SEND_FN(KC_PGUP);
        case KC_DOWN:     SEND_FN(KC_PGDN);
        case KC_LEFT:     SEND_FN(KC_HOME);
        case KC_RGHT:     SEND_FN(KC_END);
        case KC_BSPC:     SEND_FN(KC_DEL);
        case KC_0:        SEND_FN(KC_MUTE);
        case KC_MINS:     SEND_FN(KC_VOLD);
        case KC_EQL:      SEND_FN(KC_VOLU);
        case KC_W:        IF_FN(_set_keymap(_QWERTY));
        case KC_Q:        IF_FN(_set_keymap(_QWERTY_EXT));
        case KC_A:        IF_FN(_set_keymap(_COLEMAK));
        case KC_Z:        IF_FN(_set_keymap(_STENO));
    };

    return true;
}

void matrix_init_user() {
#ifdef STENO_ENABLE
    steno_set_mode(STENO_MODE);
#endif
}

void keyboard_post_init_user() {
    autoshift_enable();
}
