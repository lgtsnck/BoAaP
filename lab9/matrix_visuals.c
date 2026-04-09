#include <windows.h>
#include "matrix_logic.h"

void DrawMatrix(HDC hdc, Matrix m, int xOffset, int yOffset) {
    int cellSize = 50;

    char sizeBuf[32];
    int sizeLen = sprintf(sizeBuf, "Size: %dx%d", m.rows, m.cols);
    TextOut(hdc, xOffset, yOffset - 25, sizeBuf, sizeLen);

    COLORREF colors[] = {
        RGB(255, 100, 100),
        RGB(100, 255, 100),
        RGB(100, 100, 255),
        RGB(255, 255, 100)
    };

    SetBkMode(hdc, TRANSPARENT);

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            int colorIdx = m.data[i][j] % 4;
            HBRUSH hBrush = CreateSolidBrush(colors[colorIdx]);
            SelectObject(hdc, hBrush);

            Rectangle(hdc,
                      xOffset + j * cellSize,
                      yOffset + i * cellSize,
                      xOffset + (j + 1) * cellSize,
                      yOffset + (i + 1) * cellSize);

            char buf[16];
            int len = sprintf(buf, "%d", m.data[i][j]);
            TextOut(hdc, xOffset + j * cellSize + 18, yOffset + i * cellSize + 15, buf, len);

            DeleteObject(hBrush);
        }
    }
}
