#ifndef LAB9_MATRIX_LOGIC_H
#define LAB9_MATRIX_LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix ReadMatrixFromFile(const char *filename);
Matrix CopyMatrix(Matrix m);
void ProcessMatrix(Matrix *m);
void FreeMatrix(Matrix *m);
void DrawMatrix(HDC hdc, Matrix m, int xOffset, int yOffset);

#endif //LAB9_MATRIX_LOGIC_H