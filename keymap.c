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
  DEL_EML,
  ARC_EML,
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

#define ALTLEFT LALT(KC_LEFT)
#define ALTRGHT LALT(KC_RGHT)
#define GUILEFT LGUI(KC_LEFT)
#define GUIRGHT LGUI(KC_RGHT)

// IntelliJ Shorcuts
#define FNDFILE LSFT(LCTL(KC_N))
#define REFACTR LCTL(LALT(LSFT(KC_T)))
#define CLOSE LCTL(KC_F4)
#define HIDWINS LCTL(LSFT(KC_F12))
#define RUNTGTS LSFT(LALT(KC_F10))
#define RERUN LCTL(KC_F5)
#define EXECUTE LCTL(LSFT(KC_F10))
#define SYMBOL LSFT(LCTL(LALT(KC_N)))
#define DEBUG LCTL(LSFT(KC_F9))
#define END LCTL(KC_F2)
#define CREATE LALT(KC_INS)
#define FIND LCTL(LSFT(KC_F))
#define GO2TEST LCTL(LSFT(KC_T))
#define GIT LALT(KC_GRV)
#define HIERARC LCTL(LALT(KC_H))
#define USAGES LALT(KC_F7)
#define MENU LALT(LSFT(KC_SCLN))
#define BACK LCTL(LALT(KC_LEFT))
#define FORWARD LCTL(LALT(KC_RGHT))
#define PREVMTD LALT(KC_UP)
#define NEXTMTD LALT(KC_DOWN)
#define FONT_DN LSFT(LCTL(LALT(KC_MINS)))
#define FONT_UP LSFT(LCTL(LALT(KC_EQL)))
#define FONTRES LSFT(LCTL(LALT(KC_SCLN)))
#define INFO LCTL(KC_F1)
#define OUTLINE LCTL(KC_F12)
#define PRVCHNG LCTL(LALT(LSFT(KC_UP)))
#define NXTCHNG LCTL(LALT(LSFT(KC_DOWN)))
#define EXT_VAR LCTL(LALT(KC_V))

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
 * | Del  |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL, \
   KC_DEL, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
   KC_DEL, _______, _______, _______, _______, _______, _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,   RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Arrow (Hold Escape)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |VimCpy|DelEml|  Up  |ArcEml|VimPst|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |G+Left|A+Left| Left | Down | Right|A+Rght|G+Rght|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 | Home |  End |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROW] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,  VIM_CP, DEL_EML,   KC_UP, ARC_EML,  VIM_PS, _______, \
  _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, GUILEFT, ALTLEFT, KC_LEFT, KC_DOWN, KC_RGHT, ALTRGHT, GUIRGHT, \
  _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_HOME,  KC_END, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* IntelliJ (Fn)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Close |      |  End |Refctr|      |      |Usages|Prev_M|Outlin|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |HidWin|RunTgs|Symbol|Debug | Find | Git  |Hierar| Prev |Next_M| Next |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Rerun |Execut|Create|ExtVar|      | File | Menu |FontDn|FontUp| Info |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_INTJ] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,   CLOSE, _______,     END, REFACTR, _______, _______,  USAGES, PREVMTD, OUTLINE, _______, _______, \
  HIDWINS, RUNTGTS,  SYMBOL,   DEBUG,    FIND,     GIT, HIERARC,    BACK, NEXTMTD, FORWARD, _______, _______, \
  _______,   RERUN, EXECUTE,  CREATE, EXT_VAR, _______, FNDFILE,    MENU, FONT_DN, FONT_UP,    INFO, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
    case DEL_EML:
      if (record->event.pressed) {
        SEND_STRING("x#");
      }
      return false;
    case ARC_EML:
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
