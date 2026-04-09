#include "scene.h"
#include <math.h>

void DrawComplexScene(HDC hdc) {

    HBRUSH hGrassBrush = CreateSolidBrush(RGB(34, 139, 34));
    HPEN hNoPen = CreatePen(PS_NULL, 0, 0);
    SelectObject(hdc, hGrassBrush);
    SelectObject(hdc, hNoPen);
    Rectangle(hdc, 0, 450, 1000, 600);
    DeleteObject(hGrassBrush);

    HBRUSH hSunBrush = CreateSolidBrush(RGB(255, 255, 0));
    HPEN hSunPen = CreatePen(PS_SOLID, 3, RGB(255, 215, 0));
    SelectObject(hdc, hSunBrush);
    SelectObject(hdc, hSunPen);
    Ellipse(hdc, 50, 50, 150, 150); // Круг

    for (int i = 0; i < 12; i++) {
        double angle = i * 30 * 3.14159 / 180;
        MoveToEx(hdc, 100 + cos(angle) * 60, 100 + sin(angle) * 60, NULL);
        LineTo(hdc, 100 + cos(angle) * 100, 100 + sin(angle) * 100);
    }
    DeleteObject(hSunBrush);
    DeleteObject(hSunPen);

    HBRUSH hCloudBrush = CreateSolidBrush(RGB(173, 216, 230));
    HPEN hCloudPen = CreatePen(PS_SOLID, 1, RGB(135, 206, 235));

    SelectObject(hdc, hCloudBrush);
    SelectObject(hdc, hCloudPen);

    Ellipse(hdc, 200, 70, 280, 120); Ellipse(hdc, 240, 50, 320, 100); Ellipse(hdc, 280, 70, 360, 120);

    Ellipse(hdc, 500, 80, 580, 130); Ellipse(hdc, 540, 60, 620, 110); Ellipse(hdc, 580, 80, 660, 130);

    DeleteObject(hCloudBrush);
    DeleteObject(hCloudPen);

    HBRUSH hFenceBrush = CreateSolidBrush(RGB(139, 69, 19));
    SelectObject(hdc, hFenceBrush);
    for (int i = 0; i < 10; i++) {
        Rectangle(hdc, 500 + (i * 30), 400, 520 + (i * 30), 500);
    }
    DeleteObject(hFenceBrush);

    HPEN hStemPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    HBRUSH hFlowerBrush = CreateSolidBrush(RGB(255, 0, 0));

    for (int i = 0; i < 3; i++) {
        int flowerX = 40 + (i * 50);
        int flowerY = 480;

        SelectObject(hdc, hStemPen);
        MoveToEx(hdc, flowerX, 520, NULL);
        LineTo(hdc, flowerX, flowerY);

        SelectObject(hdc, hFlowerBrush);
        Ellipse(hdc, flowerX - 10, flowerY - 10, flowerX + 10, flowerY + 10);
    }

    DeleteObject(hStemPen);
    DeleteObject(hFlowerBrush);
    DeleteObject(hNoPen);
}
