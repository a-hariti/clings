#include <stdio.h>
#include "clings.h"

/*
 * Goal: Use the correct operator for struct pointers.
 *
 * In C, you use the dot operator (.) to access members of a struct.
 * However, when you have a pointer to a struct, you must use the
 * arrow operator (->) or dereference the pointer first (*ptr).member.
 */

struct Point {
    int x;
    int y;
};

int main(void) {
    struct Point p = {10, 20};
    struct Point *ptr = &p;

    // Fixed: Using the arrow operator (->) for pointers to structs.
    ptr->x = 30;
    ptr->y = 40;

    check_int(p.x, 30);
    check_int(p.y, 40);

    return 0;
}