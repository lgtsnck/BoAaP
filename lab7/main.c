#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "array_functions.h"

int main() {
    SetConsoleOutputCP(65001);
    int *myArray = NULL;
    int mySize = 0;

    InputArray(&myArray, &mySize);

    printf("\nИсходный массив:\n");
    OutputArray(myArray, mySize);

    UpdateArray(myArray, &mySize);

    printf("\nРезультат:\n");
    OutputArray(myArray, mySize);

    if (myArray) free(myArray);
    return 0;
}