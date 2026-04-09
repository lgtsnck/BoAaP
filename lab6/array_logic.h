#ifndef ARRAY_LOGIC_H
#define ARRAY_LOGIC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int n;
} ArrayData;

ArrayData readArrayFromFile(const char* filename);
ArrayData processArray(ArrayData input);
void freeArray(ArrayData* arr);
void writeArrayToFile(const char* filename, ArrayData arr);

#endif //LAB6_ARRAY_LOGIC_H