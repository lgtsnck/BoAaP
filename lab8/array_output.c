#include "array_functions.h"

void OutputArrayToFile(int *a, int n, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return; // Если не удалось создать файл (например, нет прав доступа)

    // Проверка на пустоту данных
    if (a == NULL || n <= 0) {
        // Первым аргументом принимаем указатель на файл
        fprintf(f, "Массив пуст.");
    } else {
        // Проходим по массиву и записываем каждое число в файл через пробел
        for (int i = 0; i < n; i++) {
            fprintf(f, "%d ", a[i]);
        }
    }

    fclose(f);
}