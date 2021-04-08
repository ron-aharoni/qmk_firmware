#ifndef __CONFIG_H_
#define __CONFIG_H_

#include "../../config.h"

#ifdef NKRO_ENABLE
#define FORCE_NKRO
#endif


#define IGNORE_MOD_TAP_INTERRUPT

// consider TAPPING_FORCE_HOLD_PER_KEY to allow space to repeat
#define TAPPING_FORCE_HOLD

// not sure if I want PERMISSIVE_HOLD on pinky,
// may want it on space
// consider PERMISSIVE_HOLD_PER_KEY

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA

#endif // __CONFIG_H_
