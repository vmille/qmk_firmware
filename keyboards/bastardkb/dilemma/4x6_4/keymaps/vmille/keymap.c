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
#include "layout.h"
#include "keycodes.h"

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
        ______________BASE_R1_LEFT______________, ______________BASE_R1_RIGHT______________,
  // ├──────────────────────────────────────────┤ ├────────────────────────────────────────┤
        ______________BASE_R2_LEFT______________, ______________BASE_R2_RIGHT______________,
  // ├──────────────────────────────────────────┤ ├────────────────────────────────────────┤
        ______________BASE_R3_LEFT______________, ______________BASE_R3_RIGHT______________,
  // ├──────────────────────────────────────────┤ ├────────────────────────────────────────┤
        ______________BASE_R4_LEFT______________, ______________BASE_R4_RIGHT______________,
  // ╰──────────────────────────────────────────┤ ├────────────────────────────────────────╯
                XXXXXXX, ______BASE_T_LEFT______, ______BASE_T_RIGHT______, XXXXXXX
  //        ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
 [FUNCTION] = LAYOUT(
 // ╭──────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
       ______________FUNCTION_R1_LEFT______________, ______________FUNCTION_R1_RIGHT______________,
 // ├──────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       ______________FUNCTION_R2_LEFT______________, ______________FUNCTION_R2_RIGHT______________,
 // ├──────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       ______________FUNCTION_R3_LEFT______________, ______________FUNCTION_R3_RIGHT______________,
 // ├──────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
       ______________FUNCTION_R4_LEFT______________, ______________FUNCTION_R4_RIGHT______________,
 // ╰──────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
               XXXXXXX, ______FUNCTION_T_LEFT______, ______FUNCTION_T_RIGHT______, XXXXXXX
 //            ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
  [NAV] = LAYOUT(
  // ╭────────────────────────────────────────╮ ╭────────────────────────────────────────╮
       ______________NAV_R1_LEFT______________, ______________NAV_R1_RIGHT______________,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       ______________NAV_R2_LEFT______________, ______________NAV_R2_RIGHT______________,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       ______________NAV_R3_LEFT______________, ______________NAV_R3_RIGHT______________,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       ______________NAV_R3_LEFT______________, ______________NAV_R4_RIGHT______________,
  // ╰────────────────────────────────────────┤ ├────────────────────────────────────────╯
               XXXXXXX, ______NAV_T_LEFT______, ______NAV_T_RIGHT______, XXXXXXX
  //      ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [IDE] = LAYOUT(
  // ╭────────────────────────────────────────╮ ╭────────────────────────────────────────╮
       ______________IDE_R1_LEFT______________, ______________IDE_R1_RIGHT______________,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       ______________IDE_R2_LEFT______________, ______________IDE_R2_RIGHT______________,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       ______________IDE_R3_LEFT______________, ______________IDE_R3_RIGHT______________,
  // ├────────────────────────────────────────┤ ├────────────────────────────────────────┤
       ______________IDE_R4_LEFT______________, ______________IDE_R4_RIGHT______________,
  // ╰────────────────────────────────────────┤ ├────────────────────────────────────────╯
               XXXXXXX, ______IDE_T_LEFT______, ______IDE_T_RIGHT______, XXXXXXX
  //      ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
    [MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────╮ ╭─────────────────────────────────────────╮
      ______________MOUSE_R1_LEFT______________, ______________MOUSE_R1_RIGHT______________,
  // ├─────────────────────────────────────────┤ ├─────────────────────────────────────────┤
      ______________MOUSE_R2_LEFT______________, ______________MOUSE_R2_RIGHT______________,
  // ├─────────────────────────────────────────┤ ├─────────────────────────────────────────┤
      ______________MOUSE_R3_LEFT______________, ______________MOUSE_R3_RIGHT______________,
  // ├─────────────────────────────────────────┤ ├─────────────────────────────────────────┤
      ______________MOUSE_R4_LEFT______________, ______________MOUSE_R4_RIGHT______________,
  // ╰─────────────────────────────────────────┤ ├─────────────────────────────────────────╯
              XXXXXXX, ______MOUSE_T_LEFT______, ______MOUSE_T_RIGHT______, XXXXXXX
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
    [BASE]     = {ENCODER_CCW_CW(RCTL(KC_Z), RCS(KC_Z)), ENCODER_CCW_CW(GUI_V_LCH, CTRL_MAJ_V_LCH)},
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
           	break;
       	case GUI_V_LCH:
           	tap_code16(RGUI(KC_V));
			layer_move(NAV);
           	break;
		case ENT_LCH:
			layer_move(BASE);
            break;
		case ESC_LCH:
           	tap_code16(KC_ESC);
			layer_move(BASE);
           	break;
   }
   return true;
}

