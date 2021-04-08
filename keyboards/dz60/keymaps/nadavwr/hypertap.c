#include "hypertap.h"

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return 8; // Magic number. At some point this method will expand to work for more presses
}

static tap hypertap_state = {
    .is_press_action = true,
    .state = 0
};

void hypertap_finished(qk_tap_dance_state_t *state, void *user_data) {
    hypertap_state.state = cur_dance(state);
    switch (hypertap_state.state) {
        case SINGLE_TAP: register_code(KC_SPACE); break;
        case SINGLE_HOLD: register_code(KC_LGUI); break;
        case DOUBLE_TAP: tap_code(KC_SPACE); register_code(KC_SPACE); break;
        case DOUBLE_HOLD: register_code16(KC_HYPR); break;
        case DOUBLE_SINGLE_TAP: tap_code(KC_SPACE); register_code(KC_SPACE); break;
    }
}

void hypertap_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (hypertap_state.state) {
        case SINGLE_TAP: unregister_code(KC_SPACE); break;
        case SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code(KC_SPACE); break;
        case DOUBLE_HOLD: unregister_code16(KC_HYPR); break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_SPACE); break;
    }
    hypertap_state.state = 0;
}
