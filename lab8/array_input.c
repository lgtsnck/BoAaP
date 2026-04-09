#include "array_functions.h"

void InputArrayFromFile(int **a, int *n, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Ошибка: файл %s не найден.\n", filename);
        return;
    }

    int temp, count = 0;
    while (fscanf(f, "%d", &temp) == 1) {
        count++;
    }

    if (count > 0) {
        *n = count;
        *a = (int*)malloc((*n) * sizeof(int));
        rewind(f);
        for (int i = 0; i < *n; i++) {
            fscanf(f, "%d", &((*a)[i]));
        }
    }
    fclose(f);
}
