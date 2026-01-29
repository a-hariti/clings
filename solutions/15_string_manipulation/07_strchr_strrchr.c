#include <stdio.h>
#include <string.h>
#include "clings.h"

int main(void) {
    const char *word = "bananas";

    const char *first = strchr(word, 'a');
    const char *last = strrchr(word, 'a');

    size_t first_index = (size_t)(first - word);
    size_t last_index = (size_t)(last - word);

    check_size_msg(first_index, 1, "First 'a' should be at index 1");
    check_size_msg(last_index, 5, "Last 'a' should be at index 5");

    return 0;
}
