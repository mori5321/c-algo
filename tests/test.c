#include <stdio.h>

#include "./test_util.h"
#include "./utils/string_test.h"

#include "./linear_search_test.h"
#include "./sentinel_search_test.h"
#include "./binary_search_test.h"


int main(void) {

    TestState t = {
        .failed = 0,
    };

    string_tests(&t);
    
    linear_search_tests(&t);
    sentinel_search_tests(&t);
    binary_search_tests(&t);
        
    if (t.failed > 0) {
        fprintf(stderr, "%d tests failed\n", t.failed);
        return 1;
    }

    fprintf(stderr, "\033[92mAll tests passed\033[0m\n");
    return 0;
}
