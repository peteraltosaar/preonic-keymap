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
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ARROW,
  _INTJ,
  _APPS
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  DELETE_EMAIL,
  ARCHIVE_EMAIL,
  VIM_CP,
  VIM_PS,
  SLACK,
  TODOIST,
  FIREFOX,
  CHROME,
  UNANET,
  ONENOTE,
  SPOTIFY,
  MAIL,
  CALENDR,
  ITERM,
  PLAN,
  VMWARE
};

// Layer shortcuts
#define ARROW MO(_ARROW)
#define INTJ MO(_INTJ)
#define APPS MO(_APPS)

#define ARR_ESC LT(ARROW, KC_ESC)
#define INTJ_F4 LT(INTJ, KC_F4)
#define SPC_APP LT(APPS, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | IntJ | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC, \
  ARR_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT, \
  INTJ_F4, KC_LCTL, KC_LALT, KC_LGUI,   LOWER, SPC_APP, SPC_APP,   RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |DelEml|ArcEml|  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3, DELETE_EMAIL,   ARCHIVE_EMAIL,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Arrow (Hold Escape)
 * ,-----------------------------------------------------------------------------------.
 * |      |SetBM1|SetBM2|SetBM3|SetBM4|SetBM5|SetBM6|SetBM7|SetBM8|SetBM9|SetBM0|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | Home | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |  End |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROW] = LAYOUT_preonic_grid( \
  _______, LSFT(LCTL(LALT(KC_1))), LSFT(LCTL(LALT(KC_2))), LSFT(LCTL(LALT(KC_3))), LSFT(LCTL(LALT(KC_4))), LSFT(LCTL(LALT(KC_5))), LSFT(LCTL(LALT(KC_6))), LSFT(LCTL(LALT(KC_7))), LSFT(LCTL(LALT(KC_8))), LSFT(LCTL(LALT(KC_9))), LSFT(LCTL(LALT(KC_0))), _______, \
  _______, KC_F1, KC_F2, KC_F3, KC_F4, _______, VIM_CP, _______, KC_UP, _______, VIM_PS, _______, \
  _______, KC_F5, KC_F6, KC_F7, KC_F8, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, \
  _______, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_END, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* IntelliJ (Fn)
 * ,-----------------------------------------------------------------------------------.
 * |      | BkMk1| BkMk2| BkMk3| BkMk4| BkMk5| BkMk6| BkMk7| BkMk8| BkMk9| BkMk0|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Close|      |  End |Refctr|      |      |Usages|Prev_M|Outlin| Run  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Symbol|      |      |      |Hierar| Prev |Next_M| Next |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |Run It|Create| View |      | File | Menu |      |Evalua|MoInfo|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_INTJ] = LAYOUT_preonic_grid( \
  _______, LCTL(LALT(KC_1)), LCTL(LALT(KC_2)), LCTL(LALT(KC_3)), LCTL(LALT(KC_4)), LCTL(LALT(KC_5)), LCTL(LALT(KC_6)), LCTL(LALT(KC_7)), LCTL(LALT(KC_8)), LCTL(LALT(KC_9)), LCTL(LALT(KC_0)), _______, \
  _______, LCTL(KC_F4), _______, LCTL(KC_F2), LSFT(LCTL(LALT(KC_T))), _______, _______, LALT(KC_F7), LALT(KC_UP), LCTL(KC_F12), LSFT(LALT(KC_F10)), _______, \
  _______, _______, LCTL(LALT(LSFT(KC_N))), _______, _______, _______, LCTL(LALT(KC_H)), LCTL(LALT(KC_LEFT)), LALT(KC_DOWN), LCTL(LALT(KC_RIGHT)), _______, _______, \
  _______, _______, LCTL(LSFT(KC_F10)), LALT(KC_INS), LALT(KC_F1), _______, LCTL(LSFT(KC_N)), LSFT(LALT(KC_SCLN)), _______, LALT(KC_F8), LCTL(KC_F1), _______, \
  _______, _______, _______, _______, _______, LCTL(LALT(KC_SCLN)), LCTL(LALT(KC_SCLN)), _______, _______, _______, _______, _______  \
),

/* App Shortcuts
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Mail |      |Tdoist|      |Unanet|ITerm |OneNte| Plan |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Slack |      |FreFox|Chrome|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Calndr|VMWare|      |      |Sptify|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_APPS] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______,    MAIL, _______, TODOIST, _______,  UNANET,   ITERM, ONENOTE,    PLAN, _______, \
  _______, _______,   SLACK, _______, FIREFOX,  CHROME, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, CALENDR,  VMWARE, _______, _______, SPOTIFY, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case DELETE_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("x#");
      }
      return false;
    case ARCHIVE_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("xe");
      }
      return false;
    case VIM_CP:
      if (record->event.pressed) {
        SEND_STRING("\"*y");
      }
      return false;
    case VIM_PS:
      if (record->event.pressed) {
        SEND_STRING("\"*p");
      }
      return false;
    case SLACK:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("slack" SS_TAP(X_ENTER));
      }
    return false;
    case CALENDR:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("calendar" SS_TAP(X_ENTER));
      }
    return false;
    case FIREFOX:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("firefox" SS_TAP(X_ENTER));
      }
    return false;
    case MAIL:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("mail" SS_TAP(X_ENTER));
      }
    return false;
    case TODOIST:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("todoist-native" SS_TAP(X_ENTER));
      }
    return false;
    case CHROME:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("chrome" SS_TAP(X_ENTER));
      }
    return false;
    case UNANET:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("unanet" SS_TAP(X_ENTER));
      }
    return false;
    case SPOTIFY:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("spotify" SS_TAP(X_ENTER));
      }
    return false;
    case ITERM:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("iterm" SS_TAP(X_ENTER));
      }
    return false;
    case ONENOTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("onenote" SS_TAP(X_ENTER));
      }
    return false;
    case PLAN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("plan" SS_TAP(X_ENTER));
      }
    return false;
    case VMWARE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_SPACE)));
        _delay_ms(200);
        SEND_STRING("vmware" SS_TAP(X_ENTER));
      }
    return false;
  }
  return true;
};

/* Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*[_LAYER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)*/
