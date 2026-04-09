#include "matrix_logic.h"

Matrix ReadMatrixFromFile(const char *filename) {
    Matrix m = {NULL, 0, 0};
    FILE *f = fopen(filename, "r");
    if (!f) return m;

    fscanf(f, "%d %d", &m.rows, &m.cols);
    m.data = (int **)malloc(m.rows * sizeof(int *));
    for (int i = 0; i < m.rows; i++) {
        m.data[i] = (int *)malloc(m.cols * sizeof(int));
        for (int j = 0; j < m.cols; j++) {
            fscanf(f, "%d", &m.data[i][j]);
        }
    }
    fclose(f);
    return m;
}

Matrix CopyMatrix(Matrix m) {
    Matrix res;
    res.rows = m.rows;
    res.cols = m.cols;
    res.data = (int **)malloc(res.rows * sizeof(int *));
    for (int i = 0; i < res.rows; i++) {
        res.data[i] = (int *)malloc(res.cols * sizeof(int));
        for (int j = 0; j < res.cols; j++) {
            res.data[i][j] = m.data[i][j];
        }
    }
    return res;
}

void ProcessMatrix(Matrix *m) {
    for (int j = 0; j < m->cols; j++) {
        int hasDuplicate = 0;
        for (int i = 0; i < m->rows - 1; i++) {
            for (int k = i + 1; k < m->rows; k++) {
                if (m->data[i][j] == m->data[k][j]) {
                    hasDuplicate = 1;
                    break;
                }
            }
            if (hasDuplicate) break;
        }

        if (hasDuplicate) {
            for (int r = 0; r < m->rows; r++) {
                for (int c = j; c < m->cols - 1; c++) {
                    m->data[r][c] = m->data[r][c + 1];
                }
            }
            m->cols--;
            j--;
        }
    }
}

void FreeMatrix(Matrix *m) {
    if (m->data) {
        for (int i = 0; i < m->rows; i++) free(m->data[i]);
        free(m->data);
    }
    m->data = NULL;
}
