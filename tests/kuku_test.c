#include "../lib/kuku.h"
#include "./kuku_test.h"
#include "./test_util.h"

void sum_kuku_tests(TestState *t) {
    int (*array)[9] = kuku(sum);

    cexpect_int(array[0][0], 2, t);
    cexpect_int(array[0][1], 3, t);
    cexpect_int(array[0][2], 4, t);
    cexpect_int(array[0][3], 5, t);
    cexpect_int(array[0][4], 6, t);
    cexpect_int(array[0][5], 7, t);

    cexpect_int(array[1][0], 3, t);
    cexpect_int(array[1][1], 4, t);
    cexpect_int(array[1][2], 5, t);
    cexpect_int(array[1][3], 6, t);
    cexpect_int(array[1][4], 7, t);
    cexpect_int(array[1][5], 8, t);

    cexpect_int(array[2][0], 4, t);
    cexpect_int(array[2][1], 5, t);
    cexpect_int(array[2][2], 6, t);
    cexpect_int(array[2][3], 7, t);
    cexpect_int(array[2][4], 8, t);
    cexpect_int(array[2][5], 9, t);

    cexpect_int(array[5][0], 7, t);
    cexpect_int(array[5][1], 8, t);
    cexpect_int(array[5][2], 9, t);
    cexpect_int(array[5][3], 10, t);
    cexpect_int(array[5][4], 11, t);
    cexpect_int(array[5][5], 12, t);

    cexpect_int(array[8][0], 10, t);
    cexpect_int(array[8][1], 11, t);
    cexpect_int(array[8][2], 12, t);
    cexpect_int(array[8][3], 13, t);
    cexpect_int(array[8][4], 14, t);
    cexpect_int(array[8][5], 15, t);

    free(array);
}

void mul_kuku_tests(TestState *t) {
    int (*array)[9] = kuku(mul);

    cexpect_int(array[0][0], 1, t);
    cexpect_int(array[0][1], 2, t);
    cexpect_int(array[0][2], 3, t);
    cexpect_int(array[0][3], 4, t);
    cexpect_int(array[0][4], 5, t);
    cexpect_int(array[0][5], 6, t);

    cexpect_int(array[1][0], 2, t);
    cexpect_int(array[1][1], 4, t);
    cexpect_int(array[1][2], 6, t);
    cexpect_int(array[1][3], 8, t);
    cexpect_int(array[1][4], 10, t);
    cexpect_int(array[1][5], 12, t);

    cexpect_int(array[2][0], 3, t);
    cexpect_int(array[2][1], 6, t);
    cexpect_int(array[2][2], 9, t);
    cexpect_int(array[2][3], 12, t);
    cexpect_int(array[2][4], 15, t);
    cexpect_int(array[2][5], 18, t);

    cexpect_int(array[5][0], 6, t);
    cexpect_int(array[5][1], 12, t);
    cexpect_int(array[5][2], 18, t);
    cexpect_int(array[5][3], 24, t);
    cexpect_int(array[5][4], 30, t);
    cexpect_int(array[5][5], 36, t);

    cexpect_int(array[8][0], 9, t);
    cexpect_int(array[8][1], 18, t);
    cexpect_int(array[8][2], 27, t);
    cexpect_int(array[8][3], 36, t);
    cexpect_int(array[8][4], 45, t);
    cexpect_int(array[8][5], 54, t);

    free(array);
}

void kuku_tests(TestState *t) {
    sum_kuku_tests(t);
}
