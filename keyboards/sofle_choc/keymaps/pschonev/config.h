/* Copyright 2023 Brian Low
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
#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define SPLIT_USB_DETECT
#define ACHORDION_STREAK

// Vial Support
#define VIAL_KEYBOARD_UID \
    { 0xA7, 0xA7, 0x9C, 0x4C, 0xE0, 0xB8, 0x00, 0x8D }

// The four corners
#define VIAL_UNLOCK_COMBO_ROWS \
    { 0, 5, 3, 8 }
#define VIAL_UNLOCK_COMBO_COLS \
    { 0, 0, 0, 0 }

#define DYNAMIC_KEYMAP_MACRO_COUNT 30

#define PERMISSIVE_HOLD
#define RETRO_TAPPING
#define TAPPING_TERM 200
