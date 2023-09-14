#include "../lib/search/binary_search.h"
#include "./test_util.h"

static void test_found_case(TestState *t) {
    int arr [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    BinarySearchResponse res = binary_search(arr, len, key);
    cexpect_bool(res.found, true, t);
    cexpect_int(res.index, 6, t);
}

static void test_found_case2(TestState *t) {
    int arr [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 21};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    BinarySearchResponse res = binary_search(arr, len, key);
    cexpect_bool(res.found, true, t);
    cexpect_int(res.index, 3, t);
}

static void test_not_found_case(TestState *t) {
    int arr [] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    BinarySearchResponse res = binary_search(arr, len, key);
    cexpect_bool(res.found, false, t);
    cexpect_int(res.index, -1, t);
};

/* static void  test_show_binary_search_procedure(TestState *t) { */
/*     int arr [] = {3, 6, 7, 13, 21, 39, 50, 79, 102}; */
/*     int len = sizeof(arr) / sizeof(arr[0]); */
/*     int key = 7; */
/* } */

void binary_search_tests(TestState *t) {
    test_found_case(t);
    test_found_case2(t);
    test_not_found_case(t);
    /* test_not_found_case(t); */
}
