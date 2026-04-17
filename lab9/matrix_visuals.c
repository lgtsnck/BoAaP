#include <windows.h>
#include "matrix_logic.h"

void DrawMatrix(HDC hdc, Matrix m, int xOffset, int yOffset) {
    int cellSize = 50; // Размер одной ячейки (квадрата) в пикселях

    // Выводим текущий размер матрицы над ней
    char sizeBuf[32];
    int sizeLen = sprintf(sizeBuf, "Size: %dx%d", m.rows, m.cols);
    TextOut(hdc, xOffset, yOffset - 25, sizeBuf, sizeLen);

    // Палитра цветов для раскраски ячеек
    COLORREF colors[] = {
        RGB(255, 100, 100), // Красный
        RGB(100, 255, 100), // Зеленый
        RGB(100, 100, 255), // Синий
        RGB(255, 255, 100)  // Желтый
    };

    // Устанавливаем прозрачный фон для текста, чтобы он не затирал цвет ячейки своим белым фоном
    SetBkMode(hdc, TRANSPARENT);

    // Двойной цикл для прохода по строкам и столбцам
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            // Выбираем цвет на основе значения числа в ячейке (остаток от деления на 4)
            int colorIdx = m.data[i][j] % 4;
            HBRUSH hBrush = CreateSolidBrush(colors[colorIdx]);
            SelectObject(hdc, hBrush);

            // Рисуем квадрат ячейки
            Rectangle(hdc,
                      xOffset + j * cellSize,
                      yOffset + i * cellSize,
                      xOffset + (j + 1) * cellSize,
                      yOffset + (i + 1) * cellSize);

            // Превращаем число в строку и выводим его в центре ячейки
            char buf[16];
            int len = sprintf(buf, "%d", m.data[i][j]);
            // Смещение +18 и +15 для центрирования
            TextOut(hdc, xOffset + j * cellSize + 18, yOffset + i * cellSize + 15, buf, len);

            // Очищаем кисть после каждой ячейки
            DeleteObject(hBrush);
        }
    }
}
