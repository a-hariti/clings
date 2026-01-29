#include <stdio.h>
#include "clings.h"

int square(int x) {
    return x * x;
}

int increment(int x) {
    return x + 1;
}

/*
 * The map function should take an array, its size, and a function pointer
 * that takes an int and returns an int. It applies that function to each
 * element in the array.
 */
void map(int *arr, size_t size, int (*f)(int)) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = f(arr[i]);
    }
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(numbers) / sizeof(numbers[0]);

    map(numbers, n, square);

    check_int(numbers[0], 1);
    check_int(numbers[1], 4);
    check_int(numbers[2], 9);
    check_int(numbers[3], 16);
    check_int(numbers[4], 25);

    map(numbers, n, increment);

    check_int(numbers[0], 2);
    check_int(numbers[1], 5);
    check_int(numbers[2], 10);
    check_int(numbers[3], 17);
    check_int(numbers[4], 26);

    return 0;
}