#include "array_functions.h"

// Передаем n по значению
void OutputArray(int *a, int n) {
    // Eсли указатель пустой или размер 0, выводим сообщение
    if (a == NULL || n <= 0) {
        printf("Массив пуст.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}