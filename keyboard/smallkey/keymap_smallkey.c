#include "keycode.h"
#include "keymap.h"

extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

/* translates key to keycode */
uint16_t actionmap_key_to_action(uint8_t layer, key_t key)
{
    return pgm_read_word(&keymaps[(layer)][(key.row)][(key.col)]);
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return (action_t){ .code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]) };
}

# define KEYMAP( K00, K01, K02, K03 ) { \
  { K00, K01 }, \
  { K02, K03 }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(KC_Q, KC_W, KC_A, KC_R), \ 
};

const uint16_t PROGMEM fn_actions[] = {};
