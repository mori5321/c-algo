#include "../lib/sentinel_search.h"
#include "./test_util.h"

static void test_found_case(TestState *t) {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    SentinelSearchResponse res = sentinel_search(arr, len, key);
    cexpect_enum(res.found, SentinelSearchResultFound, t);
    cexpect_int(res.index, 2, t);
}

static void test_not_found_case(TestState *t) {
    int sentinel = 0;
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    SentinelSearchResponse res = sentinel_search(arr, len, key);
    cexpect_enum(res.found, SentinelSearchResultNotFound, t);
    cexpect_int(res.index, -1, t);
}

void sentinel_search_tests(TestState *t) {
    test_found_case(t);
    test_not_found_case(t);
}

