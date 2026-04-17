#include "scene.h"
#include <math.h>

void DrawComplexScene(HDC hdc) {
    // Создаем сплошную кисть
    HBRUSH hGrassBrush = CreateSolidBrush(RGB(34, 139, 34));
    // Создаем невидимый карандаш
    HPEN hNoPen = CreatePen(PS_NULL, 0, 0);

    // Выбираем кисть и карандаш в контекст устройства
    SelectObject(hdc, hGrassBrush);
    SelectObject(hdc, hNoPen);
    // Рисуем прямоугольник травы
    Rectangle(hdc, 0, 450, 1000, 600);
    // Удаляем объект из памяти
    DeleteObject(hGrassBrush);

    HBRUSH hSunBrush = CreateSolidBrush(RGB(255, 255, 0)); // Желтая заливка
    HPEN hSunPen = CreatePen(PS_SOLID, 3, RGB(255, 215, 0)); // Золотистый контур
    SelectObject(hdc, hSunBrush);
    SelectObject(hdc, hSunPen);
    // Ellipse вписывается в прямоугольник, заданный координатами
    Ellipse(hdc, 50, 50, 150, 150);

    // Рисуем лучи через цикл
    for (int i = 0; i < 12; i++) {
        // Переводим градусы (шаг 30) в радианы для функций cos и sin
        double angle = i * 30 * 3.14159 / 180;
        // Начальная точка луча с отступлением от центра
        MoveToEx(hdc, 100 + cos(angle) * 60, 100 + sin(angle) * 60, NULL);
        // Конечная точка луча
        LineTo(hdc, 100 + cos(angle) * 100, 100 + sin(angle) * 100);
    }
    DeleteObject(hSunBrush);
    DeleteObject(hSunPen);

    HBRUSH hCloudBrush = CreateSolidBrush(RGB(173, 216, 230)); // Голубая заливка
    HPEN hCloudPen = CreatePen(PS_SOLID, 1, RGB(135, 206, 235));
    SelectObject(hdc, hCloudBrush);
    SelectObject(hdc, hCloudPen);

    // Рисуем два облака, каждое состоит из трех перекрывающихся эллипсов
    // Облако 1
    Ellipse(hdc, 200, 70, 280, 120); Ellipse(hdc, 240, 50, 320, 100); Ellipse(hdc, 280, 70, 360, 120);
    // Облако 2
    Ellipse(hdc, 500, 80, 580, 130); Ellipse(hdc, 540, 60, 620, 110); Ellipse(hdc, 580, 80, 660, 130);

    DeleteObject(hCloudBrush);
    DeleteObject(hCloudPen);

    HBRUSH hFenceBrush = CreateSolidBrush(RGB(139, 69, 19)); // Коричневая кисть
    SelectObject(hdc, GetStockObject(BLACK_PEN));
    SelectObject(hdc, hFenceBrush);
    for (int i = 0; i < 10; i++) {
        // Рисуем штакетины с шагом в 30 пикселей
        Rectangle(hdc, 500 + (i * 30), 400, 520 + (i * 30), 500);
    }
    DeleteObject(hFenceBrush);

    HPEN hStemPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); // Зеленый стебель
    HBRUSH hFlowerBrush = CreateSolidBrush(RGB(255, 0, 0)); // Красный бутон

    for (int i = 0; i < 3; i++) {
        int flowerX = 40 + (i * 50); // Позиция цветка по горизонтали
        int flowerY = 480;

        // Рисуем стебель
        SelectObject(hdc, hStemPen);
        MoveToEx(hdc, flowerX, 520, NULL);
        LineTo(hdc, flowerX, flowerY);

        // Рисуем бутон
        SelectObject(hdc, hFlowerBrush);
        Ellipse(hdc, flowerX - 10, flowerY - 10, flowerX + 10, flowerY + 10);
    }

    // Очистка ресурсов
    DeleteObject(hStemPen);
    DeleteObject(hFlowerBrush);
    DeleteObject(hNoPen);
}
