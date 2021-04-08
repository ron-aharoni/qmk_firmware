#ifndef __HYPERTAP_H_
#define __HYPERTAP_H_

#include QMK_KEYBOARD_H

/*
** To enable:
**
** // rules.mk:
** TAP_DANCE_ENABLE = yes
** SRC += hypertap.c
**
** enum {
**   HYPERTAP,
**   ...
** }; // tap dance names enum
**
** qk_tap_dance_action_t tap_dance_actions[] = {
**   HYPERTAP_ACTIONS(HYPERTAP)
** }
**
** then use something like TD(HYPERTAP) in layer.
**
 */


#define HYPERTAP_ACTIONS(hypertap_action_name)  \
    [hypertap_action_name] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, hypertap_finished, hypertap_reset)

typedef enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP
} hyper_tap_states_enum;

typedef struct {
    bool    is_press_action;
    uint8_t state;
} tap;

uint8_t cur_dance(qk_tap_dance_state_t *state);
void    hypertap_finished(qk_tap_dance_state_t *state, void *user_data);
void    hypertap_reset(qk_tap_dance_state_t *state, void *user_data);


#endif // __HYPERTAP_H_
