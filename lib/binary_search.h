#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdbool.h>

typedef struct {
    bool found;
    int index;
} BinarySearchResponse;

BinarySearchResponse binary_search(const int a[], int n, int key);

#endif
