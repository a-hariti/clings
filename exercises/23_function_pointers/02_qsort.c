#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clings.h"

/*
 * The goal of this exercise is to use qsort to sort an array of structs.
 * qsort requires a comparison function with a specific signature:
 * int compare(const void *a, const void *b);
 *
 * It should return:
 * - A negative value if the first element is "less than" the second.
 * - Zero if they are "equal".
 * - A positive value if the first element is "greater than" the second.
 *
 * For further reading, check `man 3 qsort` or Beej's Guide:
 * https://beej.us/guide/bgc/html/split/pointers2.html#qsort-example
 */

typedef struct {
    char name[20];
    int age;
} Person;

// TODO: Implement the comparison logic to sort by age in ascending order.
// Hint: Cast a and b to (const Person *) before accessing their age.
// the casts will not be necessary for your impelementation.
int compare_people(const void *a, const void *b);

int main(void) {
    Person people[] = {
        {"Alice", 30},
        {"Bob", 20},
        {"Charlie", 25},
        {"Diana", 22},
    };
    size_t n = sizeof(people) / sizeof(people[0]);

    // TODO: Call qsort here to sort the 'people' array.
    // qsort(&people, n, sizeof(Person), compare_people);

    for (size_t i = 0; i < n - 1; i++) {
        cling_assert(people[i].age <= people[i + 1].age, "People should be sorted by age");
    }

    check_int(people[0].age, 20);
    check_int(people[1].age, 22);
    check_int(people[2].age, 25);
    check_int(people[3].age, 30);

    return 0;
}
