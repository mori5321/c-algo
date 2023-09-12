#include "./binary_search.h"
#include <stdbool.h>

BinarySearchResponse binary_search(const int a[], int n, int key) {
    int pl = 0;
    int pr = n - 1;

    do {
        int pc = (pl + pr) / 2;
        if (a[pc] == key)
            return (BinarySearchResponse){.index = pc, .found = true};
        else if (a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);

    return (BinarySearchResponse){.index = -1, .found = false};
};
