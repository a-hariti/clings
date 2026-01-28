#include <stdint.h>
#include <stdio.h>
#include "clings.h"

/**
 * The <stdint.h> header provides macros for the minimum and maximum
 * values of each fixed-width type.
 * These macros follow a pattern: [TYPE]_MIN and [TYPE]_MAX.
 * Examples: UINT8_MAX, INT16_MIN, INT32_MAX, etc.
 */

int main(void) {
    // TODO: Assign the maximum possible value for an 8-bit unsigned integer.
    // Use the standard macro from <stdint.h> instead of a hardcoded number.
    uint8_t max_byte = 0;

    check_eq_msg(max_byte, 255, "max_byte should be the maximum value for uint8_t");

    // TODO: Assign the maximum possible value for a 32-bit signed integer.
    // Use the standard macro from <stdint.h>.
    int32_t max_int32 = 0;

    check_eq_msg(max_int32, 2147483647, "max_int32 should be the maximum value for int32_t");

    return 0;
}
