#include <stdio.h>
#include <stdlib.h>
#include "clings.h"

/**
 * Flexible Array Members (FAMs) allow a struct to end with an array of
 * unspecified size. This is useful for creating variable-length structures
 * where the data is contiguous with the struct header.
 *
 * A FAM must be the LAST member of the struct and is declared as `type name[];`.
 *
 * When allocating memory for such a struct, you must allocate enough space
 * for the struct itself PLUS the space for the array elements:
 * `malloc(sizeof(struct MyStruct) + count * sizeof(element_type))`
 */

struct IntegerList {
    int count;
    int values[]; // Flexible Array Member
};

int main(void) {
    size_t initial_count = 3;

    // Correctly allocate memory for the struct header and the array elements.
    struct IntegerList *list = malloc(sizeof(struct IntegerList) + initial_count * sizeof(int));
    if (list == NULL) {
        return 1;
    }

    list->count = (int)initial_count;
    list->values[0] = 10;
    list->values[1] = 20;
    list->values[2] = 30;

    check_int(list->values[0], 10);
    check_int(list->values[1], 20);
    check_int(list->values[2], 30);

    // Now let's resize the list to hold 5 values
    size_t new_count = 5;
    struct IntegerList *temp = realloc(list, sizeof(struct IntegerList) + new_count * sizeof(int));
    if (temp == NULL) {
        free(list);
        return 1;
    }
    list = temp;
    list->count = (int)new_count;
    list->values[3] = 40;
    list->values[4] = 50;

    check_int(list->values[3], 40);
    check_int(list->values[4], 50);

    free(list);

    return 0;
}