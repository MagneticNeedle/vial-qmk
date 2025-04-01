/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
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

// clang-format off

#include QMK_KEYBOARD_H
#include "oled.c"
// #include "rgb.c"


// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
     KC_ESCAPE,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,            KC_6,           KC_7,           KC_8,           KC_9,           KC_0,       KC_GRAVE,
        KC_TAB,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,        KC_BSPC,
       KC_LSFT,           KC_A,           KC_S,           KC_D,           KC_F,           KC_G,            KC_H,           KC_J,           KC_K,           KC_L,        KC_SCLN,       KC_QUOTE,
       KC_LCTL,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,            KC_N,           KC_M,       KC_COMMA,         KC_DOT,       KC_SLASH,      KC_RSFT,
       KC_LCTL,        KC_LALT,        KC_LGUI,          MO(2),        KC_BSPC,        KC_CAPS,         KC_MUTE,       KC_SPACE,          MO(3),       KC_ENTER,        KC_LCTL,       KC_RCTL
	),
	[1] = LAYOUT(
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
       KC_TRNS,        KC_LALT,       KC_SPACE,           KC_V,       KC_SPACE,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
	),
	[2] = LAYOUT(
       KC_TRNS,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,           KC_F6,          KC_F7,          KC_F8,          KC_F9,         KC_F10,         KC_F11,
       KC_TRNS,       KC_GRAVE, LSFT(KC_GRAVE),     LSFT(KC_3),     LSFT(KC_7),  LSFT(KC_BSLS),  LSFT(KC_EQUAL),  LSFT(KC_LBRC),  LSFT(KC_RBRC),        KC_LBRC,        KC_RBRC,         KC_F12,
       KC_TRNS,     LSFT(KC_1), LSFT(KC_MINUS),  LSFT(KC_SCLN),       KC_EQUAL,     LSFT(KC_4),      LSFT(KC_2),     LSFT(KC_9),     LSFT(KC_0), LSFT(KC_MINUS),  LSFT(KC_SCLN), LSFT(KC_QUOTE),
       KC_TRNS,     LSFT(KC_5), LSFT(KC_SLASH),     LSFT(KC_8), LSFT(KC_EQUAL),        KC_BSLS,        KC_SLASH,       KC_MINUS, LSFT(KC_COMMA),   LSFT(KC_DOT), LSFT(KC_SLASH),        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_BSPC,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
),
	[3] = LAYOUT(
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
       KC_TRNS,      KC_INSERT,        KC_PSCR, KC_APPLICATION,          KC_NO,          KC_NO,         KC_PGUP,        KC_TRNS,          KC_UP,        KC_TRNS,        KC_TRNS,        KC_BSPC,
       KC_TRNS,        KC_LALT,        KC_LCTL,        KC_LSFT,          KC_NO,        KC_CAPS,         KC_PGDN,        KC_LEFT,        KC_DOWN,       KC_RIGHT,      KC_DELETE,        KC_BSPC,
       KC_TRNS,     LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),          KC_NO,           KC_NO,        KC_TRNS,          KC_NO,        KC_TRNS,          KC_NO,        KC_TRNS,
       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
	)
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
        uprintf(
            "KL: kc: 0x%04X, row: %2u, col: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
            keycode,
            record->event.key.row,
            record->event.key.col,
            record->event.pressed,
            record->event.time,
            record->tap.interrupted,
            record->tap.count
        );
    #endif
    return true;
}
