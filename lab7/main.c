#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "array_functions.h"

int main() {
    SetConsoleOutputCP(65001);

    // Инициализируем указатель в NULL
    int *myArray = NULL;
    int mySize = 0;

    // Передаем адрес указателя (&myArray) и адрес переменной размера (&mySize)
    InputArray(&myArray, &mySize);

    printf("\nИсходный массив:\n");
    // Здесь передаем просто myArray (значение адреса), так как массив только читается
    OutputArray(myArray, mySize);

    // Выполняем логику
    UpdateArray(myArray, &mySize);

    printf("\nРезультат:\n");
    OutputArray(myArray, mySize);

    // Проверка перед освобождением памяти
    if (myArray) {
        free(myArray);
    }

    return 0;
}