#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "array_functions.h"

int main() {
    SetConsoleOutputCP(65001); // UTF-8

    int *myArray = NULL;
    int mySize = 0;

    InputArrayFromFile(&myArray, &mySize, "../data.txt");

    if (myArray != NULL) {
        UpdateArray(myArray, &mySize);

        OutputArrayToFile(myArray, mySize, "../result.txt");

        free(myArray);
        myArray = NULL;
        printf("Результат в файле result.txt\n");
    }

    return 0;
}