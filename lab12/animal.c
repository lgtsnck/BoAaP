#include "animal.h"

int ReadAnimalsFromFile(Animal *arr, int maxCount, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Ошибка: файл %s не найден.\n", filename);
        return 0;
    }

    int count = 0;
    // Читаем, пока не достигнем конца файла или лимита в 20 записей
    while (count < maxCount && fscanf(f, "%s %s %d %d",
           arr[count].species, arr[count].habitat,
           &arr[count].isPredator, &arr[count].population) == 4) {
        count++;
           }

    fclose(f);
    return count;
}

void SaveFilteredToFile(Animal *arr, int count, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return;

    fprintf(f, "--- Травоядные с популяцией менее 10 000 ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        // Условие по варианту: Травоядное (0) И популяция < 10000
        if (arr[i].isPredator == 0 && arr[i].population < 10000) {
            fprintf(f, "Вид: %-15s | Обитание: %-15s | Популяция: %d\n",
                    arr[i].species, arr[i].habitat, arr[i].population);
            found = 1;
        }
    }

    if (!found) fprintf(f, "Подходящие записи не найдены.\n");
    fclose(f);
}