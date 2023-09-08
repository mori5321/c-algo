#include "./sentinel_search.h"

SentinelSearchResponse sentinel_search(int a[], int n, int key) {
    int i = 0;
    a[n] = key; // add sentinel
    
    while (1) {
        if (a[i] == key) {
            break; // 見つかるまたは 番兵にたどりついた場合 break
        }
        i++;
    }

    if (i == n) {
        SentinelSearchResponse res = { SentinelSearchResultNotFound, -1 };
        return res;
    } else {
        SentinelSearchResponse res = { SentinelSearchResultFound, i };
        return res;
    }
}
