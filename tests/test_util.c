#include <stdio.h>

// もうちょっと賢い方法ほしい
extern int failed_tests;


#define cassert(expr) \
    if (!(expr)) { \
        fprintf(stderr, "Assertion failed: %s | %s:%d\n", #expr, __FILE__, __LINE__); \
        failed_tests++; \
    }

#define cexpect_int(actual, expect) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %d, but %d | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        failed_tests++; \
    }

#define cexpect_str(actual, expect) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %s, but %s | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        failed_tests++; \
    }

#define cexpect_enum(actual, expect) \
    if (!((actual) == (expect))) { \
        fprintf(stderr, "Assertion failed: expected %d, but %d | %s:%d\n", (expect), (actual), __FILE__, __LINE__); \
        failed_tests++; \
    }
