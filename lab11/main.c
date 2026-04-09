#include <stdio.h>
#include "text_processor.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    const char *input = "../data.txt";
    const char *output = "../result.html";

    printf("Обработка файла %s...\n", input);

    GenerateHTML(input, output);

    printf("Результат сохранен в %s\n", output);
    return 0;
}