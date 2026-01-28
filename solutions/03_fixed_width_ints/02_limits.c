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
    // The maximum possible value for an 8-bit unsigned integer is UINT8_MAX (255).
    uint8_t max_byte = UINT8_MAX;

    check_eq_msg(max_byte, 255, "max_byte should be the maximum value for uint8_t");

    // The maximum possible value for a 32-bit signed integer is INT32_MAX (2147483647).
    int32_t max_int32 = INT32_MAX;

    check_eq_msg(max_int32, 2147483647, "max_int32 should be the maximum value for int32_t");

    return 0;
}
