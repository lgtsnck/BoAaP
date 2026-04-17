#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");

    int n;

    printf("Введите количество элементов массива N: ");
    // Проверка scanf: он возвращает количество успешно считанных переменных
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка ввода размера.\n");
        return 1;
    }

    // Выделяем место в куче под n целых чисел
    int *a = (int*)malloc(n * sizeof(int));

    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Хранение лучшего результата (самой длинной цепочки)
    int maxLen = 0;
    int maxStart = -1;

    // Хранение текущей цепочки, которую мы считаем в данный момент
    int curLen = 0;
    int curStart = -1;

    // Ищем четные числа
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) { // Если число четное
            if (curLen == 0) curStart = i; // Запоминаем начало новой цепочки
            curLen++;
        } else {
            // Если встретили нечетное, то проверяем, была ли закончившаяся цепочка самой длинной
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curLen = 0; // Сбрасываем счетчик текущей цепочки
        }
    }

    // Финальная проверка после цикла (на случай, если самая длинная цепочка была в самом конце)
    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    // ОБРАБОТКА РЕЗУЛЬТАТА
    if (maxStart != -1 && maxLen > 0) {
        printf("Самая длинная цепочка четных элементов: ");
        for (int i = maxStart; i < maxStart + maxLen; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        // УДАЛЕНИЕ ЦЕПОЧКИ: сдвигаем все элементы, стоящие после цепочки, влево
        for (int i = maxStart; i < n - maxLen; i++) {
            a[i] = a[i + maxLen];
        }
        n -= maxLen; // Уменьшаем логический размер массива
    } else {
        printf("Цепочки четных элементов не найдены.\n");
    }

    // Вывод итогового массива
    printf("Результат: массив A[%d]: ", n);
    if (n == 0) {
        printf("пуст (все элементы удалены)");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");

    // Очищаем память
    free(a);

    return 0;
}