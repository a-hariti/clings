#include <stdio.h>
#include "clings.h"

/*
 * Integer overflow occurs when an arithmetic operation attempts to create a numeric
 * value that is outside of the range that can be represented with a given number
 * of bits.
 *
 * In this exercise, `counter` is an 8-bit unsigned integer (unsigned char) which
 * can only hold values from 0 to 255.
 *
 * Adding to it when it's already at its maximum will cause it to wrap around.
 * Fix this by using a larger integer type so that it can hold the value 260.
 */

int main(void) {
    int counter = 250;

    for (int i = 0; i < 10; i++) {
        counter++;
    }

    // 250 + 10 = 260.
    // Using int (at least 16 bits, typically 32) prevents the overflow.
    check_int(counter, 260);

    return 0;
}