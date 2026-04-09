#include <stdio.h>
#include "visual.h"

void DrawHistogram(HDC hdc, ArrayData arr, int x, int y, const char* title) {
    TextOut(hdc, x, y - 160, title, (int)strlen(title));
    MoveToEx(hdc, x, y - 140, NULL); LineTo(hdc, x, y); LineTo(hdc, x + 380, y);

    if (arr.n <= 0 || arr.data == NULL) {
        TextOut(hdc, x + 10, y - 50, "Array is empty", 14);
        return;
    }

    HBRUSH hBrush = CreateSolidBrush(RGB(50, 100, 200));
    SelectObject(hdc, hBrush);
    int barWidth = 350 / arr.n;

    for (int i = 0; i < arr.n; i++) {
        int barHeight = arr.data[i] * 15;
        int left = x + (i * barWidth) + 2;
        int top = y - barHeight;

        Rectangle(hdc, left, top, x + (i + 1) * barWidth - 2, y);

        char valStr[16];
        int len = sprintf(valStr, "%d", arr.data[i]);
        TextOut(hdc, left + (barWidth / 4), top - 20, valStr, len);
    }
    DeleteObject(hBrush);
}