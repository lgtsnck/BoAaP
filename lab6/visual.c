#include <stdio.h>
#include "visual.h"

void DrawHistogram(HDC hdc, ArrayData arr, int x, int y, const char* title) {
    // Выводим заголовок гистограммы чуть выше самой области рисования
    TextOut(hdc, x, y - 160, title, (int)strlen(title));

    // Рисуем оси координат (L-образная линия)
    MoveToEx(hdc, x, y - 140, NULL);
    LineTo(hdc, x, y);           // Вертикальная ось
    LineTo(hdc, x + 380, y);     // Горизонтальная ось

    // Если массив пуст, выводим соответствующее уведомление
    if (arr.n <= 0 || arr.data == NULL) {
        TextOut(hdc, x + 10, y - 50, "Array is empty", 14);
        return;
    }

    // Создаем кисть приятного синего цвета для столбиков
    HBRUSH hBrush = CreateSolidBrush(RGB(50, 100, 200));
    SelectObject(hdc, hBrush);

    // Рассчитываем ширину одного столбика исходя из доступного места
    int barWidth = 350 / arr.n;

    for (int i = 0; i < arr.n; i++) {
        // Умножаем значение на 15, чтобы столбики были видны
        int barHeight = arr.data[i] * 15;

        // Координаты конкретного столбика
        int left = x + (i * barWidth) + 2; // +2 для небольшого отступа между ними
        int top = y - barHeight;           // Вычитаем из Y, так как ось Y направлена вниз

        // Рисуем столбик
        Rectangle(hdc, left, top, x + (i + 1) * barWidth - 2, y);

        // Печатаем само число над каждым столбиком
        char valStr[16];
        int len = sprintf(valStr, "%d", arr.data[i]);
        TextOut(hdc, left + (barWidth / 4), top - 20, valStr, len);
    }

    DeleteObject(hBrush);
}