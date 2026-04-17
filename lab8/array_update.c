#include "array_functions.h"

void UpdateArray(int *a, int *n) {
    // Базовая проверка: если массив не выделен или пуст, ничего не делаем
    if (a == NULL || *n <= 0) return;

    int maxLen = 0, maxStart = -1, curLen = 0, curStart = -1;

    // Цикл поиска самой длинной последовательности четных чисел
    for (int i = 0; i < *n; i++) {
        if (a[i] % 2 == 0) { // Проверка на четность
            if (curLen == 0) curStart = i; // Фиксируем начало новой цепочки
            curLen++;
        } else {
            // Если цепочка прервалась, проверяем, длиннее ли она предыдущего рекорда
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curLen = 0; // Сбрасываем счетчик для поиска следующей цепочки
        }
    }
    // Проверка на случай, если самая длинная цепочка оказалась в самом конце массива
    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    // Если цепочка найдена (maxStart больше -1)
    if (maxStart != -1 && maxLen > 0) {
        // Сдвигаем все элементы, идущие после цепочки, на её место
        for (int i = maxStart; i < *n - maxLen; i++) {
            a[i] = a[i + maxLen];
        }
        // Уменьшаем значение переменной mySize в функции main через разыменование
        *n -= maxLen;
    }
}