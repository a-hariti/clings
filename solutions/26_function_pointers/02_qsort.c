#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clings.h"

/*
 * The goal of this exercise is to use qsort to sort an array of structs.
 * qsort requires a comparison function with a specific signature:
 * int compare(const void *a, const void *b);
 */

typedef struct {
    char name[20];
    int age;
} Person;

int compare_people(const void *a, const void *b) {
    const Person *p1 = (const Person *)a;
    const Person *p2 = (const Person *)b;

    if (p1->age < p2->age)
        return -1;
    if (p1->age > p2->age)
        return 1;
    return 0;
}

int main(void) {
    Person people[] = {
        {"Alice", 30},
        {"Bob", 20},
        {"Charlie", 25},
        {"Diana", 22},
    };
    size_t n = sizeof(people) / sizeof(people[0]);

    qsort(&people, n, sizeof(Person), compare_people);

    for (size_t i = 0; i < n - 1; i++) {
        cling_assert(people[i].age <= people[i + 1].age, "People should be sorted by age");
    }

    check_int(people[0].age, 20);
    check_int(people[1].age, 22);
    check_int(people[2].age, 25);
    check_int(people[3].age, 30);

    return 0;
}
