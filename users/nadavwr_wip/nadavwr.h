#ifndef __NADAVWR_H_
#define __NADAVWR_H_

// #define NADAVWR_LAYOUT 40 or 60
#if NADAVWR_LAYOUT == 40 || NADAVWR_LAYOUT == 60
#error "NADAVWR_LAYOUT should be either 40 or 60"
#endif

#if NADAVWR_LAYOUT == 40 && defined STENO_ENABLE
#define NADAVWR_STENO
#endif

typedef enum {
_QWERTY_EXT,
_QWERTY,
_COLEMAK,
_NAV,
_SYM,
_FN,
#ifdef NADAVWR_STENO
_PLOVER,
#endif
#if NADAVWR_LAYOUT == 40
_NUM,
#endif
} nadavwr_layer_t;

#define NAVSPC      LT(_NAV, KC_SPC)
#define GUISPC      LGUI_T(KC_SPC)
#define SYM(x)      LT(_SYM, KC_ ## x)
#define CTLESC      LCTL_T(KC_ESC)
#define FN          MO(_FN)
#define QWERTY      TO(_QWERTY)
#define QWERTY_EXT  TO(_QWERTY_EXT)
#define COLEMAK     TO(_COLEMAK)
#ifdef NADAVWR_STENO
#define PLOVER      TO(_PLOVER)
#endif
#if NADAVWR_LAYOUT == 40
#define NUM         MO(_NUM)
#endif
#define ____          _______
#define ______        _______

#if NADAVWR_LAYOUT == 60
#define NADAVWR_R0    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC
#define QWERTY_R1     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS
#define QWERTY_R2     CTLESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SYM(KC_SCLN), KC_QUOT, KC_ENT
#define QWERTY_R3    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH
#define COLEMAK_R1    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS
#define COLEMAK_R2    CTLESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, SYM(O), KC_QUOT, KC_ENT
#define COLEMAK_R3   KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLSH
#define NAV_R0       _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______
#define NAV_R1       _______, ____, ____, ____, ____, ____, ____, KC_HOME, KC_UP, KC_END, ____, ____, ____, ____
#define NAV_R2       _______, ____, ____, ____, ____, ____, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, ____, ____
#define NAV_R3       _______, ____, ____, ____, ____, ____, ____, ____, KC_PGUP, KC_PGDN, ____
#define SYM_R1       _______, KC_GRV, KC_LPRN, KC_RPRN, KC_DLR, ____, ____, KC_UNDS, KC_MINS, KC_EQL, ____, ____, ____, ____
#define SYM_R2       _______, ______, KC_LBRC, KC_RBRC, ______, ____, ____, KC_BSPC, KC_DEL, KC_QUOT, ____, ____, ____
#define SYM_R3       _______, ____, ____, ____, ____, ____, ____, KC_BSLS, ____, ____, ____
#elif NADAVWR_LAYOUT == 40
#define QWERTY_R1     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC
#define QWERTY_R2     CTLESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SYM(KC_SCLN), KC_QUOT
#define QWERTY_R3    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_ENT
#define COLEMAK_R1    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC
#define COLEMAK_R2    CTLESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, SYM(O), KC_QUOT
#define COLEMAK_R3   KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLSH, KC_ENT
#define NAV_R1       _______, ____, ____, ____, ____, ____, ____, KC_HOME, KC_UP, KC_END, ____, ____
#define NAV_R2       _______, ____, ____, ____, ____, ____, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, ____
#define NAV_R3       _______, ____, ____, ____, ____, ____, ____, ____, KC_PGUP, KC_PGDN, ____, ____
#define SYM_R1       _______, KC_GRV, KC_LPRN, KC_RPRN, KC_DLR, ____, ____, KC_UNDS, KC_MINS, KC_EQL, ____, ____
#define SYM_R2       _______, ______, KC_LBRC, KC_RBRC, ______, ____, ____, KC_BSPC, KC_DEL, KC_QUOT, ____, ____
#define SYM_R3       _______, ____, ____, ____, ____, ____, ____, KC_BSLS, ____, ____, ____, ____
#define NUM_R1,      _______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC
#define NUM_R2,      _______, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SYM(KC_SCLN), KC_QUOT
#define NUM_R3,      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_ENT
#endif

#ifdef NADAVWR_STENO
#define PLOVER_R1 _______, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5, STN_N6, STN_N7, STN_N8, STN_N9, STN_NA, STN_NB
#define PLOVER_R2 _______, STN_S1, STN_TL, STN_PL, STN_HL, STN_STR, STN_STR, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR
#define PLOVER_R3 _______, STN_S2, STN_KL, STN_WL, STN_RL, STN_STR, STN_STR, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR
#define PLOVER_THUMBS STN_A, STN_O, STN_E, STN_U
#endif


#endif // __NADAVWR_H_
