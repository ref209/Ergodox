#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

// LAYERS
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

// MACROS
#define OBRACE 0 // key { or shift
#define CBRACE 1 // key } or shift
#define OBRACK 2 // key [ or left alt
#define CBRACK 3 // key ] or left alt
#define OPAR 4 // key (
#define CPAR 5 // key )
#define CAPS 6 // caps lock
#define AT 7 // key @
#define HASH 8 // key #
#define WSUP 9 // CTRL ALT UP
#define WSDW 10 // CTRL ALT DOWN

  // TIMERS
#define KEY_TAP_FAST 85
#define KEY_TAP_SLOW 95

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
    [BASE] = KEYMAP(  // layer 0 : default
      // left hand
      KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_NONUS_BSLASH,
      KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_FN1,
      KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
      KC_LSFT,        KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
      KC_LCTRL,KC_LALT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
      ALT_T(KC_APP),  KC_LGUI,
      KC_HOME,
      KC_SPC,KC_BSPC,KC_END,
      // right hand
      KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
      KC_FN1,    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
      KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
      MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
      KC_UP,  KC_DOWN,KC_LBRC,M(WSUP),          M(WSDW),
      KC_LALT,        CTL_T(KC_ESC),
      KC_PGUP,
      KC_PGDN,KC_TAB, KC_ENT
    ),
    /* Keymap 1: Symbol Layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    // SYMBOLS
    [SYMB] = KEYMAP(
      // left hand
      M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
      KC_TRNS,KC_EXLM,M(AT),  M(OBRACE),M(CBRACE),KC_PIPE,KC_TRNS,
      KC_TRNS,M(HASH),KC_DLR, M(OPAR),M(CPAR),KC_GRV,
      KC_TRNS,KC_PERC,KC_CIRC,M(OBRACK),M(CBRACK),KC_TILD,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,
      KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,
      // right hand
      KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_RBRACKET, KC_F12,
      KC_DOWN, KC_4,   KC_5,    KC_6,    LSFT(KC_RBRACKET), KC_TRNS,
      KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
      KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* Keymap 2: Media and mouse keys
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |Brwser|
    *                                 | Lclk | Rclk |------|       |------|      |Back  |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    // MEDIA AND MOUSE
    [MDIA] = KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
      LCTL(KC_SCLN), LCTL(KC_Z), LCTL(KC_T), LCTL(KC_I), LCTL(KC_COMM), LCTL(KC_V), LCTL(KC_K),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_BTN1, KC_BTN2, KC_TRNS,
      // right hand
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_WBAK
    ),
  };

  const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
  };

  const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
  {
    switch(id) {
      case OBRACE: {
        if (record->event.pressed) {
          register_code(KC_RALT);
          register_code(KC_QUOTE);
          unregister_code(KC_QUOTE);
          unregister_code(KC_RALT);
        }
        break;
      }
      case CBRACE: {
        if (record->event.pressed) {
          register_code(KC_RALT);
          register_code(KC_BSLS);
          unregister_code(KC_BSLS);
          unregister_code(KC_RALT);
        }
        break;
      }
      case OBRACK: {
        if (record->event.pressed) {
          register_code(KC_RALT);
          register_code(KC_LBRACKET);
          unregister_code(KC_LBRACKET);
          unregister_code(KC_RALT);
        }
        break;
      }
      case CBRACK: {
        if (record->event.pressed) {
          register_code(KC_RALT);
          register_code(KC_RBRACKET);
          unregister_code(KC_RBRACKET);
          unregister_code(KC_RALT);
        }
        break;
      }
      case OPAR: {
        if (record->event.pressed) {
          register_code(KC_RSFT);
          register_code(KC_8);
          unregister_code(KC_8);
          unregister_code(KC_RSFT);
        }
        break;
        }
        case CPAR: {
          if (record->event.pressed) {
            register_code(KC_RSFT);
            register_code(KC_9);
            unregister_code(KC_9);
            unregister_code(KC_RSFT);
          }
          break;
          }
      case CAPS: {
        if (record->event.pressed) {
          register_code(KC_CAPSLOCK);
        } else {
          unregister_code(KC_CAPSLOCK);
        }
        break;
      }
      case AT: {
        if (record->event.pressed) {
          register_code(KC_RALT);          register_code(KC_2);
          unregister_code(KC_2);
          unregister_code(KC_RALT);
        }
        break;
      }
      case HASH: {
        if (record->event.pressed) {
          register_code(KC_RALT);
          register_code(KC_3);
          unregister_code(KC_3);
          unregister_code(KC_RALT);
        }
        break;
      }
      case WSUP: {
        if (record->event.pressed) {
          register_code(KC_LCTRL);
          register_code(KC_LALT);
          register_code(KC_UP);
          unregister_code(KC_UP);
          unregister_code(KC_LALT);
          unregister_code(KC_LCTRL);
        }
        break;
      }
      case WSDW: {
        if(record->event.pressed) {
          register_code(KC_LCTRL);
          register_code(KC_LALT);
          register_code(KC_DOWN);
          unregister_code(KC_DOWN);
          unregister_code(KC_LALT);
          unregister_code(KC_LCTRL);
        }
        break;
      }
    }
    return MACRO_NONE;
  };

  // Runs just one time when the keyboard initializes.
  void matrix_init_user(void) {

  };

  // Runs constantly in the background, in a loop.
  void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
      case 0:
      ergodox_right_led_1_on();
      break;
      case 1:
      ergodox_right_led_2_on();
      break;
      case 2:
      ergodox_right_led_3_on();
      break;
      default:
      // none
      break;
    }

  };
