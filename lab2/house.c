#include "house.h"

void DrawHouse(HDC hdc) {

    SelectObject(hdc, GetStockObject(WHITE_BRUSH));

    Rectangle(hdc, 200, 250, 450, 500);

    POINT roofPoints[] = { {160, 250}, {325, 80}, {490, 250} };
    Polygon(hdc, roofPoints, 3);

    Rectangle(hdc, 250, 340, 320, 430);
    MoveToEx(hdc, 285, 340, NULL);
    LineTo(hdc, 285, 430);
    MoveToEx(hdc, 285, 385, NULL);
    LineTo(hdc, 320, 385);

    Rectangle(hdc, 360, 375, 420, 500);
}