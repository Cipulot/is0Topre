/* Copyright 2022 Cipulot
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

#include "ec_switch_matrix.h"

#include "quantum.h"
#include "analog.h"
#include "print.h"

#define WAIT_DISCHARGE()
#define WAIT_CHARGE()

static ecsm_config_t config;
static uint16_t      ecsm_sw_value[MATRIX_ROWS][MATRIX_COLS];

static inline void discharge_capacitor(void) { setPinOutput(DISCHARGE_PIN); }
static inline void charge_capacitor(void) {
    setPinInput(DISCHARGE_PIN);
    writePinHigh(MATRIX_ROW_PIN);
}

static inline void clear_all_row_pin(void) {
    writePinLow(MATRIX_ROW_PIN);
}

static inline void init_row(void) {
    setPinOutput(MATRIX_ROW_PIN);
    writePinLow(MATRIX_ROW_PIN);
}

// Initialize pins
int ecsm_init(ecsm_config_t const* const ecsm_config) {
    // save config
    config = *ecsm_config;

    // initialize discharge pin as discharge mode
    writePinLow(DISCHARGE_PIN);
    setPinOutput(DISCHARGE_PIN);

    // initialize drive lines
    init_row();

    // set analog reference
    analogReference(ADC_REF_POWER);

    return 0;
}

// Read key value of key (channel, row, col) where channel 0 or 1
static uint16_t ecsm_readkey_raw(void) {
    uint16_t sw_value = 0;

    clear_all_row_pin();

    cli();

    charge_capacitor();
    WAIT_CHARGE();
    //wait_ms(0.001);

    sw_value = analogReadPin(ANALOG_PORT);

    sei();

    discharge_capacitor();
    WAIT_DISCHARGE();

    return sw_value;
}

// Update press/release state of key at (row, col)
static bool ecsm_update_key(matrix_row_t* current_row, uint8_t row, uint8_t col, uint16_t sw_value) {
    bool current_state = (*current_row >> col) & 1;

    // press to release
    if (current_state && sw_value < config.low_threshold_matrix[row][col]) {
        *current_row &= ~(1 << col);
        return true;
    }

    // release to press
    if ((!current_state) && sw_value > config.high_threshold_matrix[row][col]) {
        *current_row |= (1 << col);
        return true;
    }

    return false;
}

// Scan key values and update matrix state
bool ecsm_matrix_scan(matrix_row_t current_matrix[]) {
    bool updated = false;

    ecsm_sw_value[0][0] = ecsm_readkey_raw();
    updated |= ecsm_update_key(&current_matrix[0], 0, 0, ecsm_sw_value[0][0]);

    return updated;
}

// Debug print key values
void ecsm_print_matrix(void) {
    uprintf("%4d", ecsm_sw_value[0][0]);
    print("\n");
}
