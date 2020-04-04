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

/* IntelliSense START
 * Only necessary to satisfy VSCode
 */
#ifdef __INTELLISENSE__
#include "../../config.h"
#define QMK_KEYBOARD_H "../../rev0.h"
#endif
/* IntelliSense END */

#include QMK_KEYBOARD_H

#define _LAYER_BASE 0
#define _LAYER_NUM 1
#define _LAYER_SYM 2
#define _LAYER_FN 3
#define _LAYER_NAV 4
#define _LAYER_SYS 5

// Keep these layer definitions handy here, it is a lot simpler that way
//
// MO(layer) - momentarily activates layer. As soon as you let go of the key, the layer is deactivated.
// LT(layer, kc) - momentarily activates layer when held, and sends kc when tapped. Only supports layers 0-15.
// TG(layer) - toggles layer, activating it if it’s inactive and vice versa
// TT(layer) - Layer Tap-Toggle. If you hold the key down, layer is activated, and then is de-activated when you let go (like MO). If you repeatedly tap it, the layer will be toggled on or off (like TG). It needs 5 taps by default, but you can change this by defining TAPPING_TOGGLE – for example, #define TAPPING_TOGGLE 2 to toggle on just two taps.
// KC_LSPO - tap ( , hold SHIFT
// KC_RSPC - tap ) , hold SHIFT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER_BASE] = LAYOUT( /* Base */
        KC_ESC,                 KC_Q,     KC_P,    KC_Y,    KC_C,                 KC_B,                     KC_V,      KC_M,    KC_U,    KC_Z,           KC_L,         KC_EQUAL, KC_BSPACE,
        LT(_LAYER_NAV, KC_TAB), KC_A,     KC_N,    KC_I,    KC_S,                 KC_F,                     KC_D,      KC_T,    KC_H,    KC_O,           KC_R,         KC_QUOTE, LT(_LAYER_NAV, KC_ENTER),
        KC_LSFT,                KC_COMMA, KC_DOT,  KC_J,    KC_G,                 KC_SLASH,                 KC_SCOLON, KC_W,    KC_K,    KC_MINUS,       KC_X,         KC_RSFT,
        MO(_LAYER_FN),          KC_LCTRL, KC_LALT, KC_LGUI, LT(_LAYER_NUM, KC_E), LT(_LAYER_SYM, KC_SPACE), KC_RGUI,   KC_RALT, KC_RCTL, TG(_LAYER_NAV), MO(_LAYER_FN)
    ),
    [_LAYER_NUM] = LAYOUT( /* Numbers */
        KC_ESC,         KC_NO,    KC_NO,   KC_NO,   KC_NO,          KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,          KC_DELETE, KC_BSPACE,
        KC_NO,          KC_1,     KC_2,    KC_3,    KC_4,           KC_5,     KC_6,    KC_7,    KC_8,    KC_9,  KC_0,           KC_NO,     KC_ENTER,
        KC_NO,          KC_NO,    KC_NO,   KC_NO,   KC_NO,          KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,          KC_NO,
        KC_NO,          KC_LCTRL, KC_LALT, KC_LGUI, KC_TRANSPARENT, KC_ENTER, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, KC_NO
    ),
    [_LAYER_SYM] = LAYOUT( /* Symbols */
        KC_ESC,         KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_DELETE, KC_BSPACE,
        KC_NO,          LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),     LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),     KC_NO,     KC_ENTER,
        KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,
        KC_NO,          KC_LCTRL,   KC_LALT,    KC_LGUI,    KC_BSPACE,  KC_TRANSPARENT, KC_RGUI,    KC_RALT,    KC_RCTL,    KC_NO,      KC_NO
    ),
    [_LAYER_FN] = LAYOUT( /* FN */
        KC_ESC,         KC_NO,             KC_NO,             KC_NO,       KC_NO,          KC_NO,           KC_NO,     KC_NO,    KC_NO,          KC_NO,  KC_NO,          KC_NO, KC_DELETE,
        KC_NO,          LSFT(KC_LBRACKET), LSFT(KC_RBRACKET), KC_LBRACKET, KC_RBRACKET,    LSFT(KC_BSLASH), KC_BSLASH, KC_GRAVE, LSFT(KC_GRAVE), KC_NO,  KC_NO,          KC_NO, KC_NO,
        KC_NO,          KC_NO,             KC_NO,             KC_NO,       KC_NO,          KC_NO,           KC_NO,     KC_NO,    KC_NO,          KC_NO,  KC_PGUP,        KC_NO,
        KC_TRANSPARENT, KC_LCTRL,          KC_LALT,           KC_LGUI,     MO(_LAYER_SYS), MO(_LAYER_SYS),  KC_RGUI,   KC_HOME,  KC_PGDOWN,      KC_END, KC_TRANSPARENT
    ),
    [_LAYER_NAV] = LAYOUT( /* Navigation */
        KC_ESC,         KC_NO,    KC_NO,   KC_UP,   KC_NO,     KC_NO,    KC_NO,          KC_NO,   KC_UP,   KC_NO,    KC_NO,         KC_DELETE, KC_BSPACE,
        KC_TRANSPARENT, KC_NO,    KC_LEFT, KC_DOWN, KC_RIGHT,  KC_NO,    KC_NO,          KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,         KC_NO,     KC_ENTER,
        KC_LSFT,        KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,          KC_NO,   KC_NO,   KC_NO,    KC_UP,         KC_RSFT,
        MO(_LAYER_FN),  KC_LCTRL, KC_LALT, KC_LGUI, KC_BSPACE, KC_SPACE, TG(_LAYER_NAV), KC_LEFT, KC_DOWN, KC_RIGHT, MO(_LAYER_FN)
    ),
    [_LAYER_SYS] = LAYOUT( /* System */
        RESET, DEBUG,              KC_NO,            KC_NO,             KC_NO,           KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EEPROM_RESET,
        KC_NO, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,              KC_NO,            KC_NO,             KC_NO,           KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,              KC_NO,            KC_NO,             KC_NO,           KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};
