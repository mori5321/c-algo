#include "../lib/binary_search.h"
#include "./test_util.h"

static void test_found_case(TestState *t) {
    int arr [] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    BinarySearchResponse res = binary_search(arr, len, key);
    cexpect_bool(res.found, true, t);
    cexpect_int(res.index, 2, t);
}

static void test_not_found_case(TestState *t) {
    int arr [] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    BinarySearchResponse res = binary_search(arr, len, key);
    cexpect_bool(res.found, false, t);
    cexpect_int(res.index, -1, t);
};

void binary_search_tests(TestState *t) {
    test_found_case(t);
    test_not_found_case(t);
}
