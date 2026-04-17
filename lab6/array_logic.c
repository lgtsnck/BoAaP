#include "array_logic.h"

// Динамически определяем размер массива по содержимому файла
ArrayData readArrayFromFile(const char* filename) {
    ArrayData res = {NULL, 0};
    FILE *f = fopen(filename, "r"); // Открываем файл для чтения ("r")
    if (!f) return res;

    int temp, count = 0;
    // Считаем, сколько чисел в файле
    while (fscanf(f, "%d", &temp) == 1) count++;

    if (count > 0) {
        res.n = count;
        res.data = (int*)malloc(count * sizeof(int)); // Выделяем память
        rewind(f); // Сбрасываем указатель чтения в начало файла для второго прохода
        for (int i = 0; i < count; i++) {
            fscanf(f, "%d", &res.data[i]); // Считываем данные в массив
        }
    }
    fclose(f); // Обязательно закрываем файл
    return res;
}

// Ищем и удаляем самую длинную четную цепочку
ArrayData processArray(ArrayData input) {
    ArrayData out = {NULL, 0};
    if (input.n <= 0) return out;

    // Сначала создаем копию входного массива, чтобы не испортить оригинал - g_orig
    out.n = input.n;
    out.data = (int*)malloc(input.n * sizeof(int));
    for (int i = 0; i < input.n; i++) out.data[i] = input.data[i];

    // Алгоритм поиска самой длинной цепочки
    int maxLen = 0, maxStart = -1, curLen = 0, curStart = -1;
    for (int i = 0; i < out.n; i++) {
        if (out.data[i] % 2 == 0) {
            if (curLen == 0) curStart = i;
            curLen++;
        } else {
            if (curLen > maxLen) { maxLen = curLen; maxStart = curStart; }
            curLen = 0;
        }
    }
    if (curLen > maxLen) { maxLen = curLen; maxStart = curStart; }

    // Если цепочка найдена, то удаляем её сдвигом элементов влево
    if (maxStart != -1 && maxLen > 0) {
        if (maxLen == out.n) {
            out.n = 0; // Случай, если весь массив состоял из одной четной цепочки
        } else {
            for (int i = maxStart; i < out.n - maxLen; i++) {
                out.data[i] = out.data[i + maxLen];
            }
            out.n -= maxLen;
        }
    }
    return out;
}

// Освобождаем память
void freeArray(ArrayData* arr) {
    if (arr->data) free(arr->data);
    arr->data = NULL; // Зануляем указатель, чтобы избежать "висячих ссылок"
    arr->n = 0;
}

// Сохраняем результат в текстовый файл
void writeArrayToFile(const char* filename, ArrayData arr) {
    FILE *f = fopen(filename, "w"); // Создаём/перезаписываем файл с результатами
    if (!f) return;

    for (int i = 0; i < arr.n; i++) {
        fprintf(f, "%d ", arr.data[i]); // Записываем числа через пробел
    }

    fclose(f);
}