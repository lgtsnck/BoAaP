#include "array_logic.h"

ArrayData readArrayFromFile(const char* filename) {
    ArrayData res = {NULL, 0};
    FILE *f = fopen(filename, "r");
    if (!f) return res;

    int temp, count = 0;
    while (fscanf(f, "%d", &temp) == 1) count++;

    if (count > 0) {
        res.n = count;
        res.data = (int*)malloc(count * sizeof(int));
        rewind(f);
        for (int i = 0; i < count; i++) fscanf(f, "%d", &res.data[i]);
    }
    fclose(f);
    return res;
}

ArrayData processArray(ArrayData input) {
    ArrayData out = {NULL, 0};
    if (input.n <= 0) return out;

    out.n = input.n;
    out.data = (int*)malloc(input.n * sizeof(int));
    for (int i = 0; i < input.n; i++) out.data[i] = input.data[i];

    int maxLen = 0, maxStart = -1, curLen = 0, curStart = -1;
    for (int i = 0; i < out.n; i++) {
        if (out.data[i] % 2 == 0) {
            if (curLen == 0) curStart = i;
            curLen++;
        } else {
            if (curLen > maxLen) { maxLen = curLen; maxStart = curStart; }
            curLen = 0;
        }
    }
    if (curLen > maxLen) { maxLen = curLen; maxStart = curStart; }

    if (maxStart != -1 && maxLen > 0) {
        if (maxLen == out.n) {
            out.n = 0;
        } else {
            for (int i = maxStart; i < out.n - maxLen; i++) {
                out.data[i] = out.data[i + maxLen];
            }
            out.n -= maxLen;
        }
    }
    return out;
}

void freeArray(ArrayData* arr) {
    if (arr->data) free(arr->data);
    arr->data = NULL;
    arr->n = 0;
}

void writeArrayToFile(const char* filename, ArrayData arr) {
    FILE *f = fopen(filename, "w"); // "w" — режим перезаписи
    if (!f) return;

    for (int i = 0; i < arr.n; i++) {
            fprintf(f, "%d ", arr.data[i]);
    }

    fclose(f);
}