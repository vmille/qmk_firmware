//
// Created by Vivien on 5/1/2024.
//

#ifndef LAYOUT_H
#define LAYOUT_H

#define ______________BASE_R1_LEFT______________ KC_EQL , KC_1           , KC_2        , KC_3        , KC_4        , KC_5
#define ______________BASE_R2_LEFT______________ KC_BSLS, KC_Q           , KC_W        , KC_E        , KC_R        , KC_T
#define ______________BASE_R3_LEFT______________ KC_LPRN, LT(MOUSE, KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), RCTL_T(KC_G)
#define ______________BASE_R4_LEFT______________ KC_LBRC, KC_Z           , KC_X        , KC_C        , KC_V        , KC_B
#define ______BASE_T_LEFT______ KC_ENT, KC_BTN1, LT(NAV, KC_DEL)

#define ______________BASE_R1_RIGHT______________ KC_6        , KC_7        , KC_8        , KC_9        , KC_0   , KC_MINS
#define ______________BASE_R2_RIGHT______________ KC_Y        , KC_U        , KC_I        , KC_O        , KC_P   , KC_QUOT
#define ______________BASE_R3_RIGHT______________ RCTL_T(KC_H), LCTL_T(KC_J), LSFT_T(KC_K), LALT_T(KC_L), KC_SCLN, KC_RPRN
#define ______________BASE_R4_RIGHT______________ KC_N        , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH, KC_RBRC
#define ______BASE_T_RIGHT______ LT(FUNCTION, KC_BSPC), KC_SPC, MO(IDE)

#define ______________FUNCTION_R1_LEFT______________ KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________FUNCTION_R2_LEFT______________ XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INSERT
#define ______________FUNCTION_R3_LEFT______________ XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX
#define ______________FUNCTION_R4_LEFT______________ XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_SYRQ
#define ______FUNCTION_T_LEFT______ ENT_LCH, _______, _______

#define ______________FUNCTION_R1_RIGHT______________ CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS
#define ______________FUNCTION_R2_RIGHT______________ XXXXXXX, KC_HOME, KC_UP  , KC_PGUP, XXXXXXX, XXXXXXX
#define ______________FUNCTION_R3_RIGHT______________ KC_RCTL, KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX
#define ______________FUNCTION_R4_RIGHT______________ XXXXXXX, KC_PGDN, XXXXXXX, KC_END , XXXXXXX, XXXXXXX
#define ______FUNCTION_T_RIGHT______ _______, _______, _______

#define ______________NAV_R1_LEFT______________ ESC_LCH , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________NAV_R2_LEFT______________ RGB_MOD , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________NAV_R3_LEFT______________ RGB_TOG , XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_RCTL
#define ______________NAV_R4_LEFT______________ RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______NAV_T_LEFT______ XXXXXXX, XXXXXXX, _______

#define ______________NAV_R1_RIGHT______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX
#define ______________NAV_R2_RIGHT______________ XXXXXXX, KC_HOME, KC_UP  , KC_PGUP , XXXXXXX, XXXXXXX
#define ______________NAV_R3_RIGHT______________ XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX
#define ______________NAV_R4_RIGHT______________ XXXXXXX, KC_PGDN, XXXXXXX, KC_END  , XXXXXXX, XXXXXXX
#define ______NAV_T_RIGHT______ KC_TAB, _______, _______


#define ______________IDE_R1_LEFT______________ XXXXXXX, BUILD    , RUN    ,DEBUG   , XXXXXXX, XXXXXXX
#define ______________IDE_R2_LEFT______________ XXXXXXX, A(KC_GRV), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________IDE_R3_LEFT______________ XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________IDE_R4_LEFT______________ XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______IDE_T_LEFT______ XXXXXXX, XXXXXXX, XXXXXXX

#define ______________IDE_R1_RIGHT______________ XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________IDE_R2_RIGHT______________ XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________IDE_R3_RIGHT______________ XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________IDE_R4_RIGHT______________ XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______IDE_T_RIGHT______ XXXXXXX, XXXXXXX, XXXXXXX


#endif //LAYOUT_H
