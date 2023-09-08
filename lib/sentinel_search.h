#ifndef SENTINEL_SEARCH
#define SENTINEL_SEARCH

// golangのエラー風味にしたい
typedef enum {
    SentinelSearchResultFound,
    SentinelSearchResultNotFound
} SentinelSearchResult;

typedef struct {
    SentinelSearchResult found;
    int index;
} SentinelSearchResponse;

SentinelSearchResponse sentinel_search(int a[], int n, int key);

#endif
