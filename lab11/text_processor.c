#include "text_processor.h"

// Считываем сколько разных букв в слове
int CountUniqueLetters(const char *word) {
    int count = 0;
    char seen[256] = {0}; // Используем массив-флаг, индекс - код символа, значение - была ли буква

    for (int i = 0; word[i] != '\0'; i++) {
        unsigned char c = (unsigned char)word[i];

        // Игнорируем знаки препинания и пробелы
        if (ispunct(c) || isspace(c)) continue;

        // Если символ встретился впервые в слове
        if (seen[c] == 0) {
            seen[c] = 1; // Помечаем, что символ был
            count++;      // Увеличиваем счетчик уникальных
        }
    }
    return count;
}

// Логика удаления разнообразных по буквам слов
void RemoveMaxUniqueWord(char *line) {
    char temp[1024], maxWord[256] = "";
    strcpy(temp, line); // Копируем строку, так как strtok её меняет

    char *token = strtok(temp, " \t\r\n"); // Разбиваем строку на слова
    int maxUnique = -1;

    while (token != NULL) {
        int currentUnique = CountUniqueLetters(token);
        // Ищем слово, где уникальных букв больше всего
        if (currentUnique > maxUnique) {
            maxUnique = currentUnique;
            strcpy(maxWord, token);
        }
        token = strtok(NULL, " \t\r\n");
    }

    // Если слово найдено, вырезаем его из оригинальной строки
    if (maxUnique != -1) {
        char *pos = strstr(line, maxWord); // Ищем вхождение слова в оригинал
        if (pos) {
            size_t len = strlen(maxWord);
            // Если после слова есть пробел, удаляем и его
            if (pos[len] == ' ') len++;
            // Сдвигаем остаток строки влево, затираем удаленное слово
            memmove(pos, pos + len, strlen(pos + len) + 1);
        }
    }
}

void GenerateHTML(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    if (!in || !out) return;

    char line[1024];

    // Формируем шапку HTML-файла
    fprintf(out, "<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"UTF-8\">\n");
    fprintf(out, "<title>Результат обработки</title>\n</head>\n<body>\n");

    // Обрабатываем первую строку отдельно — делаем её заголовком страницы
    if (fgets(line, sizeof(line), in)) {
        line[strcspn(line, "\n")] = 0; // Удаляем символ переноса строки
        fprintf(out, "<h1>%s</h1>\n", line);
    }

    // Читаем остальные строки
    while (fgets(line, sizeof(line), in)) {
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) > 1) {
            RemoveMaxUniqueWord(line); // Применяем нашу логику удаления
            fprintf(out, "<p>%s</p>\n", line); // Заворачиваем строку в тег абзаца
        }
    }

    // Закрываем теги и файлы
    fprintf(out, "</body>\n</html>");
    fclose(in);
    fclose(out);
}
