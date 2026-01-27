#include <stdio.h>
#include "clings.h"

/*
 * Goal: Understand pass-by-value vs pass-by-reference.
 *
 * In C, functions receive a copy of the arguments (pass-by-value).
 * If you want a function to modify a variable from the caller's scope,
 * you need to pass a pointer to that variable.
 *
 * Task: Modify the `increment` function and its call so that `score`
 * actually increases in `main`.
 */

void increment(int n) {
    n = n + 1;
}

int main(void) {
    int score = 42;

    increment(score);

    // This will fail because score is still 42.
    // How can we make increment modify the original score?
    check_int(score, 43);

    return 0;
}