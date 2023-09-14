#include "./linear_search.h"

LinearSearchResponse linear_search(const int a[], int n, int key)
{
    int i  = 0;
    while (1) {
        if (i == n) {
            LinearSearchResponse res = { LinearSearchResultNotFound, -1 };
            return res;
        }
        if (a[i] == key) {
            LinearSearchResponse res = { LinearSearchResultFound, i };
            return res;
        }
        i++;
    }
}

