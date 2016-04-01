#include "ergodox_ez.h"
#include "action_layer.h"
#include "keymap_common.h"

#define UM 0

#define L0   0      // layer_0
#define L1   1      // layer_2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * .-------------------------------------.------------------------------------.
 * |LBRC | 1  | 2  | 3  | 4   | 5  |LGUI | 6   | 7  | 8  | 9  | 0  |RBRC| EQL |
 * !-----+----+----+----+-----+----------!-----+----+----+----+----+----+-----!
 * |TAB  |QUOT|COMM|DOT | P   | Y  |INS  |PGUP | F  | G  | C  | R  | L  | SLSH|
 * !-----+----+----+----x-----x----!     !     !----x----x----+----+----+-----!
 * |CAPS | A  | O  | E  | U   | I  |-----!-----! D  | H  | T  | N  | S  | MINS|
 * !-----+----+----+----x-----x----!     !     !----x----x----+----+----+-----!
 * |LSFT |COLN| Q  | J  | K   | X  |TILD |PGDN | B  | M  | W  | V  | Z  | LSFT|
 * '-----+----+----+----+-----+----------'----------+----+----+----+----+-----'
 *  |LCTL|LALT|BSLS|RGHT|ENTER|                    !ENTER| UP |DOWN|LEFT|RGHT|
 *  '-------------------------'                    '------------------------'
 *                         .-----------. .---------.
 *                         |DEL  |ESC  | !VOLU|HYPR|
 *                   .-----+-----+-----! !----+----+-----.
 *                   !     !     | END | !VOLD|    !     !
 *                   !     !     !-----! !----!    !     !
 *                   |SPACE|BSPC |HOME | !PGDN|TAB |SPACE|
 *                   '-----------------' '---------------'
*/
[L0] = KEYMAP(
 KC_LBRC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LGUI,
 KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_INS,
 KC_CAPS, KC_A, KC_O, KC_E, KC_U, KC_I,
 KC_LSFT, KC_COLN, KC_Q, KC_J, KC_K, KC_X, KC_TILD,
 KC_LCTL, KC_LALT, KC_BSLS, KC_RGHT, KC_ENTER,
 KC_DEL, KC_ESC,
 KC_END,
 KC_SPACE, KC_BSPC, KC_HOME,
 KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC, KC_EQL,
 KC_PGUP, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
 KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
 KC_PGDN, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_LSFT,
 KC_ENTER, KC_UP, KC_DOWN, KC_LEFT, KC_RGHT,
 KC_VOLU, KC_HYPR,
 KC_VOLD,
 KC_PGDN, KC_TAB, KC_SPACE
),
/*
 * .------------------------------------.------------------------------------.
 * |     |    |    |    |    |    |     |     |    |    |    |    |    |     |
 * !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
 * |     |    |    |    |    |    |     |     |    |    |    |    |    |     |
 * !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
 * |     |    |    |    |    |    |-----!-----!    |    |    |    |    |     |
 * !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
 * |     |    |    |    |    |    |     |     |    |    |    |    |    |     |
 * '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
 *  |    |    |    |    |    |                     !    |    |    |    |    |
 *  '------------------------'                     '------------------------'
 *                         .-----------. .-----------.
 *                         |     |     | !     |     |
 *                   .-----+-----+-----! !-----+-----+-----.
 *                   !     !     |     | !     |     !     !
 *                   !     !     !-----! !-----!     !     !
 *                   |     |     |     | !     |     |     |
 *                   '-----------------' '-----------------'
*/
[L1] = KEYMAP(
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS,
 KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS,
 KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {};

#define UC_MODE_WIN 0
#define UC_MODE_LINUX 1
#define UC_MODE_OSX 2

// TODO: allow default mode to be configured
static uint16_t unicode_mode = UC_MODE_WIN;

uint16_t hextokeycode(uint8_t hex) {
    if (hex == 0x0) {
        return KC_P0;
    }
    if (hex < 0xA) {
        return KC_P1 + (hex - 0x1);
    }
    return KC_A + (hex - 0xA);
}

void unicode_action_function(uint16_t hi, uint16_t lo) {
    switch (unicode_mode) {
    case UC_MODE_WIN:
        register_code(KC_LALT);

        register_code(KC_PPLS);
        unregister_code(KC_PPLS);

        register_code(hextokeycode((hi & 0xF0) >> 4));
        unregister_code(hextokeycode((hi & 0xF0) >> 4));
        register_code(hextokeycode((hi & 0x0F)));
        unregister_code(hextokeycode((hi & 0x0F)));
        register_code(hextokeycode((lo & 0xF0) >> 4));
        unregister_code(hextokeycode((lo & 0xF0) >> 4));
        register_code(hextokeycode((lo & 0x0F)));
        unregister_code(hextokeycode((lo & 0x0F)));

        unregister_code(KC_LALT);
        break;
    case UC_MODE_LINUX:
        register_code(KC_LCTL);
        register_code(KC_LSFT);

        register_code(KC_U);
        unregister_code(KC_U);

        register_code(hextokeycode((hi & 0xF0) >> 4));
        unregister_code(hextokeycode((hi & 0xF0) >> 4));
        register_code(hextokeycode((hi & 0x0F)));
        unregister_code(hextokeycode((hi & 0x0F)));
        register_code(hextokeycode((lo & 0xF0) >> 4));
        unregister_code(hextokeycode((lo & 0xF0) >> 4));
        register_code(hextokeycode((lo & 0x0F)));
        unregister_code(hextokeycode((lo & 0x0F)));

        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        break;
    case UC_MODE_OSX:
        break;
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (!record->event.pressed) {
        return MACRO_NONE;
    }
    // MACRODOWN only works in this function
    switch(id) {
        case UM:
            unicode_mode = (unicode_mode + 1) % 2;
            break;


        default:
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case L1:
            ergodox_right_led_1_on();
            break;
        case L2:
            ergodox_right_led_2_on();
            break;
        case L3:
            ergodox_right_led_3_on();
            break;
        case L4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case L5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        // case L6:
        //     ergodox_right_led_2_on();
        //     ergodox_right_led_3_on();
        //     break;
        // case L7:
        //     ergodox_right_led_1_on();
        //     ergodox_right_led_2_on();
        //     ergodox_right_led_3_on();
        //     break;
        default:
            ergodox_board_led_off();
            break;
    }
};
