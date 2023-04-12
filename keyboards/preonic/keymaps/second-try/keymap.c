/* Copyright 2015-2017 Jack Humbert
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

enum preonic_layers {
    _BASE_CTL = 0,
    _FUNCTION_CTL,
    _NAVIGATION_CTL,
    _BASE_CMD,
    _FUNCTION_CMD,
    _NAVIGATION_CMD,
};

enum my_keycodes {
    PRINT_CTL = SAFE_RANGE,
    PRINT_CMD
};

enum unicode_names {
    POINT_MEDIAN
};

const uint32_t unicode_map[] PROGMEM = {
    [POINT_MEDIAN]  = 0x00B7,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * |  =   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  /   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |(&Shif|   A  |S&LAlt|D&Shif|F&Ctrl|   G  |   H  |J&Ctrl|K&Shif|L&RAlt|   ;  |)&Shif|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  [   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,   |  .   |   /  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BSpace|Escape| Wox  |   ç  | NAV  |Enter |Space | FUNC |  `   | Win  |   ·  | Del  |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE_CTL] = LAYOUT_preonic_grid(
        KC_EQUAL, KC_1  , KC_2        , KC_3         , KC_4               , KC_5        , KC_6        , KC_7             , KC_8        , KC_9        , KC_0           , KC_MINUS,
        KC_BSLS , KC_Q  , KC_W        , KC_E         , KC_R               , KC_T        , KC_Y        , KC_U             , KC_I        , KC_O        , KC_P           , KC_QUOTE,
        KC_LSPO , KC_A  , LALT_T(KC_S), LSFT_T(KC_D) , LCTL_T(KC_F)       , LCTL_T(KC_G), RCTL_T(KC_H), RCTL_T(KC_J)     , RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN        , KC_RSPC ,
        KC_LBRC , KC_Z  , KC_X        , KC_C         , KC_V               , KC_B        , KC_N        , KC_M             , KC_COMM     , KC_DOT      , KC_SLSH        , KC_RBRC ,
        KC_DEL  , KC_ESC, LALT(KC_SPC), RALT(KC_COMM), MO(_NAVIGATION_CTL), KC_ENTER    , KC_SPC      , MO(_FUNCTION_CTL), KC_GRAVE    , KC_LGUI     , X(POINT_MEDIAN), KC_BSPC
),

/* FUNCTION
 * ,-----------------------------------------------------------------------------------.
 * |Escape|      |      |      |      |      |      |      |      |      |      |CapsLo|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  | Ins  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      | Ctrl |Shift |L-Alt |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  |SysRq |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION_CTL] = LAYOUT_preonic_grid(
    KC_ESC , _______, _______, _______, _______, _______  , DF(_BASE_CMD), PRINT_CTL, _______, _______, _______, KC_CAPS,
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INSERT, _______      , _______  , _______, _______, _______, _______,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______  , KC_LCTL      , KC_LCTL  , KC_LSFT, KC_LALT, _______, _______,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_SYRQ  , _______      , _______  , _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______  , _______      , _______  , _______, _______, _______, _______
),

/* NAVIGATION
 * ,-----------------------------------------------------------------------------------.
 * |Escape|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  1   |  2   |  3   |      |      | Home |  Up  | PgUp | W-Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |4&LAlt|5&Shif|6&Ctrl|  0   |      | Left | Down |Right |W-Down|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  7   |  8   |  9   |      |      | PgDn |      | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Tab  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIGATION_CTL] = LAYOUT_preonic_grid(
    KC_ESC , _______, _______        , _______        , _______        , QK_BOOT        , _______, _______, _______, _______ , _______      , _______,
    _______, _______, KC_KP_1        , KC_KP_2        , KC_KP_3        , _______        , _______, KC_HOME, KC_UP  , KC_PGUP , KC_MS_WH_UP  , _______,
    _______, _______, LALT_T(KC_KP_4), LSFT_T(KC_KP_5), LCTL_T(KC_KP_6), LCTL_T(KC_KP_0), _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MS_WH_DOWN, _______,
    _______, _______, KC_KP_7        , KC_KP_8        , KC_KP_9        , _______        , _______, KC_PGDN, _______, KC_END  , _______      , _______,
    _______, _______, _______        , _______        , _______        , _______        , KC_TAB , _______, _______, _______ , _______      , _______
),
    /* BASE
 * ,-----------------------------------------------------------------------------------.
 * |  =   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  /   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |(&Shif|   A  |S&LAlt|D&Shif|F&Ctrl|   G  |   H  |J&Ctrl|K&Shif|L&RAlt|   ;  |)&Shif|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  [   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,   |  .   |   /  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BSpace|Escape| Wox  |   ç  | NAV  |Enter |Space | FUNC |  `   | Win  |   ·  | Del  |
 * `-----------------------------------------------------------------------------------'
     */
    [_BASE_CMD] = LAYOUT_preonic_grid(
        KC_EQUAL, KC_1  , KC_2        , KC_3         , KC_4               , KC_5        , KC_6        , KC_7             , KC_8        , KC_9        , KC_0           , KC_MINUS,
        KC_BSLS , KC_Q  , KC_W        , KC_E         , KC_R               , KC_T        , KC_Y        , KC_U             , KC_I        , KC_O        , KC_P           , KC_QUOTE,
        KC_LSPO , KC_A  , LALT_T(KC_S), LSFT_T(KC_D) , LCMD_T(KC_F)       , LCTL_T(KC_G), RCTL_T(KC_H), RCMD_T(KC_J)     , RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN        , KC_RSPC ,
        KC_LBRC , KC_Z  , KC_X        , KC_C         , KC_V               , KC_B        , KC_N        , KC_M             , KC_COMM     , KC_DOT      , KC_SLSH        , KC_RBRC ,
        KC_DEL  , KC_ESC, LALT(KC_SPC), RALT(KC_COMM), MO(_NAVIGATION_CMD), KC_ENTER    , KC_SPC      , MO(_FUNCTION_CMD), KC_GRAVE    , LCMD(KC_SPC), X(POINT_MEDIAN), KC_BSPC
        ),

    /* FUNCTION
 * ,-----------------------------------------------------------------------------------.
 * |Escape|      |      |      |      |      |      |      |      |      |      |CapsLo|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  | Ins  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      | Ctrl |Shift |L-Alt |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  |SysRq |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
     */
    [_FUNCTION_CMD] = LAYOUT_preonic_grid(
        KC_ESC , _______, _______, _______, _______, _______  , DF(_BASE_CTL), PRINT_CMD, _______, _______, _______, KC_CAPS,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INSERT, _______      , _______  , _______, _______, _______, _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______  , KC_LCTL      , KC_LCMD  , KC_LSFT, KC_LALT, _______, _______,
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_SYRQ  , _______      , _______  , _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______  , _______      , _______  , _______, _______, _______, _______
        ),

    /* NAVIGATION
 * ,-----------------------------------------------------------------------------------.
 * |Escape|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  1   |  2   |  3   |      |      | Home |  Up  | PgUp | W-Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |4&LAlt|5&Shif|6&Ctrl|  0   |      | Left | Down |Right |W-Down|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  7   |  8   |  9   |      |      | PgDn |      | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Tab  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
     */
    [_NAVIGATION_CMD] = LAYOUT_preonic_grid(
        KC_ESC , _______, _______        , _______        , _______        , QK_BOOT        , _______, _______, _______, _______ , _______      , _______,
        _______, _______, KC_KP_1        , KC_KP_2        , KC_KP_3        , _______        , _______, KC_HOME, KC_UP  , KC_PGUP , KC_MS_WH_UP  , _______,
        _______, _______, LALT_T(KC_KP_4), LSFT_T(KC_KP_5), LCMD_T(KC_KP_6), LCTL_T(KC_KP_0), _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MS_WH_DOWN, _______,
        _______, _______, KC_KP_7        , KC_KP_8        , KC_KP_9        , _______        , _______, KC_PGDN, _______, KC_END  , _______      , _______,
        _______, _______, _______        , _______        , _______        , _______        , KC_TAB , _______, _______, _______ , _______      , _______
        )
};
ee\eeeeeeeeeee\\\\\\\\eeee\\eeqqqq
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Paaqq11RINT_CTL:
            if (record->event.pressed) {
                SEND_STRING("CTL");
            }
            else {
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
            }
            break;
        case PRINT_CMD:
            if (record->event.pressed) {
                SEND_STRING("CMD");
            }
            else {
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
            }
            break;
    }
    return true;
}


