/* Copyright 2019
 *
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
//#include "keymap_steno.h"

#ifndef PROGMEM
#  define PROGMEM
#endif

#define LAYOUT_nadavwr( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33,    K3X,     K3Y,    K38, K39, K3A, K3B  \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B }, \
    { K30, K31, K32, K33, K3X, ___, K3Y, ___, K38, K39, K3A, K3B }  \
}

typedef enum {
    _QWERTY,
    _COLEMAK,
    _NUM,
    _NAV,
    _SYM,
    _FN,
} layer_t;

#define NAV(x)   LT(_NAV, KC_ ## x)
#define GUISPC   LGUI_T(KC_SPC)
#define SYM(x)   LT(_SYM, KC_ ## x)
#define NUM      MO(_NUM)
#define CTLESC   LCTL_T(KC_ESC)
#define FN       MO(_FN)

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
#define HPRTAB     _LH(TAB)
#define QWERTY     TO(_QWERTY)
#define COLEMAK    TO(_COLEMAK)
#define PLOVER     TO(_PLOVER)
#define ______     KC_TRNS
#define ____       KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_nadavwr(
      HPRTAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_BSPC,
      CTLESC,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   SYM(SCLN), KC_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,   KC_ENT,
      NUM, FN, KC_LCTL, KC_LALT,    GUISPC,    NAV(SPC), KC_RSFT, ______, _______,   _______
  ),

  [_COLEMAK] = LAYOUT_nadavwr(
      HPRTAB,  KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
      CTLESC,  KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E,    KC_I,   SYM(O),  KC_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
      NUM, FN, KC_LCTL, KC_LALT,    GUISPC,    NAV(SPC), KC_RSFT, ______, _______, _______
  ),

  [_NUM] = LAYOUT_nadavwr(
      ____, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,    ____,
      ____, ____, ____, ____, ____, ____, ____, KC_4, KC_5, KC_6, SYM(NO), ____,
      ____, ____, ____, ____, ____, ____, KC_0, KC_1, KC_2, KC_3, ____,    ____,
      ____, ____, ____, ____,    ____,       NAV(0),   KC_DOT, ____, ____, ____
  ),

  [_NAV] = LAYOUT_nadavwr(
      _______, _______, _______, _______, KC_AGIN, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______,
      _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,SYM(END), _______,
      _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PAST, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______,
      _______, _______, _______, _______,       _______,       _______,       _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT_nadavwr(
      _______,  KC_GRV, KC_LPRN, KC_RPRN,  KC_DLR, _______, _______, KC_UNDS, KC_MINS,  KC_EQL, _______, _______,
      _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_BSPC,  KC_DEL, KC_QUOT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_COMM,  KC_DOT, _______, _______,
      _______, _______, _______, _______,       _______,       _______,       _______, _______, _______, _______
  ),

  [_FN] = LAYOUT_nadavwr(
      QWERTY,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MUTE,
      COLEMAK, RGB_TOG, RGB_MOD, RGB_M_P, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_VOLU,
      _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_VOLD,
      _______, _______, _______, _______,      _______,       _______,        _______, _______, RESET,   _______
  ),

};

void keyboard_post_init_user() {
  rgblight_disable();
}
