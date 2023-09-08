#include "../lib/sentinel_search.h"
#include "./test_util.c"

static void test_found_case() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    SentinelSearchResponse res = sentinel_search(arr, len, key);
    cexpect_enum(res.found, SentinelSearchResultFound);
    cexpect_int(res.index, 2);
}

static void test_not_found_case() {
    int sentinel = 0;
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    SentinelSearchResponse res = sentinel_search(arr, len, key);
    cexpect_enum(res.found, SentinelSearchResultNotFound);
    cexpect_int(res.index, -1);
}

void sentinel_search_tests() {
    test_found_case();
    test_not_found_case();
}

