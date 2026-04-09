#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");

    int n;

    printf("Введите количество элементов массива N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка ввода размера.\n");
        return 1;
    }

    int *a = (int*)malloc(n * sizeof(int));
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int maxLen = 0;
    int maxStart = -1;

    int curLen = 0;
    int curStart = -1;

    for (int i = 0; i < n; i++) {
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

    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }

    if (maxStart != -1 && maxLen > 0) {
        printf("Самая длинная цепочка четных элементов: ");
        for (int i = maxStart; i < maxStart + maxLen; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        for (int i = maxStart; i < n - maxLen; i++) {
            a[i] = a[i + maxLen];
        }
        n -= maxLen;
    } else {
        printf("Цепочки четных элементов не найдены.\n");
    }

    printf("Результат: массив A[%d]: ", n);
    if (n == 0) {
        printf("пуст (все элементы удалены)");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");

    free(a);

    return 0;
}