#include "../lib/search/linear_search.h"
#include "./test_util.h"

static void test_found_case(TestState *t) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    LinearSearchResponse res = linear_search(arr, len, key);
    cexpect_enum(res.result, LinearSearchResultFound, t);
    cexpect_enum(res.index, 4, t);
}

static void test_not_found_case(TestState *t) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    LinearSearchResponse res = linear_search(arr, len, key);
    cexpect_enum(res.result, LinearSearchResultNotFound, t)
    cexpect_enum(res.index, -1, t);
}

void linear_search_tests(TestState *t) {
    test_found_case(t);
    test_not_found_case(t);
}

