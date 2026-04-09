#include "array_functions.h"

void UpdateArray(int *a, int *n) {
    if (a == NULL || *n <= 0) return;
    int maxLen = 0, maxStart = -1, curLen = 0, curStart = -1;

    for (int i = 0; i < *n; i++) {
        if (a[i] % 2 == 0) {
            if (curLen == 0) curStart = i;
            curLen++;
        } else {
            if (curLen > maxLen) { maxLen = curLen; maxStart = curStart; }
            curLen = 0;
        }
    }
    if (curLen > maxLen) { maxLen = curLen; maxStart = curStart; }

    if (maxStart != -1 && maxLen > 0) {
        for (int i = maxStart; i < *n - maxLen; i++) a[i] = a[i + maxLen];
        *n -= maxLen;
    }
}