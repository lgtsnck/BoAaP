#include "approx_curve.h"

void DrawLinePattern(HDC hdc) {
    HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    SelectObject(hdc, hRedPen);

    // Начальные настройки сетки
    int startX = 50, startY = 50; // Точка начала (левый угол)
    int size = 200;               // Размер области сетки
    int step = 10;                // Плотность сетки
    int i = 0;                    // Счетчик цикла

    // Цикл отрисовки линий
    while (i <= size) {
        MoveToEx(hdc, startX, startY + i, NULL);

        // Проводим линию к нижней горизонтальной границе
        // Координата X смещается вправо, а Y всегда остается на уровне дна (startY + size)
        LineTo(hdc, startX + i, startY + size);

        // Увеличиваем смещение на шаг
        i += step;
    }

    // Удаляем перо из памяти
    DeleteObject(hRedPen);
}