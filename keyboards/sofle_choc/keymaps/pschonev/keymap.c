/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "sendstring_us_international.h"
#include "features/achordion.h"

enum custom_keycode {
  M_QUOT = QK_KB_0,
  M_DQUOT,
  M_LNAV,
  M_RNAV,
  M_UPNAV,
  M_SCREEN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

LAYOUT(
    KC_GRAVE,  M_SCREEN, KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    M_SCREEN,
    TG(2),   KC_B,    KC_L,    KC_D,    KC_G,    KC_V,                      KC_K,    KC_F,    KC_U,    KC_DQUO, KC_QUOT, KC_LCTL,
    KC_LSFT,   KC_N,    KC_R,    KC_T,    LSFT(KC_S), KC_C,                      KC_Y,    LSFT(KC_H), KC_I,    KC_A,    KC_O,    KC_RSFT,
    KC_LGUI,   LGUI(KC_Q), LCTL(KC_X), LALT(KC_M), KC_W, KC_Z, KC_MPLY, M_UPNAV, KC_J,    KC_P,    LALT(KC_DOT),LCTL(KC_MINS),LGUI(KC_SCLN), TG(3),
    KC_LCTL,   KC_ESC,  LT(2,KC_TAB), LT(1,KC_SPC), KC_ENT,               KC_COMMA, LT(1,KC_E), LT(2,KC_BSPC), KC_DEL,  KC_LALT
)
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {
    case M_QUOT:
      if (record->event.pressed) { 
        SEND_STRING("'");
      }
      return false;
    case M_DQUOT:
      if (record->event.pressed) { 
        SEND_STRING("\"");
      }
      return false;
    case M_LNAV:
      if (record->event.pressed) {
        register_code(KC_LCTL); 
        tap_code(KC_LEFT); 
        unregister_code(KC_LCTL);
      }
      return false;
    case M_RNAV: 
      if (record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_RIGHT);
        unregister_code(KC_LCTL);
      }
      return false;
    case M_UPNAV:
      if (record->event.pressed) {
        register_code(KC_LCTL); 
        tap_code(KC_UP);       
        unregister_code(KC_LCTL); 
      }
      return false;
    case M_SCREEN:
      if (record->event.pressed) {
        // Start of the screenshot macro
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_4);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
        // End of the screenshot macro
      }
      return false;
    // More macros...
  }
  return true;
}


void matrix_scan_user(void) {
  achordion_task();
}
