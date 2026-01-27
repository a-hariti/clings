#include <stdio.h>
#include "clings.h"

int main(void) {
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += i;
    }

    check_int(sum, 10);

    return 0;
}