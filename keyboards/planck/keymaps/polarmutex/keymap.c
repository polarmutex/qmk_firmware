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

enum planck_layers {
  _COLEMAK,
  _SHIFT_COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  BACKLIT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define S_SFT MO(_SHIFT_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak DH Mod
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   q  |   w  |   f  |   p  |   b  |   j  |   l  |   u  |   y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   a  |   r  |   s  |   t  |   g  |   m  |   n  |   e  |   i  |   o  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   z  |   x  |   c  |   d  |   v  |   k  |   h  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space |CShift|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    RCTL_T(KC_ENT),
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    BACKLIT,        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  S_SFT,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak DH Mod Shifted
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SHIFT_COLEMAK] = LAYOUT_planck_grid(
    S(KC_TAB), S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B), S(KC_J), S(KC_L), S(KC_U),    S(KC_Y),    S(KC_SCLN), _______,
    S(KC_ESC), S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G), S(KC_M), S(KC_N), S(KC_E),    S(KC_I),    S(KC_O),    _______,
    _______,   S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V), S(KC_K), S(KC_H), S(KC_COMM), S(KC_DOT),  S(KC_SLSH), _______,
    _______,   _______, _______, _______, _______, _______, _______, _______, S(KC_LEFT), S(KC_DOWN), S(KC_UP),   S(KC_RGHT)
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   ^  |   *  |   +  |   -  |   /  |   \  |   _  |   '  |   "  |   `  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   $  |   {  |   [  |   (  |   ;  |   :  |   )  |   ]  |   }  |   @  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   |  |   &  |   !  |   ~  |   %  |   #  |   =  |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | Pgup | Pgdn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_CIRC, KC_ASTR, KC_PLUS, KC_MINS, KC_SLSH, KC_BSLS, KC_UNDS, KC_QUOT, KC_DQT,  KC_GRV,  _______,
    _______, KC_DLR,  KC_LCBR, KC_LBRC, KC_LPRN, KC_SCLN, KC_COLN, KC_RPRN, KC_RBRC, KC_RCBR, KC_AT,   _______,
    _______, KC_PIPE, KC_AMPR, KC_EXLM, KC_TILD, KC_PERC, KC_HASH, KC_EQL,  KC_LT,   KC_GT,   KC_QUES, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   7  |   8  |   9  |      |      |  F9  |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |      |      |  F5  |  F6  |  F7  |  F8  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |  .   |      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}


void encoder_update(bool clockwise) {
  if (clockwise) {
    #ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_DOWN);
    #else
      tap_code(KC_PGDN);
    #endif
  } else {
    #ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_UP);
    #else
      tap_code(KC_PGUP);
    #endif
  }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
