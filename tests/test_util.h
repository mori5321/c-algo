#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <stdio.h>

typedef struct {
    int failed;
} TestState;

void increment_failed_count(TestState *t);

#define cassert(expr, testState) \
    if (!(expr)) { \
        fprintf(stderr, "Assertion failed: %s | %s:%d\n", #expr, __FILE__, __LINE__); \
        increment_failed_count(testState); \
    }

#define cexpect_int(actual, expect, testState) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %d, but %d | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        increment_failed_count(testState); \
    }

#define cexpect_size_t(actual, expect, testState) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %zu, but %zu | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        increment_failed_count(testState); \
    }

#define cexpect_char(actual, expect, testState) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %c, but %c | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        increment_failed_count(testState); \
    }

#define cexpect_str(actual, expect, testState) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %s, but %s | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        increment_failed_count(testState); \
    }

#define cexpect_enum(actual, expect, testState) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %d, but %d | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        increment_failed_count(testState); \
    }

#endif
