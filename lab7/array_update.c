#include "array_functions.h"

void UpdateArray(int *a, int *n) {
    // Проверяем, не пустой ли массив пришел в функцию
    if (a == NULL || *n <= 0) return;

    int maxLen = 0;
    int maxStart = -1;
    int curLen = 0;
    int curStart = -1;

    // Используем *n, так как n — это указатель на размер
    for (int i = 0; i < *n; i++) {
        if (a[i] % 2 == 0) {
            if (curLen == 0) curStart = i;
            curLen++;
        } else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curLen = 0;
        }
    }

    // Проверяем последнюю цепочку, если массив закончился на четном числе
    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    if (maxStart != -1 && maxLen > 0) {
        // Сдвигаем элементы влево, затирая найденную цепочку
        for (int i = maxStart; i < *n - maxLen; i++) {
            a[i] = a[i + maxLen];
        }
        // Разыменовываем n (*n), чтобы уменьшить значение переменной mySize непосредственно в функции main
        *n -= maxLen;
    }
}