#include <stdint.h>
#include <stdio.h>
#include "clings.h"

#define FLAG_READ (1 << 0)
#define FLAG_WRITE (1 << 1)
#define FLAG_EXEC (1 << 2)

/*
 * Bit manipulation is a core skill in C, especially for systems programming.
 * Bitmasks allow us to pack multiple boolean flags into a single integer.
 *
 * Your task:
 * 1. Set both READ and WRITE flags in 'permissions'.
 * 2. Clear the READ flag.
 * 3. Toggle the EXEC flag.
 */

int main(void) {
    uint8_t permissions = 0;

    // 1. Set the READ and WRITE flags
    permissions |= FLAG_READ;
    permissions |= FLAG_WRITE;

    cling_assert((permissions & FLAG_READ) && (permissions & FLAG_WRITE), "Both READ and WRITE flags should be set");

    // 2. Clear the READ flag
    permissions &= ~FLAG_READ;

    cling_assert(!(permissions & FLAG_READ), "READ flag should be cleared");
    cling_assert(permissions & FLAG_WRITE, "WRITE flag should still be set");

    // 3. Toggle the EXEC flag
    permissions ^= FLAG_EXEC;

    cling_assert(permissions & FLAG_EXEC, "EXEC flag should be set after toggling");

    permissions ^= FLAG_EXEC;
    cling_assert(!(permissions & FLAG_EXEC), "EXEC flag should be cleared after toggling again");

    return 0;
}