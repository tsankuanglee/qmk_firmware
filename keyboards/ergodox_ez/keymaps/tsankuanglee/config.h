#ifndef CONFIG_TSANKUANGLEE_H
#define CONFIG_TSANKUANGLEE_H

#include "../../config.h"

#ifndef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 4
#endif // !QMK_KEYS_PER_SCAN

#undef TAPPING_TERM
#define TAPPING_TERM 100

#ifndef RETRO_TAPPING
#define RETRO_TAPPING // Tap anyway, even after timeout, as long as there was no interruption
#endif

#ifndef PERMISSIVE_HOLD
#define PERMISSIVE_HOLD
#endif

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
#ifndef NO_DEBUG
#define NO_DEBUG
#endif

/* disable print */
#ifndef NO_PRINT
#define NO_PRINT
#endif


/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//#define DEBUG_MATRIX_SCAN_RATE

#undef DEBUG_ACTION

#endif
