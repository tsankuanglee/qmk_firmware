#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

/* Aliases */
#define ____ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  RGB_0000FF,
  RGB_008000,
  RGB_FFA500,
  RGB_800080,
  RGB_FF0000
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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
  [BASE] = LAYOUT_ergodox(
	// left hand
	KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,TO(7),
	KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,ALL_T(KC_NO),
	KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,
	KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,LT(1,KC_NO),

	LT(4,KC_GRAVE),LT(2,KC_NONUS_BSLASH),KC_LCTL,KC_LGUI,KC_LALT,
		 LT(2,KC_GRAVE),MEH_T(KC_NO),
					LT(4,KC_DELETE),
	KC_SPACE,LT(3,KC_ENTER),LT(5,KC_BSPACE),

	// right hand
	TO(1),KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,
	ALL_T(KC_NO),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
	 KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,
	LT(1,KC_NO),KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,

	   ALGR_T(KC_MINUS),RGUI_T(KC_EQUAL),KC_LBRACKET,KC_RBRACKET,RCTL_T(KC_APPLICATION),
	KC_LEFT,KC_RIGHT,
	KC_UP,
	KC_DOWN,LT(2,KC_SPACE),LT(3,KC_ENTER)
),

  [1] = LAYOUT_ergodox(KC_MINUS,KC_0,KC_9,KC_8,KC_7,KC_6,TO(0),KC_BSLASH,KC_P,KC_O,KC_I,KC_U,KC_Y,KC_APPLICATION,KC_QUOTE,KC_SCOLON,KC_L,KC_K,KC_J,KC_H,KC_RSHIFT,KC_SLASH,KC_DOT,KC_COMMA,KC_M,KC_N,____,KC_LBRACKET,KC_RBRACKET,RCTL_T(KC_NO),RGUI_T(KC_NO),ALGR_T(KC_NO),KC_LCBR,KC_RCBR,KC_EQUAL,____,____,KC_MINUS,TO(2),KC_5,KC_4,KC_3,KC_2,KC_1,KC_GRAVE,KC_ESCAPE,KC_T,KC_R,KC_E,KC_W,KC_Q,KC_TAB,KC_G,KC_F,KC_D,KC_S,KC_A,KC_LCTL,____,KC_B,KC_V,KC_C,KC_X,KC_Z,KC_LSHIFT,ALGR_T(KC_MINUS),RGUI_T(KC_EQUAL),____,____,RCTL_T(KC_APPLICATION),____,____,____,____,____,____),

  [2] = LAYOUT_ergodox(____,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,TO(1),____,KC_F11,KC_F12,KC_F13,KC_F14,KC_F15,____,KC_CAPSLOCK,KC_F16,KC_F17,KC_F18,KC_F19,KC_F20,____,KC_F21,KC_F22,KC_F23,KC_F24,____,____,____,____,____,____,____,____,____,____,____,____,____,TO(3),KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_PSCREEN,KC_NUMLOCK,KC_KP_7,KC_KP_8,KC_KP_9,KC_KP_PLUS,KC_F12,KC_SLCK,KC_KP_4,KC_KP_5,KC_KP_6,KC_KP_MINUS,KC_KP_ENTER,____,____,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_ASTERISK,____,KC_KP_0,KC_EQUAL,KC_KP_DOT,KC_KP_SLASH,____,____,____,____,____,____,____),

  [3] = LAYOUT_ergodox(KC_HOME,KC_MS_BTN4,KC_MS_BTN3,KC_MS_BTN5,KC_MS_WH_UP,KC_MS_ACCEL0,TO(2),KC_END,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_MS_WH_DOWN,KC_MS_ACCEL1,KC_PGUP,KC_LCTL,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_UP,KC_MS_ACCEL2,KC_LSHIFT,KC_MS_WH_LEFT,KC_MS_WH_RIGHT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDOWN,KC_SLCK,KC_APPLICATION,CTL_T(KC_NO),GUI_T(KC_NO),ALT_T(KC_NO),KC_MS_BTN4,KC_MS_BTN5,KC_MS_WH_UP,____,____,KC_MS_WH_DOWN,TO(4),____,KC_PSCREEN,KC_SLCK,KC_PAUSE,KC_MS_WH_LEFT,KC_MS_WH_RIGHT,____,KC_INSERT,KC_HOME,KC_UP,KC_END,KC_PGUP,KC_MS_WH_UP,KC_DELETE,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDOWN,KC_MS_WH_DOWN,____,KC_LCBR,KC_RCBR,KC_LBRACKET,KC_RBRACKET,____,____,ALGR_T(KC_NO),RGUI_T(KC_NO),____,____,RCTL_T(KC_NO),KC_MS_BTN4,KC_MS_BTN5,KC_MS_WH_UP,KC_MS_WH_DOWN,____,____),

  [4] = LAYOUT_ergodox(KC_MAIL,KC_CALCULATOR,KC_MEDIA_STOP,KC_MEDIA_EJECT,KC_WWW_REFRESH,KC_WWW_FAVORITES,TO(3),KC_MY_COMPUTER,KC_MEDIA_PREV_TRACK,KC_MEDIA_REWIND,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_FAST_FORWARD,KC_MEDIA_NEXT_TRACK,____,____,KC_F20,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_AUDIO_VOL_UP,____,____,____,____,____,____,____,____,____,____,____,____,____,KC_WWW_BACK,KC_WWW_FORWARD,____,____,____,KC_WWW_HOME,TO(5),RGB_0000FF,RGB_008000,RGB_FFA500,RGB_800080,RGB_FF0000,KC_SYSTEM_POWER,____,RGB_HUD,RGB_VAD,RGB_TOG,RGB_VAI,RGB_HUI,KC_SYSTEM_SLEEP,KC_B,RGB_SLD,____,RGB_MOD,____,KC_SYSTEM_WAKE,KC_PSCREEN,KC_O,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____),

  [5] = LAYOUT_ergodox(____,LCTL(LGUI(KC_F1)),LCTL(LGUI(KC_F2)),LCTL(LGUI(KC_F3)),LCTL(LGUI(KC_F4)),LCTL(LGUI(KC_F5)),TO(4),____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,TO(6),LCTL(LGUI(KC_F6)),LCTL(LGUI(KC_F7)),LCTL(LGUI(KC_F8)),LCTL(LGUI(KC_F9)),LCTL(LGUI(KC_F10)),LCTL(LGUI(KC_F11)),____,____,____,____,____,____,LCTL(LGUI(KC_F12)),____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____),

  [6] = LAYOUT_ergodox(KC_GRAVE,____,____,____,____,____,TO(5),KC_TAB,____,____,____,____,____,KC_Y,KC_LCTL,____,____,____,____,____,KC_LSHIFT,____,____,____,____,____,KC_H,KC_L,KC_O,KC_LCTL,KC_EQUAL,KC_LALT,KC_KP_MINUS,KC_KP_1,KC_KP_0,KC_SPACE,KC_KP_PLUS,KC_KP_ENTER,TO(7),____,____,____,____,____,____,KC_ESCAPE,____,____,____,____,____,____,____,____,____,____,____,____,KC_F11,____,____,____,____,____,____,____,____,____,____,____,KC_F1,KC_F2,KC_F7,KC_F8,KC_F5,KC_KP_ENTER),

  [7] = LAYOUT_ergodox(____,____,____,____,____,____,TO(6),____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,TO(0),____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____)

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
    
    case RGB_0000FF:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0x00,0x00,0xff);
        #endif
      }
      return false;
      break;
    
    case RGB_008000:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0x00,0x80,0x00);
        #endif
      }
      return false;
      break;
    
    case RGB_FFA500:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0xff,0xa5,0x00);
        #endif
      }
      return false;
      break;
    
    case RGB_800080:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0x80,0x00,0x80);
        #endif
      }
      return false;
      break;
    
    case RGB_FF0000:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0xff,0x00,0x00);
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

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

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
