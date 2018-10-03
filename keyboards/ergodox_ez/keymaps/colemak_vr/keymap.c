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

  [0] = LAYOUT_ergodox(   //layer 0 : default, colemak
       // left hand
       KC_ESC,              KC_1,            KC_2,            KC_3,              KC_4,               KC_5,          _______,
       KC_TAB,              KC_Q,            KC_W,            KC_F,              KC_P,               KC_G,          _______,
       OSM(MOD_LCTL),       KC_A,            LT(4,KC_R),      LT(2,KC_S),        LT(3,KC_T),         LT(3,KC_D),    /*...........*/
       OSM(MOD_LSFT),       CTL_T(KC_Z),     KC_X,            KC_C,              KC_V,               KC_B,          _______,
       OSL(2),              OSM(MOD_MEH),    OSM(MOD_HYPR),    OSM(MOD_LALT),    OSM(MOD_LGUI),

                                                      _______,                  _______,
                                 /*.....*/            /*...........*/           _______,
                                 GUI_T(KC_SPACE),     KC_BSPC,                  LGUI(LCTL(KC_SPACE)),

       // right hand
       _______,           _______,          LCTL(KC_DOWN),         LCTL(KC_LEFT),         LCTL(KC_RIGHT),    LCTL(KC_UP),          _______,
       _______,           KC_J,             KC_L,                  KC_U,                  KC_Y,              KC_SCOLON,            KC_BSLASH,
       /*...........*/    LT(3,KC_H),       LT(3,KC_N),            LT(2,KC_E),            KC_I,              KC_O,                 RCTL_T(KC_QUOTE),
       _______,           KC_K,             KC_M,                  KC_COMMA,              KC_DOT,            RCTL_T(KC_SLASH),     OSM(MOD_LSFT),
       OSM(MOD_LGUI),     OSM(MOD_LALT),    OSM(MOD_HYPR),         OSM(MOD_MEH),          OSL(3),

       _______,                  _______,
       _______,                  /*...........*/           /*.....*/
       RGUI(RCTL(KC_SPACE)),     KC_ENT,           KC_SPACE),

  [1] = LAYOUT_ergodox(   //layer 1 : qwerty
        // left hand
        _______,             KC_1,            KC_2,            KC_3,              KC_4,               KC_5,          _______,
        _______,             KC_Q,            KC_W,            KC_E,              KC_R,               KC_T,          _______,
        _______,             KC_A,            LT(4,KC_S),      LT(2,KC_D),        LT(3,KC_F),         LT(3,KC_G),    /*...........*/
        _______,             CTL_T(KC_Z),     KC_X,            KC_C,              KC_V,               KC_B,          _______,
        OSL(2),              _______,         _______,         _______,           _______,

                                                 _______,            _______,
                                  /*.....*/      /*..........*/      _______,
                                  _______,       _______,            _______,

        // right hand
        _______,           KC_6,             KC_7,                  KC_8,                  KC_9,                KC_0,                KC_MINUS,
        _______,           KC_Y,             KC_U,                  KC_I,                  KC_O,                KC_P,                KC_BSLASH,
        /*...........*/    LT(3,KC_H),       LT(3,KC_J),            LT(2,KC_K),            KC_L,                KC_SCOLON,           RCTL_T(KC_QUOTE),
        _______,           KC_N,             KC_M,                  KC_COMMA,              KC_DOT,              RCTL_T(KC_SLASH),    OSM(MOD_LSFT),
        _______,           _______,          _______,               _______,               OSM(3),

        _______,           _______,
        _______,           /*...........*/    /*....*/
        _______,           _______,           _______),

  [2] = LAYOUT_ergodox(   //layer 2 : navigation
        // left hand
        _______,           LCTL(KC_LEFT),       LCTL(LSFT(KC_TAB)),      KC_MS_BTN3,             LCTL(KC_TAB),      LCTL(KC_RIGHT),        _______,
        _______,           KC_MS_WH_DOWN,       KC_MS_BTN1,              KC_MS_UP,               KC_MS_BTN2,        KC_MS_WH_UP,           _______,
        _______,           KC_MS_WH_LEFT,       KC_MS_LEFT,              KC_MS_DOWN,             KC_MS_RIGHT,       KC_MS_WH_RIGHT,        /*...........*/
        LSFT(KC_ENTER),    XXXXXXX,             KC_MS_ACCEL0,            KC_MS_ACCEL1,           KC_MS_ACCEL2,      XXXXXXX,               _______,
        _______,           _______,             LGUI(KC_T),              LGUI(KC_W),             LGUI(LSFT(KC_T)),

                                                  _______,           _______,
                                                                     _______,
                                    KC_ESCAPE,    TO(0),             _______,

        // right hand
        _______,           _______,             LCTL(KC_DOWN),    LCTL(KC_LEFT),         LCTL(KC_RIGHT),    LCTL(KC_UP),       _______,
        LGUI(KC_C),        XXXXXXX,             KC_WWW_BACK,      LCTL(LSFT(KC_TAB)),    LCTL(KC_TAB),      KC_WWW_FORWARD,    _______,
        /*.......*/        KC_BSPACE,           KC_LEFT,          KC_DOWN,               KC_UP,             KC_RIGHT,          _______,
        LGUI(KC_V),        XXXXXXX,             KC_HOME,          KC_PGDOWN,             KC_PGUP,           KC_END,            OSM(MOD_LSFT),
        _______,           _______,             _______,          _______,               _______,

        _______,           _______,
        _______,
        _______,           TO(1),             KC_ENTER),

  [3] = LAYOUT_ergodox(
        // left hand
        KC_ESCAPE,         KC_F1,             KC_F2,             KC_F3,          KC_F4,          KC_F5,       KC_F6,
        _______,           KC_EXLM,           KC_AT,             KC_LCBR,        KC_RCBR,        KC_PIPE,     _______,
        _______,           KC_HASH,           KC_DLR,            KC_LPRN,        KC_RPRN,        KC_GRAVE,
        OSM(MOD_LSFT),     KC_PERC,           KC_CIRC,           KC_LBRACKET,    KC_RBRACKET,    KC_TILD,     _______,
        _______,           _______,           _______,           KC_AMPR,        KC_BSLASH,

        _______,           _______,
        _______,
        LT(8,KC_SPACE),    TO(0),    _______,

        // right hand
        KC_F7,              KC_F8,             KC_F9,     KC_F10,            KC_F11,            KC_F12,         _______,
        _______,            KC_SCLN,           KC_7,      KC_8,              KC_9,              KC_ASTERISK,    KC_SLASH,
        /*...........*/     KC_BSPACE,         KC_4,      KC_5,              KC_6,              KC_PLUS,        KC_MINUS,
        _______,            KC_COLN,           KC_1,      KC_2,              KC_3,              KC_EQUAL,       KC_ENTER,
        KC_0,               KC_COMMA,          KC_DOT,    _______,           _______,

        _______,            _______,
        _______,
        _______,            TO(1),             LT(8,KC_SPACE)),


  [4] = LAYOUT_ergodox(   //layer 4 : regex
       // left hand
       _______,     _______,     _______,     KC_3,        KC_4,        KC_5,        _______,
       _______,     _______,     _______,     KC_BSPC,     KC_1,        KC_2,        _______,
       _______,     KC_HOME,     XXXXXXX,     KC_LEFT,     KC_RGHT,     KC_END,      /*....*/
       _______,     _______,     _______,     _______,     _______,     _______,     _______,
       _______,     _______,     _______,     _______,     _______,

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
