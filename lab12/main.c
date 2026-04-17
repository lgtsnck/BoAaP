#include <stdio.h>
#include "animal.h"
//#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    // Мы заранее выделяем место под 20 животных нашей статической БД
    Animal zoo[20];
    int actualCount = 0; // Переменная для хранения реального количества считанных записей

    // Передаем массив, его максимальный размер и имя файла.
    actualCount = ReadAnimalsFromFile(zoo, 20, "../animals.txt");

    if (actualCount > 0) {
        printf("Загружено записей: %d. Выполняем фильтрацию.\n", actualCount);

        // Проверяем на "травоядность".
        SaveFilteredToFile(zoo, actualCount, "../results.txt");

        printf("Результат сохранен в results.txt\n");
    } else {
        printf("Файл пуст или не найден.\n");
    }

    return 0;
}