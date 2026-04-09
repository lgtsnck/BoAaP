#ifndef LAB12_ANIMAL_H
#define LAB12_ANIMAL_H

#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct {
    char species[50];    // Вид
    char habitat[50];    // Место обитания
    int isPredator;      // 1 - Хищник, 0 - Травоядное
    int population;      // Популяция
} Animal;

// Чтение всего массива из файла
int ReadAnimalsFromFile(Animal *arr, int maxCount, const char *filename);

// Запись отфильтрованных данных в файл
void SaveFilteredToFile(Animal *arr, int count, const char *filename);

#endif //LAB12_ANIMAL_H