#include "./linear_search_test.h"
#include "./sentinel_search_test.h"
#include "./test_util.c"

int failed_tests = 0;

int main(void) {
    linear_search_tests();
    sentinel_search_tests();
        
    if (failed_tests > 0) {
        fprintf(stderr, "%d tests failed\n", failed_tests);
        return 1;
    }

    fprintf(stderr, "All tests passed\n");
    return 0;
}
