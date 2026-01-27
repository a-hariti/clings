#include <stdio.h>
#include "clings.h"

/*
 * Exercise: 01_ifdef.c
 *
 * The preprocessor can include or exclude code blocks using #ifdef, #else, and #endif.
 * This is widely used for feature flags and platform-specific logic.
 *
 * Your task: Define the macro 'ENABLE_FEATURE' to make the test pass.
 */

#define ENABLE_FEATURE

int main(void) {
    int feature_enabled = 0;

#ifdef ENABLE_FEATURE
    feature_enabled = 1;
#endif

    cling_assert(feature_enabled == 1, "Feature should be enabled using ENABLE_FEATURE macro!");

    if (feature_enabled) {
        printf("Feature is ENABLED. Good job!\n");
    } else {
        printf("Feature is DISABLED. Try defining the macro.\n");
    }

    return 0;
}
