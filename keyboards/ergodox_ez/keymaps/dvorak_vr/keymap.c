#include "config.h"
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

  [0] = LAYOUT_ergodox(   //layer 0 : default, dvorak
       // left hand
       KC_F13,              KC_1,            KC_2,            KC_3,              KC_4,               KC_5,          SGUI(KC_3),
       KC_TAB,              KC_QUOTE,        KC_COMMA,        KC_DOT,            KC_P,               KC_Y,          SGUI(KC_4),
       KC_LCTL,             KC_A,            LT(1,KC_O),      LT(2,KC_E),        LT(3,KC_U),         LT(3,KC_I),    /*...........*/
       KC_LSFT,             KC_SCLN,         KC_Q,            KC_J,              KC_K,               KC_X,          _______,
       KC_CAPS,             KC_HYPR,         KC_MEH,          KC_LCAG,           KC_LALT,

                                                      _______,                  LCTL(KC_TAB),
                                 /*.....*/            /*....*/                  S(LCTL(KC_TAB)),
                                 GUI_T(KC_SPACE),     LALT(KC_F1),              LCTL(KC_LEFT),

       // right hand
       _______,           _______,          LCTL(KC_DOWN),         LCTL(KC_LEFT),         LCTL(KC_RIGHT),    LCTL(KC_UP),          _______,
       LCTL(KC_F1),       KC_F,             KC_G,                  KC_C,                  KC_R,              KC_L,                 KC_SLSH,
       /*....*/           LT(3,KC_D),       LT(3,KC_H),            LT(2,KC_T),            KC_N,              KC_S,                 RCTL_T(KC_MINS),
       LALT(KC_F1),       KC_B,             KC_M,                  KC_W,                  KC_V,              RCTL_T(KC_Z),         KC_LSFT,
       KC_RGUI,           KC_LCAG,          KC_MEH,                KC_HYPR,               KC_CAPS,

       LCTL(KC_UP),                _______,
       LGUI(KC_GRAVE),             /*...*/           /*.............*/
       LCTL(KC_RIGHT),             LALT(KC_F1),      ALT_T(KC_SPACE)),

  [1] = LAYOUT_ergodox(   //layer 1 : regex
       // left hand
       _______,     _______,     _______,     KC_3,        KC_4,            KC_5,        _______,
       _______,     _______,     _______,     KC_0,        KC_1,            KC_9,        _______,
       _______,     _______,     XXXXXXX,     LT(2,KC_E),  LT(3,KC_S),      KC_D,        /*....*/
       _______,     _______,     _______,     KC_W,        KC_Z,            KC_B,        _______,
       _______,     _______,     _______,     _______,     KC_PERC,

                                              _______,      _______,
                                 /*.....*/    /*....*/      _______,
                                 KC_SPC,      _______,      _______,

       // right hand
       _______,      KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        _______,
       _______,      KC_LCBR,     KC_RCBR,     KC_AMPR,     KC_COLN,     KC_PAST,     KC_SLSH,
       /*....*/      KC_LPRN,     KC_RPRN,     KC_CIRC,     KC_DLR,      KC_PLUS,     KC_MINS,
       _______,      KC_LBRC,     KC_RBRC,     KC_COMM,     KC_DOT,      KC_QUES,     KC_EXLM,
       KC_BSLS,      _______,     _______,     _______,     _______,

       _______,     _______,
       _______,     /*....*/      /*.....*/
       _______,     _______,      KC_SPC),

  [2] = LAYOUT_ergodox(   //layer 2 : navigation
        // left hand
        _______,           XXXXXXX,             KC_MS_ACCEL0,            KC_MS_ACCEL1,           KC_MS_ACCEL2,      XXXXXXX,               _______,
        _______,           LCTL(KC_LEFT),       KC_MS_BTN1,              KC_MS_BTN3,             KC_MS_BTN2,        LCTL(KC_RIGHT),        _______,
        _______,           KC_MS_WH_RIGHT,      KC_MS_WH_UP,             KC_MS_UP,               KC_MS_WH_DOWN,     KC_MS_WH_LEFT,         /*....*/
        LSFT(KC_ENT),      LCTL(LSFT(KC_TAB)),  KC_MS_LEFT,              KC_MS_DOWN,             KC_MS_RIGHT,       LCTL(KC_TAB),          _______,
        TO(0),             _______,             LGUI(KC_T),              LGUI(KC_W),             SGUI(KC_T),

                                                  _______,           _______,
                                                                     _______,
                                    KC_ESCAPE,    _______,           _______,

        // right hand
        _______,           XXXXXXX,             LCTL(KC_DOWN),    LCTL(KC_LEFT),         LCTL(KC_RIGHT),    LCTL(KC_UP),       _______,
        LGUI(KC_C),        LGUI(KC_GRAVE),      LCTL(KC_LEFT),    LCTL(LSFT(KC_TAB)),    LCTL(KC_TAB),      LCTL(KC_RIGHT),    _______,
        /*.......*/        KC_BSPACE,           KC_LEFT,          KC_DOWN,               KC_UP,             KC_RIGHT,          _______,
        LGUI(KC_V),        SGUI(KC_GRAVE),      KC_HOME,          KC_PGDOWN,             KC_PGUP,           KC_END,            KC_LSFT,
        _______,           _______,             _______,          _______,               TO(3),

        _______,           _______,
        _______,
        _______,           _______,             KC_ESCAPE),

  [3] = LAYOUT_ergodox(
        // left hand
        KC_ESCAPE,         KC_F1,             KC_F2,             KC_F3,          KC_F4,          KC_F5,       KC_F6,
        _______,           KC_EXLM,           KC_AT,             KC_LCBR,        KC_RCBR,        KC_PIPE,     _______,
        _______,           KC_HASH,           KC_DLR,            KC_LPRN,        KC_RPRN,        KC_GRAVE,
        _______,           KC_PERC,           KC_CIRC,           KC_LBRACKET,    KC_RBRACKET,    KC_TILD,     _______,
        TO(2),             _______,           _______,           KC_AMPR,        KC_BSLASH,

        _______,           _______,
        _______,
        _______,           TO(0),             _______,

        // right hand
        KC_F7,              KC_F8,             KC_F9,          KC_F10,         KC_F11,          KC_F12,         _______,
        _______,            KC_BSLS,           KC_P7,          KC_P8,          KC_P9,           KC_PAST,        KC_PSLS,
        /*...........*/     KC_BSPACE,         KC_P4,          LT(4,KC_P5),    KC_P6,           KC_PPLS,        KC_PMNS,
        _______,            KC_COLN,           KC_P1,          KC_P2,          KC_P3,           KC_PEQL,        KC_ENT,
        KC_P0,              KC_COMM,           KC_PDOT,        _______,        TO(0),

        _______,            _______,
        _______,
        _______,            MO(8),             _______),

  [4] = LAYOUT_ergodox(
        // left hand
        KC_ESCAPE,         KC_F1,             KC_F2,         KC_F3,          KC_F4,          KC_F5,       KC_F6,
        KC_E,              KC_F,              KC_P7,         KC_P8,          KC_P9,          KC_SCLN,     _______,
        KC_C,              KC_D,              KC_P4,         KC_P5,          KC_P6,          KC_BSPACE,
        KC_A,              KC_B,              KC_P1,         KC_P2,          KC_P3,          KC_HASH,     _______,
        TO(2),             _______,           KC_P0,         KC_COMM,        KC_PDOT,

        _______,           _______,
        _______,
        _______,           _______,             _______,

        // right hand
        KC_F7,        KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,      _______,
        _______,      KC_LCBR,     KC_RCBR,     KC_AMPR,     KC_COLN,     KC_PAST,     KC_SLSH,
        /*....*/      KC_LPRN,     KC_RPRN,     KC_CIRC,     KC_DLR,      KC_PLUS,     S(KC_MINS),
        _______,      KC_LBRC,     KC_RBRC,     KC_COMM,     KC_DOT,      KC_QUES,     S(KC_ENTER),
        KC_BSLS,      _______,     _______,     _______,     _______,

        _______,            _______,
        _______,
        _______,            MO(8),             _______),

  [8] = LAYOUT_ergodox(
        _______,     _______,             _______,                 _______,                   _______,                   _______,     _______,
        _______,     _______,             KC_MEDIA_PREV_TRACK,     KC_MEDIA_PLAY_PAUSE,       KC_MEDIA_NEXT_TRACK,       _______,     _______,
        _______,     _______,             KC_MEDIA_REWIND,         KC_MEDIA_STOP,             KC_MEDIA_FAST_FORWARD,     _______,
        _______,     _______,             KC_AUDIO_VOL_DOWN,       KC_AUDIO_MUTE,             KC_AUDIO_VOL_UP,           _______,     _______,
        _______,     _______,             _______,                 _______,                   _______,

        _______,     _______,
        _______,
        _______,     _______,             _______,

        // right hand
        _______,     _______,             _______,                 _______,                   _______,                   _______,     _______,
        _______,     _______,             KC_MEDIA_PREV_TRACK,     KC_MEDIA_PLAY_PAUSE,       KC_MEDIA_NEXT_TRACK,       _______,     _______,
        _______,     KC_MEDIA_REWIND,     KC_MEDIA_STOP,           KC_MEDIA_FAST_FORWARD,     _______,                   _______,
        _______,     _______,             KC_AUDIO_VOL_DOWN,       KC_AUDIO_MUTE,             KC_AUDIO_VOL_UP,           _______,     _______,
        _______,     _______,             _______,                 _______,                   _______,

        _______,     _______,
        _______,
        _______,     _______,             _______),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
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
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
