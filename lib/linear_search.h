#ifndef LINEAR_SEARCH_TEST
#define LINEAR_SEARCH_TEST


typedef enum {
    LinearSearchResultFound,
    LinearSearchResultNotFound
} LinearSearchResult;

typedef struct {
    LinearSearchResult result;
    int index;
} LinearSearchResponse;

LinearSearchResponse linear_search(const int a[], int n, int key);

#endif
