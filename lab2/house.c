#include "house.h"

void DrawHouse(HDC hdc) {
    // Выбираем стандартные кисти, чёрную и белую
    SelectObject(hdc, GetStockObject(BLACK_PEN));
    SelectObject(hdc, GetStockObject(WHITE_BRUSH));

    // Рисуем основной корпус (лево: 200, верх: 250, право: 450, низ: 500)
    Rectangle(hdc, 200, 250, 450, 500);

    // Крыша
    // 1. Левый угол крыши, 2. Вершина, 3. Правый угол
    POINT roofPoints[] = { {160, 250}, {325, 80}, {490, 250} };
    // Функция Polygon автоматически соединяет точки и закрашивает внутреннюю область
    Polygon(hdc, roofPoints, 3);

    // Рисуем раму окна
    Rectangle(hdc, 250, 340, 320, 430);

    // Рисуем переплет окна
    MoveToEx(hdc, 285, 340, NULL);
    LineTo(hdc, 285, 430);

    // Рисуем переплет окна
    MoveToEx(hdc, 285, 385, NULL);
    LineTo(hdc, 320, 385);

    // Рисуем прямоугольник двери
    Rectangle(hdc, 360, 375, 420, 500);
}