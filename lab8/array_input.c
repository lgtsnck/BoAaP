#include "array_functions.h"

// Принимаем адрес указателя (**a), чтобы записать туда адрес выделенной памяти
void InputArrayFromFile(int **a, int *n, const char *filename) {
    // Открываем файл для чтения
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Ошибка: файл %s не найден.\n", filename);
        return;
    }

    int temp, count = 0;
    // Считаем количество чисел в файле
    // fscanf возвращает 1, если успешно считал одно целое число
    while (fscanf(f, "%d", &temp) == 1) {
        count++;
    }

    if (count > 0) {
        *n = count; // Записываем количество в переменную mySize в main

        // Выделяем память и записываем её адрес в переменную myArray в main через *a
        *a = (int*)malloc((*n) * sizeof(int));

        // Сбрасываем каретку чтения в самое начало файла
        rewind(f);

        // Считываем числа уже в выделенную память
        for (int i = 0; i < *n; i++) {
            // Записываем число по адресу i-го элемента массива
            fscanf(f, "%d", &((*a)[i]));
        }
    }
    // Закрываем файл
    fclose(f);
}
