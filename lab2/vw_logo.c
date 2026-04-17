#include "vw_logo.h"

void DrawVWLogo(HDC hdc) {
    // Координаты центра и радиусы логотипа
    int cx = 600, cy = 300;
    int r_outer = 100; // Внешний радиус
    int r_inner = 88;  // Внутренний радиус

    // Создаем синюю кисть для фона логотипа
    HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 71, 255));

    // Настройка кисти для пера
    LOGBRUSH lb;
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(255, 255, 255); // Цвет линий будет белым
    lb.lbHatch = 0;

    HPEN hWhitePen = ExtCreatePen(PS_GEOMETRIC | PS_JOIN_ROUND | PS_ENDCAP_ROUND, 10, &lb, 0, NULL);

    HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 71, 255));
    // Прозрачная кисть
    HBRUSH hNoBrush = (HBRUSH)GetStockObject(NULL_BRUSH);

    // Основной синий круг
    SelectObject(hdc, hBlueBrush);
    SelectObject(hdc, hBluePen);
    Ellipse(hdc, cx - r_outer, cy - r_outer, cx + r_outer, cy + r_outer);

    // Внутренняя белая окружность
    SelectObject(hdc, hWhitePen);
    SelectObject(hdc, hNoBrush);
    Ellipse(hdc, cx - r_inner, cy - r_inner, cx + r_inner, cy + r_inner);

    // Рисуем букву 'V'
    POINT vPoints[] = {
        {cx - 36, cy - 76}, // Лехвый верхний конец V
        {cx,      cy - 4},  // Нижняя точка V (по центру)
        {cx + 36, cy - 76}  // Правый верхний конец V
    };
    // Polyline рисует ломаную линию по точкам, не закрашивая область внутри
    Polyline(hdc, vPoints, 3);

    // Рисуем букву 'W'
    POINT wPoints[] = {
        {cx - 84, cy - 10}, // Начало W слева
        {cx - 38, cy + 80}, // Нижний левый угол W
        {cx,      cy + 4},  // Центральный верхний пик W
        {cx + 38, cy + 80}, // Нижний правый угол W
        {cx + 84, cy - 10}  // Конец W справа
    };
    Polyline(hdc, wPoints, 5);

    // Очистка ресурсов
    DeleteObject(hBlueBrush);
    DeleteObject(hBluePen);
    DeleteObject(hWhitePen);
}