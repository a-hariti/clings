#include <stdint.h>
#include <stdio.h>
#include "clings.h"

int main(void) {
    // Unix timestamps are often stored as seconds since Jan 1, 1970.
    // In 2038, a 32-bit signed integer will overflow (The Year 2038 Problem).
    // To be safe for the far future, we need a 64-bit integer.

    // We use int64_t to ensure it is exactly 64 bits on all platforms.
    int64_t timestamp = 2147483647;

    // This assertion checks the size of your type.
    cling_assert(sizeof(timestamp) == 8, "Timestamp must be 64 bits wide!");

    // Check that it can hold a value larger than 32-bit max
    timestamp = 5000000000L;

    printf("Timestamp: %ld\n", (long)timestamp);

    return 0;
}
