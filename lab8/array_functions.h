#ifndef LAB8_ARRAY_FUNCTIONS_H
#define LAB8_ARRAY_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

void InputArrayFromFile(int **a, int *n, const char *filename);
void OutputArrayToFile(int *a, int n, const char *filename);
void UpdateArray(int *a, int *n);

#endif //LAB8_ARRAY_FUNCTIONS_H