#include <stdlib.h>

int sum(int x, int y) {
  return x + y;
}

int mul(int x, int y) {
  return x * y;
}

int (*kuku(int (*calc)(int, int)))[9] {
    int (*array)[9] = malloc(9 * sizeof(*array));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            array[i][j] = calc(i + 1, j + 1);
        }
    }
    return array;
}
