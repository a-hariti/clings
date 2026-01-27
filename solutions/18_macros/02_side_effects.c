#include <stdio.h>
#include "clings.h"

/*
 * Macros are simple text substitutions. If an argument with a side effect
 * (like i++) is passed to a macro, it might be evaluated more than once,
 * leading to unexpected behavior.
 *
 * One way to prevent double evaluation is to use a function instead of a macro.
 * Since functions evaluate their arguments exactly once before execution,
 * side effects only happen once.
 */

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

#define MAX(a, b) max(a, b)

int main(void) {
    int i = 10;
    int j = 20;

    int result = MAX(i++, j++);

    check_int(result, 20);
    check_int(i, 11);
    check_int(j, 21);

    return 0;
}