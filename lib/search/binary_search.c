#include "./binary_search.h"
#include "../utils/string.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static BinarySearchResponse binary_search_internal(
    const int a[],
    int n,
    int key,
    int *stacks
) {
    int pl = 0;
    int pr = n - 1;

    const bool debug_mode = stacks != NULL ? true : false;
    int stacks_index = -1;

    do {
        int pc = (pl + pr) / 2;

        if (debug_mode) {
            stacks_index++;
            stacks[stacks_index] = pc;
        }

        if (a[pc] == key) {
            return (BinarySearchResponse) { .index = pc, .found = true};
        } else if (a[pc] < key) {
            pl = pc + 1;
        } else {
            pr = pc -1;
        }

    } while (pl <= pr);


    /* for (int pc = (pl + pr) / 2; pl <= pr; pc = (pl + pr) / 2) {     */
    /*     if (a[pc] == key) */
    /*         return (BinarySearchResponse) { .index = pc, .found = true}; */
    /*     else if (a[pc] < key) */
    /*         pl = pc + 1; */
    /*     else */
    /*         pr = pc -1; */
    /* } */

    return (BinarySearchResponse){.index = -1, .found = false};
}

BinarySearchResponse binary_search(const int a[], int n, int key) {
    return binary_search_internal(a, n, key, NULL);
};


typedef struct {
    int *a;
    int *stacks;
    int an;
    int sn;
} Debugger;

Debugger initDebugger(int an, int sn, int *a, int *stacks) {
    Debugger d = {
        .an = an,
        .sn = sn,
        .a = malloc(sizeof(int) * an),
        .stacks = malloc(sizeof(int) * sn),
    };

    d.a = a;
    d.stacks = stacks;

    return d;
}

void free_debugger(Debugger *d) {
    free(d->a);
    free(d->stacks);
    free(d);
}

int countDigits(int n) {
    if (n == 0) return 1;
    return (int)log10(n) + 1;
};

void print_debugger(Debugger *d) {
    int max = d->a[d->an - 1];
    int max_digits = countDigits(max);
    if (max_digits < 3) max_digits = 3;

    char *spaces = (char *)malloc(max_digits);
    char *lines = (char *)malloc(max_digits);
    for (int i = 0; i < max_digits; i++) {
        spaces[i] = ' ';
        lines[i] = '-';
    }

    // 1st line
    printf("%s%s", spaces, "|");
    for (int i = 0; i < d->an; i++) {
        printf("%s%d", spaces, i);
    }
    printf("\n");

    // 2nd line
    printf("%s%s", lines, "+");
    for (int i = 0; i < d->an; i++) {
        printf("%s%s", lines, "-");
    }
    printf("\n");

    // 3rd line
    for (int i = 0; i < d->sn; i++) {
        printf("%s%s", spaces, "|");

        for (int j = 0; j < d->an; j++) {
            if (d->stacks[i] == j) {
                printf("%s%s", spaces, "*");
            } else {
                printf("%s%s", spaces, " ");
            }
        }

        printf("\n");

        for (int k = 0; k < d->an + 1; k++) {
            if (k == 0) {
                int spaces_size = max_digits - countDigits(i);
                char *spaces2 = (char *)malloc(spaces_size);
                for (int l = 0; l < spaces_size; l++) {
                    spaces2[l] = ' ';
                }
                printf("%s%d%s", spaces2, i, "|");
                free(spaces2);
            } else {
                printf("%s%d", spaces, d->a[k - 1]);
            }
        }

        printf("\n");
    }
    
    free(spaces);
    free(lines);

    printf("\n\n");
}

BinarySearchResponse debug_binary_search(int a[], int n, int key) {
    int stacks[n];

    for (int i = 0; i < n; i++) {
        stacks[i] = -1;
    }

    BinarySearchResponse res = binary_search_internal(a, n, key, stacks);

    
    int sn = 0;
    for (int i = 0; i < n && stacks[i] != -1 ; i++) {
        sn++;
    }


    Debugger d = initDebugger(n, sn, a, stacks);
    print_debugger(&d);

    return res;
};


/* static void print_search_display(SearchDisplay *sd, int len) { */
/*     // 1st line */
/*     printf("   |"); */
/*     for (int i = 0; i < len; i++) { */
/*         printf("   %d", i); */
/*     } */
/*     printf("\n"); */
/*      */
/*     // 2nd line */
/*     printf("---+"); */
/*     for (int i = 0; i < len; i++) { */
/*         printf("----"); */
/*     } */
/*     printf("\n"); */
/*      */
/*     sd->search_fn(sd->a, sd->current, sd->key); */
/*  */
/*     // 3rd line */
/*     printf("   |"); */
/*     for (int i = 0; i < len; i++) { */
/*         printf("   %d", sd->a[i]); */
/*     } */
/*     printf("\n");  */
/* } */

