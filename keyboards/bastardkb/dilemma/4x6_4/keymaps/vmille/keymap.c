/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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
//#include "layout.h"
//#include "keycodes.h"

enum custom_keycodes {
    CTRL_MAJ_V_LCH = SAFE_RANGE,
    GUI_V_LCH,
    ENT_LCH,
    ESC_LCH,
    NEW_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};

#define BUILD RCTL(KC_F9)
#define RUN S(KC_F9)
#define DEBUG S(KC_F10)

enum dilemma_keymap_layers {
    BASE = 0,
	FUNCTION,
    NAV,
    IDE,
	MOUSE
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
  // ╭──────────────────────────────────────────╮ ╭────────────────────────────────────────╮
        KC_EQL , KC_1           , KC_2        , KC_3        , KC_4        , KC_5, KC_6        , KC_7        , KC_8        , KC_9        , KC_0   , KC_MINS,
  // ├──────────────────────────────────────────┤ ├────────────────────────────────────────┤
        KC_BSLS, KC_Q           , KC_W        , KC_E        , KC_R        , KC_T, KC_Y        , KC_U        , KC_I        , KC_O        , KC_P   , KC_QUOT,
  // ├──────────────────────────────────────────┤ ├────────────────────────────────────────┤
       KC_GRV , LT(MOUSE, KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), RCTL_T(KC_G), RCTL_T(KC_H), LCTL_T(KC_J), LSFT_T(KC_K), LALT_T(KC_L), KC_SCLN,KC_LWIN ,
  // ├──────────────────────────────────────────┤ ├────────────────────────────────────────┤
        KC_LBRC, KC_Z           , KC_X        , KC_C        , KC_V        , KC_B, KC_N        , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH, KC_RBRC,
  // ╰──────────────────────────────────────────┤ ├────────────────────────────────────────╯
                XXXXXXX, KC_ENT, KC_BTN1, LT(NAV, KC_DEL), LT(FUNCTION, KC_BSPC), KC_SPC, MO(IDE), XXXXXXX
  //        ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
 [FUNCTION] = LAYOUT(
 // ╭──────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       KC_ESC , KC_CAPS,CG_LSWP,XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 // ├──────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INSERT, XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX,
 // ├──────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, KC_RCTL, KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX,
 // ├──────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_SYRQ, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX,
 // ╰──────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
               XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX
 //            ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
  [NAV] = LAYOUT(
  // ╭────────────────────────────────────────╮ ╭────────────────────────────────────────╮
       ESC_LCH , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
        RGB_MOD , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WBAK, KC_HOME, KC_UP  , KC_PGUP , XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       RGB_TOG , XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_RCTL, KC_WFWD, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, KC_END  , XXXXXXX, XXXXXXX,
  // ╰────────────────────────────────────────┤ ├────────────────────────────────────────╯
               XXXXXXX,  ENT_LCH, _______, _______, KC_TAB, _______, _______, XXXXXXX
  //      ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [IDE] = LAYOUT(
  // ╭────────────────────────────────────────╮ ╭────────────────────────────────────────╮
       XXXXXXX, BUILD    , RUN    ,DEBUG   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       XXXXXXX, A(KC_GRV), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰────────────────────────────────────────┤ ├────────────────────────────────────────╯
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //      ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
    [MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────╮ ╭─────────────────────────────────────────╮
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────┤ ├─────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WBAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────┤ ├─────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────┤ ├─────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, C(KC_X), C(KC_C), C(KC_V), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────┤ ├─────────────────────────────────────────╯
              XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //      ╰────────────────────────────────────╯ ╰────────────────────────────────────╯
  ),
};
// clang-format on

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.7
void rgb_matrix_update_pwm_buffers(void);
#endif

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE]     = {ENCODER_CCW_CW(LCTL(KC_Z), LCTL(LSFT(KC_Z))), ENCODER_CCW_CW(GUI_V_LCH, CTRL_MAJ_V_LCH)},
    [FUNCTION] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [NAV]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [IDE]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [MOUSE]    = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
};

// clang-format on
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    	case CTRL_MAJ_V_LCH:
      	    tap_code16(RCS(KC_V));
            layer_move(NAV);
           	return false;
       	case GUI_V_LCH:
           	tap_code16(RGUI(KC_V));
			layer_move(NAV);
           	return false;
		case ENT_LCH:
			layer_move(BASE);
           	break;
		case ESC_LCH:
           	tap_code16(KC_ESC);
			layer_move(BASE);
           	return false;
   }
   return true;
}

bool rgb_matrix_indicators_user(void) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case NAV:
            rgb_matrix_set_color_all(0xFF, 0xFF, 0x00);  // RGB yellow
            break;
        default:
            break;
    }
    return false;
}