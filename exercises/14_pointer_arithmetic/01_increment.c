#include <stdio.h>
#include "clings.h"

/*
 * Goal: Use pointer arithmetic (increment) to sum all elements in the array.
 *
 * In C, adding 1 to a pointer moves it forward by the size of its base type.
 * For an int pointer, ptr + 1 moves 4 bytes (assuming 4-byte ints).
 */

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;

    int *ptr = numbers;

    for (int i = 0; i < n; i++) {
        sum += *ptr;
        // Bug: We are not moving the pointer to the next element!
    }

    check_int(sum, 150);

    return 0;
}
