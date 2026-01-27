#include <stdio.h>
#include "clings.h"

/*
 * Macros are simple text substitutions. If an argument with a side effect
 * (like i++) is passed to a macro, it might be evaluated more than once,
 * leading to unexpected behavior.
 *
 * Your goal is to fix the MAX macro so that it only evaluates its arguments once.
 *
 * Hint: A function is often better than a macro for this.
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    int i = 10;
    int j = 20;

    /*
     * If MAX(i++, j++) is a macro, one of the arguments will be incremented twice.
     * We want i to become 11, j to become 21, and result to be 20.
     */
    int result = MAX(i++, j++);

    check_int(result, 20);
    check_int(i, 11);
    check_int(j, 21);

    return 0;
}