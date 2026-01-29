#include <stdio.h>
#include <string.h>
#include "clings.h"

/*
 * strchr finds the first occurrence, strrchr finds the last.
 */

int main(void) {
    const char *word = "bananas";

    // TODO: Find the first and last 'a'.
    const char *first = NULL;
    const char *last = NULL;

    size_t first_index = (size_t)(first - word);
    size_t last_index = (size_t)(last - word);

    check_size_msg(first_index, 1, "First 'a' should be at index 1");
    check_size_msg(last_index, 5, "Last 'a' should be at index 5");

    return 0;
}
