#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

int main(void) {
    size_t count = 4;
    int *numbers = calloc(count, sizeof(int));

    cling_assert(numbers != NULL, "Allocation should succeed");

    for (size_t i = 0; i < count; i++) {
        check_int_msg(numbers[i], 0, "calloc should zero-initialize memory");
    }

    free(numbers);
    return 0;
}
