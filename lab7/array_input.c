#include "array_functions.h"

void InputArray(int **a, int *n) {
    printf("Введите количество элементов N: ");
    if (scanf("%d", n) != 1 || *n <= 0) return;

    *a = (int*)malloc((*n) * sizeof(int));
    if (*a == NULL) return;

    printf("Введите %d элементов:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &((*a)[i]));
    }
}
