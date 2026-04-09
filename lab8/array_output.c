#include "array_functions.h"

void OutputArrayToFile(int *a, int n, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return;

    if (a == NULL || n <= 0) {
        fprintf(f, "Массив пуст.");
    } else {
        for (int i = 0; i < n; i++) {
            fprintf(f, "%d ", a[i]);
        }
    }
    fclose(f);
}