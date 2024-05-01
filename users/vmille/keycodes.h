//
// Created by Vivien on 5/1/2024.
//

#pragma once




enum my_keycodes {
    CTRL_MAJ_V_LCH = SAFE_RANGE,
    GUI_V_LCH,
    ENT_LCH,
    ESC_LCH,
};

#define BUILD RCTL(KC_F9)
#define RUN S(KC_F9)
#define DEBUG S(KC_F10)


const key_override_t left_parenthesis_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_TILD);
const key_override_t right_parenthesis_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_GRV);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &left_parenthesis_key_override,
    &right_parenthesis_key_override,
    NULL // Null terminate the array of overrides!
};

