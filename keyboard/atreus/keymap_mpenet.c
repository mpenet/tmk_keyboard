#include "keymap_common.h"

/* This is based on the "querty_classic" layer with some adjustements
   to make it comfy if you use C-i (tab) C-h (del) C-m (ret).

   This is a layout optimized for emacs users, and currently paired
   with i3 with movements keys and general ergonomics following the
   same approach

   The goal is to have really minimal hand movement and 1 mod access to the
   various parens, numbers & glyphs. bksp and enter are still on L1
   but never used, same goes for esc and tab.

   Arrows and F keys are never used but present on L3
*/

// L1
 /*   q     w     e     r     t       ||       y     u     i     o    p   */
 /*   a     s     d     f     g       ||       h     j     k     l    ;   */
 /*   z     x     c     v     b       ||       n     m     ,     .    /   */
 /*  bksp  esc  tab  super shift ctrl || alt space  fn     -     '  enter */

// L2
//    !     @     {     }     |       ||     pgup    7     8     9    *
//    #     $     (     )     `       ||     pgdn    4     5     6    +
//    %     ^     [     ]     ~       ||       &     1     2     3    \
//   L2  insert super shift bksp ctrl || alt space   fn    .     0    =

// L3 has the arrows (I *never* use that layer)
//  insert home    ↑    end  pgup     ||       ↑     F7    F8    F9   F10
//    del   ←      ↓     →   pgdn     ||       ↓     F4    F5    F6   F11
//                                    ||             F1    F2    F3   F12
//              super shift bksp ctrl || alt space   L0             reset

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_BSPC, KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,     \
         KC_SPC, KC_FN0, KC_MINS, KC_QUOT, KC_ENT),                     \
  /* 1: punctuation and numbers */
  FN_LAYER,                                     \
  /* 2: arrows and function keys */
  LAYER_TWO
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
