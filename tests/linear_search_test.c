#include "../lib/linear_search.h"
#include "./test_util.c"

static void test_found_case(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    LinearSearchResponse res = linear_search(arr, len, key);
    cexpect_enum(res.result, LinearSearchResultFound);
    cexpect_enum(res.index, 4);
}

static void test_not_found_case(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    LinearSearchResponse res = linear_search(arr, len, key);
    cexpect_enum(res.result, LinearSearchResultNotFound)
    cexpect_enum(res.index, -1);
}

void linear_search_tests(void) {
    test_found_case();
    test_not_found_case();
}

