#ifndef CLINGS_H
#define CLINGS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Simple assertion macro that prints a message and exits if false */
#define cling_assert(condition, message)                                                                               \
    do {                                                                                                               \
        if (!(condition)) {                                                                                            \
            fprintf(stderr, "\033[1;31m❌ Assertion failed:\033[0m %s\n", message);                                    \
            fprintf(stderr, "   Location: %s:%d\n", __FILE__, __LINE__);                                               \
            exit(1);                                                                                                   \
        }                                                                                                              \
        printf("\033[1;32m✅ Passed:\033[0m %s\n", message);                                                           \
    } while (0)

/* Helper for integer equality */
#define check_int(actual, expected)                                                                                    \
    do {                                                                                                               \
        int __a = (actual);                                                                                            \
        int __e = (expected);                                                                                          \
        if (__a != __e) {                                                                                              \
            fprintf(stderr,                                                                                            \
                    "\033[1;31m❌ Assertion failed:\033[0m Expected %d, but "                                          \
                    "got %d\n",                                                                                        \
                    __e, __a);                                                                                         \
            fprintf(stderr, "   Location: %s:%d\n", __FILE__, __LINE__);                                               \
            exit(1);                                                                                                   \
        }                                                                                                              \
        printf("\033[1;32m✅ Passed:\033[0m Got expected value %d\n", __a);                                            \
    } while (0)

/* Helper for float equality (with epsilon) */
#define check_float(actual, expected)                                                                                  \
    do {                                                                                                               \
        float __fa = (actual);                                                                                         \
        float __fe = (expected);                                                                                       \
        float __diff = __fa - __fe;                                                                                    \
        if (__diff < 0)                                                                                                \
            __diff = -__diff;                                                                                          \
        if (__diff > 0.00001f) {                                                                                       \
            fprintf(stderr,                                                                                            \
                    "\033[1;31m❌ Assertion failed:\033[0m Expected %f, but "                                          \
                    "got %f\n",                                                                                        \
                    __fe, __fa);                                                                                       \
            fprintf(stderr, "   Location: %s:%d\n", __FILE__, __LINE__);                                               \
            exit(1);                                                                                                   \
        }                                                                                                              \
        printf("\033[1;32m✅ Passed:\033[0m Got expected value %f\n", __fa);                                           \
    } while (0)

// This will hijack malloc and free to allow us to track memory allocations
//  -- MEMORY TRACKER START --
static int ACTIVE_ALLOCATIONS = 0;

void *test_malloc(size_t size) {
    void *ptr = malloc(size);
    ACTIVE_ALLOCATIONS++;
    return ptr;
}

void test_free(void *ptr) {
    free(ptr);
    ACTIVE_ALLOCATIONS--;
}

// intercept malloc & free to spy on them
#define malloc(size) test_malloc(size)
#define free(ptr) test_free(ptr)

// -- MEMORY TRACKER END --

#endif /* CLINGS_H */
