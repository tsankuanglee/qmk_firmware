#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


/* Aliases */
#define ____ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  HSV_240_255_255,
  HSV_120_255_128,
  HSV_38_255_255,
  HSV_300_255_128,
  HSV_0_255_255
};

// https://configure.ergodox-ez.com/layouts/amWo

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// this keymap is kept here so we know the order of the keys in the array.
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
//[BASE] = LAYOUT_ergodox(  // layer 0 : default
//        // left hand
//        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
//        KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
//        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
//        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
//        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
//                                              ALT_T(KC_APP),  KC_LGUI,
//                                                              KC_HOME,
//                                               KC_SPC,KC_BSPC,KC_END,
//        // right hand
//             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
//             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
//                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
//             MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
//                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
//             KC_LALT,        CTL_T(KC_ESC),
//             KC_PGUP,
//             KC_PGDN,KC_TAB, KC_ENT
//    ),
[0] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LEAD,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, ALL_T(KC_NO),
    CTL_T(KC_ESCAPE), KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, SH_MON,
     LT(6,KC_NO), LT(7,KC_NO), KC_LCTRL, KC_LGUI, KC_LALT,
        
    // left thumb
    	LT(6,KC_GRAVE), MEH_T(KC_NO),
    		LT(10,KC_DELETE),
    	KC_SPACE, LT(8,KC_ENTER), LT(7,KC_BSPACE),
    
    // right hand
    KC_LEAD, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPACE,
    ALL_T(KC_NO), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
    SH_MON, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
     ALGR_T(KC_MINUS), RGUI_T(KC_EQUAL), RCTL_T(KC_LBRACKET), LT(10,KC_RBRACKET), LT(6,KC_APPLICATION),
    
    // right thumb
    KC_LEFT, KC_RIGHT,
    KC_UP,
    KC_DOWN, LT(7,KC_SPACE), LT(8,KC_ENTER)
),

[1] = LAYOUT_ergodox(
    // left hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		LT(10,KC_NO),
    	____, ____, ____,
    
    // right hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[2] = LAYOUT_ergodox(
    // left hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		LT(10,KC_NO),
    	____, ____, ____,
    
    // right hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[3] = LAYOUT_ergodox(
    // left hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		LT(10,KC_NO),
    	____, ____, ____,
    
    // right hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[4] = LAYOUT_ergodox(
    // left hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		____,
    	____, ____, ____,
    
    // right hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[5] = LAYOUT_ergodox(
    // left hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		____,
    	____, ____, ____,
    
    // right hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[6] = LAYOUT_ergodox(
    // left hand
    ____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, ____,
    ____, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, ____,
    ____, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,
    ____, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		LT(10,KC_NO),
    	____, ____, ____,
    
    // right hand
    ____, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    ____, KC_F21, KC_F22, KC_F23, KC_F24, KC_NONUS_BSLASH, KC_F12,
    KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_NONUS_HASH,
    ____, KC_GRAVE, KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[7] = LAYOUT_ergodox(
    // left hand
    KC_CAPSLOCK, KC_CALCULATOR, KC_WWW_SEARCH, KC_MAIL, KC_PSCREEN, KC_MY_COMPUTER, ____,
    KC_F20, KC_AUDIO_MUTE, KC_WWW_HOME, KC_MEDIA_EJECT, KC_WWW_REFRESH, KC_AUDIO_VOL_UP, ____,
    ____, KC_WWW_FAVORITES, KC_WWW_BACK, KC_MEDIA_STOP, KC_WWW_FORWARD, KC_AUDIO_VOL_DOWN,
    ____, KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, KC_MEDIA_NEXT_TRACK, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		LT(10,KC_NO),
    	____, ____, ____,
    
    // right hand
    ____, KC_CIRC, KC_EQUAL, KC_KP_ASTERISK, KC_LPRN, KC_RPRN, KC_BSPACE,
    ____, KC_NUMLOCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_EQUAL,
    KC_SCROLLLOCK, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_KP_ENTER,
    ____, KC_PSCREEN, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, ____,
     KC_KP_0, KC_PERC, KC_KP_DOT, ____, KC_CALCULATOR,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[8] = LAYOUT_ergodox(
    // left hand
    KC_HOME, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN5, KC_MS_WH_UP, KC_MS_ACCEL0, ____,
    KC_END, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_MS_WH_DOWN, KC_MS_ACCEL1, KC_PGUP,
    ____, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_UP, KC_MS_ACCEL2,
    ____, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		LT(10,KC_NO),
    	LT(9,KC_NO), ____, ____,
    
    // right hand
    ____, ____, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
    ____, KC_INSERT, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_MS_WH_UP,
    KC_DELETE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, KC_MS_WH_DOWN,
    ____, KC_MS_BTN4, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN5, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, LT(9,KC_NO), ____
),

[9] = LAYOUT_ergodox(
    // left hand
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, KC_MS_BTN4, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN5, ____,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		____,
    	____, ____, ____,
    
    // right hand
    ____, ____, ____, ____, ____, KC_MS_ACCEL0, ____,
    ____, KC_MS_WH_UP, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN5, KC_MS_ACCEL1, ____,
    KC_MS_WH_DOWN, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_MS_ACCEL2, ____,
    ____, KC_MS_WH_LEFT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_RIGHT, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
),

[10] = LAYOUT_ergodox(
    // left hand
    TO(0), TO(1), TO(2), TO(3), TO(4), TO(5), ____,
    ____, TO(6), TO(7), TO(8), TO(9), ____, ____,
    ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, SH_OFF,
     ____, ____, ____, ____, ____,
        
    // left thumb
    	____, ____,
    		____,
    	____, ____, ____,
    
    // right hand
    ____, HSV_240_255_255, HSV_120_255_128, HSV_38_255_255, HSV_300_255_128, HSV_0_255_255, KC_SYSTEM_POWER,
    ____, RGB_HUD, RGB_VAD, RGB_TOG, RGB_VAI, RGB_HUI, KC_SYSTEM_SLEEP,
    ____, RGB_SLD, ____, RGB_MOD, ____, KC_SYSTEM_WAKE,
    ____, RESET, ____, ____, ____, KC_POWER, ____,
     ____, ____, ____, ____, ____,
    
    // right thumb
    ____, ____,
    ____,
    ____, ____, ____
)

};
    

const uint16_t PROGMEM fn_actions[] = {
    //[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        //SEND_STRING (QMK_KEYBOARD "/" QMK_LAYOUT_ergodox " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        //SEND_STRING (QMK_KEYBOARD "/" QMK_LAYOUT_ergodox " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case HSV_240_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(240,255,255);
        #endif
      }
      return false;
      break;
    case HSV_120_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(120,255,128);
        #endif
      }
      return false;
      break;
    case HSV_38_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(38,255,255);
        #endif
      }
      return false;
      break;
    case HSV_300_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(300,255,128);
        #endif
      }
      return false;
      break;
    case HSV_0_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  ergodox_led_all_set(5); 
};

// leader key
LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // SEQ_ONE_KEY SEQ_TWO_KEYS SEQ_THREE_KEYS SEQ_FOUR_KEYS SEQ_FIVE_KEYS
    SEQ_TWO_KEYS(KC_C, KC_D) {
      SEND_STRING("cd ~/");
    }
    SEQ_THREE_KEYS(KC_A,KC_W,KC_K) {
      SEND_STRING("awk '{print $1}'"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
    }
    //SEQ_THREE_KEYS(KC_X,KC_O,KC_N) {
    //  // Anything you can do in a macro.
      //SEND_STRING(SS_LCTRL("a")SS_LCTRL("c"));
      //SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER));
      //register_code(KC_LGUI);
      //register_code(KC_S);
      //unregister_code(KC_S);
      //unregister_code(KC_LGUI);
    //}
  }
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
