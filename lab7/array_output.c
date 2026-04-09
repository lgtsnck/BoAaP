#include "array_functions.h"

void OutputArray(int *a, int n) {
    if (a == NULL || n <= 0) {
        printf("Массив пуст.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}