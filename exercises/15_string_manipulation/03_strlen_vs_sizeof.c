#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * sizeof(array) is the array size in bytes.
 * strlen(string) counts characters up to the first '\0'.
 */

int main(void) {
    char word[] = "hello";

    // TODO: Use strlen to compute the character length.
    size_t len = sizeof(word);

    check_size_msg(len, 5, "Length should be 5 characters");

    return 0;
}
