#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "config.h"


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
       KC_GRAVE,            KC_1,            KC_2,            KC_3,              KC_4,               KC_5,    KC_TRANSPARENT,
       KC_TAB,              KC_Q,            KC_W,            KC_F,              KC_P,               KC_G,    KC_TRANSPARENT,
       CTL_T(KC_ESCAPE),    SFT_T(KC_A),     KC_R,            LT(3,KC_S),        LT(2,KC_T),         KC_D,    /*...........*/
       OSM(MOD_LSFT),       CTL_T(KC_Z),     KC_X,            KC_C,              KC_V,               KC_B,    KC_TRANSPARENT,
       OSL(2),              MEH_T(KC_NO),    ALL_T(KC_NO),    ALT_T(KC_LEFT),    GUI_T(KC_RIGHT),

                                                     KC_TRANSPARENT,           KC_TRANSPARENT,
                                 /*.....*/           /*...........*/           KC_TRANSPARENT,
                                 KC_SPACE,           LGUI(KC_SPACE),           LCTL(KC_SPACE),

       // right hand
       KC_TRANSPARENT,    KC_6,             KC_7,                  KC_8,                  KC_9,      KC_0,                 KC_MINUS,
       KC_TRANSPARENT,    KC_J,             KC_L,                  KC_U,                  KC_Y,      KC_SCOLON,            KC_BSLASH,
       /*...........*/    KC_H,             LT(2,KC_N),            LT(3,KC_E),            KC_I,      SFT_T(KC_O),          RCTL_T(KC_QUOTE),
       KC_TRANSPARENT,    KC_K,             KC_M,                  KC_COMMA,              KC_DOT,    RCTL_T(KC_SLASH),     OSM(MOD_RSFT),
       GUI_T(KC_DOWN),    RALT_T(KC_UP),    ALL_T(KC_LBRACKET),    MEH_T(KC_RBRACKET),    OSL(3),

       KC_TRANSPARENT,           KC_TRANSPARENT,
       KC_TRANSPARENT,           /*...........*/           /*.....*/
       RCTL(KC_SPACE),           LGUI(KC_SPACE),           KC_SPACE),

  [1] = LAYOUT_ergodox(   //layer 1 : qwerty
        // left hand
        KC_GRAVE,            KC_1,            KC_2,            KC_3,              KC_4,               KC_5,    KC_TRANSPARENT,
        KC_TAB,              KC_Q,            KC_W,            KC_E,              KC_R,               KC_T,    KC_TRANSPARENT,
        CTL_T(KC_ESCAPE),    SFT_T(KC_A),     KC_S,            LT(3,KC_D),        LT(2,KC_F),         KC_G,    /*...........*/
        OSM(MOD_LSFT),       CTL_T(KC_Z),     KC_X,            KC_C,              KC_V,               KC_B,    KC_TRANSPARENT,
        OSL(2),              MEH_T(KC_NO),    ALL_T(KC_NO),    ALT_T(KC_LEFT),    GUI_T(KC_RIGHT),

                                                    KC_TRANSPARENT,      KC_TRANSPARENT,
                                     /*.....*/      /*...........*/      KC_TRANSPARENT,
                                     KC_SPACE,      LGUI(KC_SPACE),      LCTL(KC_SPACE),

        // right hand
        KC_TRANSPARENT,    KC_6,             KC_7,                  KC_8,                  KC_9,                KC_0,                KC_MINUS,
        KC_TRANSPARENT,    KC_Y,             KC_U,                  KC_I,                  KC_O,                KC_P,                KC_BSLASH,
        /*...........*/    KC_H,             LT(2,KC_J),            LT(3,KC_K),            KC_L,                SFT_T(KC_SCOLON),    RCTL_T(KC_QUOTE),
        KC_TRANSPARENT,    KC_N,             KC_M,                  KC_COMMA,              KC_DOT,              RCTL_T(KC_SLASH),    OSM(MOD_RSFT),
        GUI_T(KC_DOWN),    RALT_T(KC_UP),    ALL_T(KC_LBRACKET),    MEH_T(KC_RBRACKET),    OSL(3),

        KC_TRANSPARENT,    KC_TRANSPARENT,
        KC_TRANSPARENT,    /*...........*/    /*....*/
        RCTL(KC_SPACE),    LGUI(KC_SPACE),    KC_SPACE),

  [2] = LAYOUT_ergodox(   //layer 2 : navigation
        // left hand
        KC_TRANSPARENT,    KC_TRANSPARENT,    KC_MS_BTN4,      KC_MS_BTN3,          KC_MS_BTN5,      KC_TRANSPARENT,    KC_TRANSPARENT,
        KC_TRANSPARENT,    KC_MS_WH_DOWN,     KC_MS_BTN1,      KC_MS_UP,            KC_MS_BTN2,      KC_MS_WH_UP,       KC_TRANSPARENT,
        KC_TRANSPARENT,    KC_MS_WH_LEFT,     KC_MS_LEFT,      KC_MS_DOWN,          KC_MS_RIGHT,     KC_MS_WH_RIGHT,    /*...........*/
        KC_ENTER,          KC_TRANSPARENT,    KC_MS_ACCEL0,    KC_MS_ACCEL1,        KC_MS_ACCEL2,    KC_TRANSPARENT,    KC_TRANSPARENT,
        KC_TRANSPARENT,    KC_TRANSPARENT,    LGUI(KC_T),      LGUI(LSFT(KC_T)),    LGUI(KC_W),

                                                  KC_TRANSPARENT,    KC_TRANSPARENT,
                                                                     KC_TRANSPARENT,
                                    KC_ESCAPE,    TO(0),             KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT,    KC_TRANSPARENT,      LCTL(KC_DOWN),    LCTL(KC_LEFT),         LCTL(KC_RIGHT),    LCTL(KC_UP),       KC_TRANSPARENT,
        LGUI(KC_C),        KC_TRANSPARENT,      KC_WWW_BACK,      LCTL(LSFT(KC_TAB)),    LCTL(KC_TAB),      KC_WWW_FORWARD,    KC_TRANSPARENT,
        /*.......*/        KC_BSPACE,           KC_LEFT,          KC_DOWN,               KC_UP,             KC_RIGHT,          KC_TRANSPARENT,
        LGUI(KC_V),        KC_TRANSPARENT,      KC_END,           KC_PGDOWN,             KC_PGUP,           KC_HOME,           KC_ENTER,
        LGUI(KC_W),        LGUI(LSFT(KC_T)),    RGUI(KC_T),       KC_TRANSPARENT,        TO(3),

        KC_TRANSPARENT,    KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT,    TO(1),             KC_ENTER),

  [3] = LAYOUT_ergodox(
        // left hand
        KC_ESCAPE,         KC_F1,             KC_F2,             KC_F3,          KC_F4,          KC_F5,       KC_F6,
        KC_TRANSPARENT,    KC_EXLM,           KC_AT,             KC_LCBR,        KC_RCBR,        KC_PIPE,     KC_TRANSPARENT,
        KC_TRANSPARENT,    KC_HASH,           KC_DLR,            KC_LPRN,        KC_RPRN,        KC_GRAVE,
        KC_ENTER,          KC_PERC,           KC_CIRC,           KC_LBRACKET,    KC_RBRACKET,    KC_TILD,     KC_TRANSPARENT,
        TO(2),             KC_TRANSPARENT,    KC_TRANSPARENT,    KC_AMPR,        KC_BSLASH,

        KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,
        LT(4,KC_SPACE), TO(0), KC_TRANSPARENT,

        // right hand
        KC_F7,              KC_F8,             KC_F9,     KC_F10,            KC_F11,            KC_F12,         KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_UP,             KC_7,      KC_8,              KC_9,              KC_ASTERISK,    KC_SLASH,
        /*...........*/     KC_BSPACE,         KC_4,      KC_5,              KC_6,              KC_PLUS,        KC_MINUS,
        KC_TRANSPARENT,     KC_AMPR,           KC_1,      KC_2,              KC_3,              KC_EQUAL,       KC_ENTER,
        KC_0,               KC_COMMA,          KC_DOT,    KC_TRANSPARENT,    KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,
        KC_TRANSPARENT,     TO(1),             MO(4)),

  [4] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_REWIND,KC_MEDIA_STOP,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_AUDIO_VOL_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_REWIND,KC_MEDIA_STOP,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_AUDIO_VOL_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

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
