#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "array_functions.h"

int main() {
    SetConsoleOutputCP(65001);

    int *myArray = NULL;
    int mySize = 0;

    // Передаем адреса (&myArray, &mySize), чтобы функция выделила память и записала размер
    // Также передаем путь к файлу
    InputArrayFromFile(&myArray, &mySize, "../data.txt");

    // Проверяем, удалось ли считать данные
    if (myArray != NULL) {

        // Используем функцию из 7-й лабы
        UpdateArray(myArray, &mySize);

        // Записываем измененный массив в новый файл
        OutputArrayToFile(myArray, mySize, "../result.txt");

        // Очистка памяти
        free(myArray);
        myArray = NULL;
        printf("Результат сохранен в файле result.txt\n");
    } else {
        printf("Не удалось получить данные из файла.\n");
    }

    return 0;
}