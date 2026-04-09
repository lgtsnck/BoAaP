#include "bezier_curve.h"

void DrawLinePattern(HDC hdc) {
    HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    SelectObject(hdc, hRedPen);

    int startX = 50, startY = 50;
    int size = 200;
    int step = 10;
    int i = 0;

    while (i <= size) {
        MoveToEx(hdc, startX, startY + i, NULL);
        LineTo(hdc, startX + i, startY + size);

        i += step;
    }

    DeleteObject(hRedPen);
}