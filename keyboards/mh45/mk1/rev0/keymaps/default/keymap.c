/* Copyright 2019 Marcus Heese
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

#define _BASE 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( /* Base */
        KC_ESC,    KC_Q,     KC_P,    KC_Y,    KC_C, KC_B,     KC_V,      KC_M,    KC_U,    KC_Z,     KC_L,   KC_MINUS,  KC_BSPACE,
        KC_TAB,    KC_A,     KC_N,    KC_I,    KC_S, KC_F,     KC_D,      KC_T,    KC_H,    KC_O,     KC_R,   KC_QUOTE,  KC_ENTER,
        KC_LSHIFT, KC_COMMA, KC_DOT,  KC_J,    KC_G, KC_SLASH, KC_SCOLON, KC_W,    KC_K,    KC_X,     KC_UP,  KC_RSHIFT,
        MO(_FN),   KC_LCTRL, KC_LALT, KC_LGUI, KC_E, KC_SPACE, KC_RGUI,   KC_LEFT, KC_DOWN, KC_RIGHT, MO(_FN)
    ),
    [_FN] = LAYOUT(
        LSFT(KC_GRAVE), LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_4),  LSFT(KC_5),     LSFT(KC_6),     LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_EQUAL), KC_DELETE,
        KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,        KC_5,           KC_6,           KC_7,       KC_8,       KC_9,       KC_0,       KC_EQUAL,       KC_TRANSPARENT,
        KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_LBRACKET, KC_BSLASH,      KC_RBRACKET,    KC_NO,      KC_NO,      KC_NO,      KC_PGUP,    KC_TRANSPARENT,
        KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,       KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,    KC_PGDOWN,  KC_END,     KC_NO
    )
};
