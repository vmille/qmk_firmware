#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _BASE = 0,
    _FUNCTION,
    _NAVIGATION
};

enum unicode_names {
    POINT_MEDIAN = SAFE_RANGE,
    LCTL_CMD_T,
    RCTL_CMD_T,
    CMD_CTL,
    SWITCH_CMD_CTL,
    PRINT_CMD_CTL
};

enum cmd_ctl_e {
    CTL, CMD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: BASE
 *
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4       |   5   |      |           |      |   6   |   7       |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+-----------+--------------|           |------+-------+-----------+------+------+------+--------|
 * |   /    |   Q  |   W  |   E  |   R       |   T   |      |           |      |   Y   |   U       |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+-----------+-------|      |           |      |-------+-----------+------+------+------+--------|
 * | (&Shif |   A  |S&LAlt|D&Shif|F&LCTL_CMD |G&LCTL |------|           |------|H&RCTL |J&RCTL_CMD |K&Shif|L&LAlt|   ;  | )&Shif |
 * |--------+------+------+------+-----------+-------|      |           |      |-------+-----------+------+------+------+--------|
 * |    [   |   Z  |   X  |   C  |   V       |   B   |      |           |      |   N   |   M       |   ,  |   .  |   /  |   ]    |
 * `--------+------+------+------+-----------+--------------'           `--------------+-----------+------+------+------+--------'
 *   |BSpace|Escape| Wox  |   ç  |           |                                         |           |  `   | Win  |   ·  | Del  |
 *   `---------------------------------------'                                         `---------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+----.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  NAV | Enter|------|       |------| Space| FUNC |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_BASE] = LAYOUT_ergodox_pretty(
  // left hand
    KC_EQUAL, KC_1  , KC_2        , KC_3         , KC_4      ,    KC_5        ,    _______,             _______, KC_6        , KC_7      , KC_8        , KC_9        , KC_0        , KC_MINUS,
    KC_BSLS , KC_Q  , KC_W        , KC_E         , KC_R      ,    KC_T        ,    _______,             _______, KC_Y        , KC_U      , KC_I        , KC_O        , KC_P        , KC_QUOTE,
    KC_LSPO , KC_A  , LALT_T(KC_S), LSFT_T(KC_D) , LCTL_CMD_T,    LCTL_T(KC_G),                                  RCTL_T(KC_H), RCTL_CMD_T, RSFT_T(KC_K), LALT_T(KC_L), KC_SCLN     , KC_RSPC ,
    KC_LCBR , KC_Z  , KC_X        , KC_C         , KC_V      ,    KC_B        ,    _______,             KC_RCMD, KC_N        , KC_M      , KC_COMM     , KC_DOT      , KC_SLSH     , KC_RCBR ,
    KC_DEL  , KC_ESC, LALT(KC_SPC), RALT(KC_COMM), _______   ,                                                    _______    , KC_GRAVE  , KC_LGUI     , POINT_MEDIAN, KC_BSPC ,
                                                                _______, _______,                       _______, _______,
                                                                         _______,                       _______,
                                              MO(_NAVIGATION), KC_ENTER, _______,                       _______, KC_SPC, MO(_FUNCTION)
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,-----------------------------------------------------------------------.
 * |  Escape |      |      |      |      |      |      |           |      | Switch CMD/CTL | Print CMD/CTL |      |      |      |CapsLock|
 * |---------+------+------+------+------+------+------|           |------+-----------------+----------------+------+------+------+--------|
 * |         |  F1  |  F2  |  F3  |  F4  | Ins  |      |           |      |                 |                |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |-----------------+----------------+------+------+------+--------|
 * |         |  F5  |  F6  |  F7  |  F8  |      |------|           |------|       Ctl       | CMD_CTL        |Shift |L-Alt |      |        |
 * |---------+------+------+------+------+------|      |           |      |-----------------+----------------+------+------+------+--------|
 * |         |  F9  | F10  | F11  | F12  |SysRq |      |           |      |                 |                |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `------------------------+----------------+------+------+------+--------'
 *   |       |      |      |      |      |                                                  |                |      |      |      |      |
 *   `-----------------------------------'                                                  `--------------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_FUNCTION] = LAYOUT_ergodox_pretty(
  // left hand
    KC_ESC , _______, _______, _______, _______, _______  , _______,            _______, SWITCH_CMD_CTL, PRINT_CMD_CTL, _______, _______, _______, KC_CAPS,
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INSERT, _______,            _______, _______        , _______     , _______, _______, _______, _______,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______  ,                              KC_LCTL        , CMD_CTL     , KC_LSFT, KC_LALT, _______, _______,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_SYRQ  , _______,            _______, _______        , _______     , _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                          _______     , _______, _______, _______, _______,
                                             _______, _______,                      _______, _______,
                                                      _______,                      _______,
                                    _______, _______, _______,                      _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * | Escape |      |      |      |        |      |Reset |           |      |      |      |      |      |      |CapsLock|
 * |--------+------+------+------+--------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |        |      |      |           |      |      | Home |  Up  | PgUp | W-Up |        |
 * |--------+------+------+------+--------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LAlt | Shift|CMD_CTL | CTL  |------|           |------|      | Left | Down |Right |W-Down|        |
 * |--------+------+------+------+--------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |        |      |      |           |      |      | PgDn |      | End  |      |        |
 * `--------+------+------+------+--------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |        |                                       |      |      |      |      |        |
 *   `------------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  Tab |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NAVIGATION] = LAYOUT_ergodox_pretty(
  // left hand
    KC_ESC , _______, _______, _______, _______, _______, QK_BOOT,            _______, _______, _______, _______, _______ , _______      , KC_CAPS,
    _______, _______, _______, _______, _______, _______, _______,            _______, _______, KC_HOME, KC_UP  , KC_PGUP , KC_MS_WH_UP  , _______,
    _______, _______, KC_LALT, KC_LSFT, CMD_CTL, KC_LCTL,                              _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MS_WH_DOWN, _______,
    _______, _______, _______, _______, _______, _______, _______,            _______, _______, KC_PGDN, _______, KC_END  , _______      , _______,
    _______, _______, _______, _______, _______,                                                _______, _______, _______ , _______      , _______,
                                                                     _______, _______,                     _______, _______,
                                                                              _______,                     _______,
                                                            _______, _______, _______,                     _______, KC_TAB , _______
),
};

enum cmd_ctl_e current_modifier = CTL;

static uint16_t r_hash_timer;
static uint16_t l_hash_timer;
static uint16_t r_ctl_or_cmd;
static uint16_t l_ctl_or_cmd;

enum pressed_e { 
    NOTHING, PRESSED_LEFT_CTL_CMD, PRESSED_RIGHT_CTL_CMD
};

enum pressed_e current_pressed = NOTHING;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case POINT_MEDIAN:
            if (record->event.pressed) {
                // when keycode POINT_MEDIAN is pressed
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_8)SS_TAP(X_KP_3)SS_UP(X_LALT));
            } else {
                // when keycode POINT_MEDIAN is released
            }
            return false;
            break;
        case SWITCH_CMD_CTL:
            if (record->event.pressed) {
                if (current_modifier == CTL) {
                    current_modifier = CMD;
                    l_ctl_or_cmd = KC_LEFT_GUI;
                    r_ctl_or_cmd = KC_LEFT_GUI;
                }
                else {
                    current_modifier = CTL;
                    l_ctl_or_cmd = KC_RIGHT_CTRL;
                    r_ctl_or_cmd = KC_RIGHT_CTRL;
                }
                return false;
            }
            break;
        case PRINT_CMD_CTL:
            if (record->event.pressed) {
                if (current_modifier == CTL) {
                    SEND_STRING("CTL");
                } else {
                    SEND_STRING("CMD");
                }
                return false;
            }
            break;
        case LCTL_CMD_T:
            if (current_pressed == PRESSED_RIGHT_CTL_CMD) {
                if (record->event.pressed) {
                    tap_code(KC_F);
                }
            }
            else {
                if (record->event.pressed) {
                    l_hash_timer = timer_read();
                    register_code(l_ctl_or_cmd);
                    current_pressed = PRESSED_LEFT_CTL_CMD;
                }
                else {
                    unregister_code(l_ctl_or_cmd);
                    current_pressed = NOTHING;
                    if (timer_elapsed(l_hash_timer) < TAPPING_TERM) {
                        tap_code(KC_F);
                    }
                }
            }
            return false;
        case RCTL_CMD_T:
            if (current_pressed == PRESSED_LEFT_CTL_CMD) {
                if (record->event.pressed) {
                    tap_code(KC_J);
                }
            }
            else {
                if (record->event.pressed) {
                    r_hash_timer = timer_read();
                    register_code(r_ctl_or_cmd);
                    current_pressed = PRESSED_RIGHT_CTL_CMD;
                }
                else {
                    unregister_code(r_ctl_or_cmd);
                    current_pressed = NOTHING;
                    if (timer_elapsed(r_hash_timer) < TAPPING_TERM) {
                        tap_code(KC_J);
                    }
                }
            }
            return false;
            break;
        case CMD_CTL:
            if (record->event.pressed) {
                register_code(l_ctl_or_cmd);
            }
            else {
                unregister_code(l_ctl_or_cmd);
            }
            return false;
            break;
    }
    return true;
}
