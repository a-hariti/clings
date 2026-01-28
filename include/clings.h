#include <stdbool.h>

#ifndef CLINGS_H
#define CLINGS_H

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CLINGS_COLOR
#define CLINGS_COLOR 1
#endif

#ifndef CLINGS_VERBOSE
#define CLINGS_VERBOSE 1
#endif

#ifndef CLINGS_FAIL_FAST
#define CLINGS_FAIL_FAST 1
#endif

#ifndef CLINGS_EMOJI
#define CLINGS_EMOJI 1
#endif

#ifndef CLINGS_EPSILON
#define CLINGS_EPSILON 1.0e-5f
#endif

#ifndef CLINGS_TRACK_ALLOC
#define CLINGS_TRACK_ALLOC 1
#endif

#if CLINGS_COLOR
#define CLINGS_RED "\033[1;31m"
#define CLINGS_GREEN "\033[1;32m"
#define CLINGS_RESET "\033[0m"
#else
#define CLINGS_RED ""
#define CLINGS_GREEN ""
#define CLINGS_RESET ""
#endif

#if CLINGS_EMOJI
#define CLINGS_EMOJI_FAIL "❌ "
#define CLINGS_EMOJI_PASS "✅ "
#else
#define CLINGS_EMOJI_FAIL ""
#define CLINGS_EMOJI_PASS ""
#endif

static int CLINGS_FAILURES = 0;

static inline void clings_fail(const char *message, const char *file, int line) {
    fprintf(stderr, "%s%sAssertion failed:%s %s\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET, message);
    fprintf(stderr, "   Location: %s:%d\n", file, line);
    CLINGS_FAILURES++;
#if CLINGS_FAIL_FAST
    exit(1);
#endif
}

static inline void clings_pass(const char *message) {
#if CLINGS_VERBOSE
    printf("%s%sPassed:%s %s\n", CLINGS_GREEN, CLINGS_EMOJI_PASS, CLINGS_RESET, message);
#else
    (void)message;
#endif
}

static inline void clings_check_int_msg(int actual, int expected, const char *message, const char *file, int line) {
    if (actual != expected) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %d, got %d\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected, actual);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected int value");
    }
}

static inline void clings_check_long_msg(long actual, long expected, const char *message, const char *file, int line) {
    if (actual != expected) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %ld, got %ld\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected, actual);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected long value");
    }
}

static inline void clings_check_uint_msg(unsigned int actual, unsigned int expected, const char *message,
                                         const char *file, int line) {
    if (actual != expected) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %u, got %u\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected, actual);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected unsigned int value");
    }
}

static inline void clings_check_ulong_msg(unsigned long actual, unsigned long expected, const char *message,
                                          const char *file, int line) {
    if (actual != expected) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %lu, got %lu\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected, actual);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected unsigned long value");
    }
}

static inline void clings_check_size_msg(size_t actual, size_t expected, const char *message, const char *file,
                                         int line) {
    if (actual != expected) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %zu, got %zu\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected, actual);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected size_t value");
    }
}

static inline void clings_check_ptrdiff_msg(ptrdiff_t actual, ptrdiff_t expected, const char *message, const char *file,
                                            int line) {
    if (actual != expected) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %td, got %td\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected, actual);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected ptrdiff_t value");
    }
}

static inline void clings_check_ptr_msg(const void *actual, const void *expected, const char *message, const char *file,
                                        int line) {
    if (actual != expected) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %p, got %p\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected, actual);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected pointer value");
    }
}

static inline void clings_check_str_msg(const char *actual, const char *expected, const char *message, const char *file,
                                        int line) {
    if (actual == NULL || expected == NULL || strcmp(actual, expected) != 0) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected \"%s\", got \"%s\"\n", CLINGS_RED, CLINGS_EMOJI_FAIL,
                CLINGS_RESET, (expected != NULL) ? expected : "(null)", (actual != NULL) ? actual : "(null)");
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected string value");
    }
}

static inline void clings_check_bool_msg(_Bool actual, _Bool expected, const char *message, const char *file,
                                         int line) {
    int actual_int = actual ? 1 : 0;
    int expected_int = expected ? 1 : 0;
    if (actual_int != expected_int) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %d, got %d\n", CLINGS_RED, CLINGS_EMOJI_FAIL, CLINGS_RESET,
                expected_int, actual_int);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected boolean value");
    }
}

static inline void clings_check_float_eps_msg(float actual, float expected, float epsilon, const char *message,
                                              const char *file, int line) {
    float diff = fabsf(actual - expected);
    if (diff > epsilon) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %f, got %f (eps=%f)\n", CLINGS_RED, CLINGS_EMOJI_FAIL,
                CLINGS_RESET, expected, actual, epsilon);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected float value");
    }
}

static inline void clings_check_float_msg(float actual, float expected, const char *message, const char *file,
                                          int line) {
    clings_check_float_eps_msg(actual, expected, CLINGS_EPSILON, message, file, line);
}

static inline void clings_check_double_eps_msg(double actual, double expected, double epsilon, const char *message,
                                               const char *file, int line) {
    double diff = fabs(actual - expected);
    if (diff > epsilon) {
        fprintf(stderr, "%s%sAssertion failed:%s Expected %f, got %f (eps=%f)\n", CLINGS_RED, CLINGS_EMOJI_FAIL,
                CLINGS_RESET, expected, actual, epsilon);
        if (message != NULL && message[0] != '\0') {
            fprintf(stderr, "   Message: %s\n", message);
        }
        fprintf(stderr, "   Location: %s:%d\n", file, line);
        CLINGS_FAILURES++;
        if (CLINGS_FAIL_FAST)
            exit(1);
    } else {
        clings_pass((message != NULL && message[0] != '\0') ? message : "Got expected double value");
    }
}

static inline void clings_check_double_msg(double actual, double expected, const char *message, const char *file,
                                           int line) {
    clings_check_double_eps_msg(actual, expected, (double)CLINGS_EPSILON, message, file, line);
}

/* Simple assertion macro that prints a message and exits if false */
#define cling_assert(condition, message)                                                                               \
    do {                                                                                                               \
        if (!(condition)) {                                                                                            \
            clings_fail((message), __FILE__, __LINE__);                                                                \
        } else {                                                                                                       \
            clings_pass((message));                                                                                    \
        }                                                                                                              \
    } while (0)

/* Helper for integer equality */
#define check_int_msg(actual, expected, message)                                                                       \
    clings_check_int_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_int(actual, expected)                                                                                    \
    do {                                                                                                               \
        check_int_msg((actual), (expected), NULL);                                                                     \
    } while (0)

#define check_enum_msg(actual, expected, message)                                                                      \
    check_int_msg((int)(actual), (int)(expected), (message))

#define check_enum(actual, expected)                                                                                   \
    do {                                                                                                               \
        check_enum_msg((actual), (expected), NULL);                                                                    \
    } while (0)

#define check_long_msg(actual, expected, message)                                                                      \
    clings_check_long_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_long(actual, expected)                                                                                   \
    do {                                                                                                               \
        check_long_msg((actual), (expected), NULL);                                                                    \
    } while (0)

#define check_uint_msg(actual, expected, message)                                                                      \
    clings_check_uint_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_uint(actual, expected)                                                                                   \
    do {                                                                                                               \
        check_uint_msg((actual), (expected), NULL);                                                                    \
    } while (0)

#define check_ulong_msg(actual, expected, message)                                                                     \
    clings_check_ulong_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_ulong(actual, expected)                                                                                  \
    do {                                                                                                               \
        check_ulong_msg((actual), (expected), NULL);                                                                   \
    } while (0)

#define check_size_msg(actual, expected, message)                                                                      \
    clings_check_size_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_size(actual, expected)                                                                                   \
    do {                                                                                                               \
        check_size_msg((actual), (expected), NULL);                                                                    \
    } while (0)

#define check_ptrdiff_msg(actual, expected, message)                                                                   \
    clings_check_ptrdiff_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_ptrdiff(actual, expected)                                                                                \
    do {                                                                                                               \
        check_ptrdiff_msg((actual), (expected), NULL);                                                                 \
    } while (0)

#define check_ptr_msg(actual, expected, message)                                                                       \
    clings_check_ptr_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_ptr(actual, expected)                                                                                    \
    do {                                                                                                               \
        check_ptr_msg((actual), (expected), NULL);                                                                     \
    } while (0)

#define check_str_msg(actual, expected, message)                                                                       \
    clings_check_str_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_str(actual, expected)                                                                                    \
    do {                                                                                                               \
        check_str_msg((actual), (expected), NULL);                                                                     \
    } while (0)

#define check_bool_msg(actual, expected, message)                                                                      \
    clings_check_bool_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_bool(actual, expected)                                                                                   \
    do {                                                                                                               \
        check_bool_msg((actual), (expected), NULL);                                                                    \
    } while (0)

/* Helper for float equality (with epsilon) */
#define check_float_eps_msg(actual, expected, epsilon, message)                                                        \
    clings_check_float_eps_msg((actual), (expected), (epsilon), (message), __FILE__, __LINE__)

#define check_float_eps(actual, expected, epsilon)                                                                     \
    do {                                                                                                               \
        check_float_eps_msg((actual), (expected), (epsilon), NULL);                                                    \
    } while (0)

#define check_float_msg(actual, expected, message)                                                                     \
    clings_check_float_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_float(actual, expected)                                                                                  \
    do {                                                                                                               \
        check_float_eps_msg((actual), (expected), CLINGS_EPSILON, NULL);                                               \
    } while (0)

#define check_double_eps_msg(actual, expected, epsilon, message)                                                       \
    clings_check_double_eps_msg((actual), (expected), (epsilon), (message), __FILE__, __LINE__)

#define check_double_eps(actual, expected, epsilon)                                                                    \
    do {                                                                                                               \
        check_double_eps_msg((actual), (expected), (epsilon), NULL);                                                   \
    } while (0)

#define check_double_msg(actual, expected, message)                                                                    \
    clings_check_double_msg((actual), (expected), (message), __FILE__, __LINE__)

#define check_double(actual, expected)                                                                                 \
    do {                                                                                                               \
        check_double_eps_msg((actual), (expected), (double)CLINGS_EPSILON, NULL);                                      \
    } while (0)

#define check_eq_msg(actual, expected, message)                                                                        \
    _Generic((expected),                                                                                               \
        char *: clings_check_str_msg,                                                                                  \
        const char *: clings_check_str_msg,                                                                            \
        float: clings_check_float_msg,                                                                                 \
        double: clings_check_double_msg,                                                                               \
        int: clings_check_int_msg,                                                                                     \
        long: clings_check_long_msg,                                                                                   \
        unsigned int: clings_check_uint_msg,                                                                           \
        unsigned long: clings_check_ulong_msg,                                                                         \
        bool: clings_check_bool_msg,                                                                                   \
        default: clings_check_ptr_msg)((actual), (expected), (message), __FILE__, __LINE__)

#define check_eq(actual, expected)                                                                                     \
    do {                                                                                                               \
        check_eq_msg((actual), (expected), NULL);                                                                      \
    } while (0)

#if CLINGS_TRACK_ALLOC
// This will hijack malloc and free to allow us to track memory allocations.
//  -- MEMORY TRACKER START --
static int ACTIVE_ALLOCATIONS = 0;
static int TOTAL_ALLOCATIONS = 0;

static inline void *test_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        ACTIVE_ALLOCATIONS++;
        TOTAL_ALLOCATIONS++;
    }
    return ptr;
}

static inline void test_free(void *ptr) {
    if (ptr != NULL) {
        ACTIVE_ALLOCATIONS--;
    }
    free(ptr);
}

// intercept malloc & free to spy on them
#define malloc(size) test_malloc(size)
#define free(ptr) test_free(ptr)

// -- MEMORY TRACKER END --
#endif

#endif /* CLINGS_H */
