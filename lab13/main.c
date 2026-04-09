#include <stdio.h>
#include <windows.h>
#include "my_string.h"

int main() {
    SetConsoleOutputCP(65001);
    char str1[256], str2[256];
    char ch;

    printf("--- Тест my_strchr (Поиск символа) ---\n");
    printf("Введите строку: ");
    gets(str1);
    printf("Введите символ для поиска: ");
    scanf(" %c", &ch);
    char* res_ch = my_strchr(str1, ch);
    printf("Результат: %s\n\n", res_ch ? res_ch : "Символ не найден");

    getchar();

    printf("--- Тест my_strstr (Поиск подстроки) ---\n");
    printf("Введите строку: ");
    gets(str1);
    printf("Введите подстроку: ");
    gets(str2);
    char* res_str = my_strstr(str1, str2);
    printf("Результат: %s\n\n", res_str ? res_str : "Подстрока не найдена");

    printf("--- Тест my_strlwr (Нижний регистр) ---\n");
    printf("Введите строку в ВЕРХНЕМ регистре: ");
    gets(str1);
    printf("Результат: %s\n", my_strlwr(str1));

    return 0;
}