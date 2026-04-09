#include "text_processor.h"

int CountUniqueLetters(const char *word) {
    int count = 0;
    char seen[256] = {0};

    for (int i = 0; word[i] != '\0'; i++) {
        unsigned char c = (unsigned char)word[i];

        if (ispunct(c) || isspace(c)) continue;

        if (seen[c] == 0) {
            seen[c] = 1;
            count++;
        }
    }
    return count;
}

void RemoveMaxUniqueWord(char *line) {
    char temp[1024], maxWord[256] = "";
    strcpy(temp, line);

    char *token = strtok(temp, " \t\r\n");
    int maxUnique = -1;

    while (token != NULL) {
        int currentUnique = CountUniqueLetters(token);
        if (currentUnique > maxUnique) {
            maxUnique = currentUnique;
            strcpy(maxWord, token);
        }
        token = strtok(NULL, " \t\r\n");
    }

    if (maxUnique != -1) {
        char *pos = strstr(line, maxWord);
        if (pos) {
            size_t len = strlen(maxWord);
            if (pos[len] == ' ') len++;
            memmove(pos, pos + len, strlen(pos + len) + 1);
        }
    }
}

void GenerateHTML(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");
    if (!in || !out) return;

    char line[1024];

    fprintf(out, "<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"UTF-8\">\n");
    fprintf(out, "<title>Результат обработки</title>\n</head>\n<body>\n");

    if (fgets(line, sizeof(line), in)) {
        line[strcspn(line, "\n")] = 0;
        fprintf(out, "<h1>%s</h1>\n", line);
    }

    while (fgets(line, sizeof(line), in)) {
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) > 1) {
            RemoveMaxUniqueWord(line);
            fprintf(out, "<p>%s</p>\n", line);
        }
    }

    fprintf(out, "</body>\n</html>");
    fclose(in);
    fclose(out);
}
