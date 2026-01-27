#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/*
 * Exercise: use_after_free
 *
 * Accessing memory after it has been freed is a serious bug that can lead to
 * crashes or security vulnerabilities. Once free() is called, the pointer
 * becomes invalid and the memory it pointed to belongs back to the system.
 *
 * Fix the order of operations so that the memory is accessed only before it is freed.
 */

int main(void) {
    int *secret_code = malloc(sizeof(int));
    if (secret_code == NULL)
        return 1;

    *secret_code = 1234;

    free(secret_code);

    // Bug: Accessing secret_code after it's been freed!
    // ASan (AddressSanitizer) will detect this and report a use-after-free error.
    check_int(*secret_code, 1234);

    return 0;
}