#include <stdio.h>
#include "animal.h"

int main() {
    SetConsoleOutputCP(65001);

    Animal zoo[20]; // Массив ограничен 20 экземплярами
    int actualCount = 0;

    // 1. Считываем из входного файла
    actualCount = ReadAnimalsFromFile(zoo, 20, "../animals.txt");

    if (actualCount > 0) {
        printf("Загружено записей: %d. Выполняю фильтрацию.\n", actualCount);

        // 2. Обрабатываем и записываем только подходящие в выходной файл
        SaveFilteredToFile(zoo, actualCount, "../results.txt");

        printf("Результат сохранен в results.txt\n");
    }

    return 0;
}