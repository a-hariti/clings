#include <stdio.h>
#include "clings.h"

/*
 * Goal: Access struct members using the dot operator.
 *
 * Requirements:
 * 1. Set the 'x' member of 'p' to 10.
 * 2. Set the 'y' member of 'p' to 20.
 */

struct Point {
    int x;
    int y;
};

int main(void) {
    struct Point p;

    // TODO: Set p's x to 10 and y to 20
    x = 10;
    y = 20;

    check_int(p.x, 10);
    check_int(p.y, 20);

    return 0;
}
