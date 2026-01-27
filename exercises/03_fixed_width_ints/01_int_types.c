#include <stdint.h>
#include <stdio.h>
#include "clings.h"

int main(void) {
    // Unix timestamps are often stored as seconds since Jan 1, 1970.
    // In 2038, a 32-bit signed integer will overflow (The Year 2038 Problem).
    // To be safe for the far future, we need a 64-bit integer.

    // TODO: Change this type to be exactly 64 bits wide.
    // Do not use 'long' or 'long long' directly; use a fixed-width type.
    int32_t timestamp = 2147483647;

    // This assertion checks the size of your type.
    // On most systems, sizeof returns bytes (1 byte = 8 bits).
    cling_assert(sizeof(timestamp) == 8, "Timestamp must be 64 bits wide!");

    // Check that it can hold a value larger than 32-bit max
    // (We cast to avoid compiler warnings in the broken version)
    // In the solution, this assignment should be valid without overflow.
    timestamp = 5000000000L;

    printf("Timestamp: %ld\n", (long)timestamp);

    return 0;
}
