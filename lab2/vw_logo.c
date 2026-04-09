#include "vw_logo.h"

void DrawVWLogo(HDC hdc) {
    int cx = 600, cy = 300;
    int r_outer = 100;
    int r_inner = 88;

    HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 71, 255));

    LOGBRUSH lb;
    lb.lbStyle = BS_SOLID;
    lb.lbColor = RGB(255, 255, 255);
    lb.lbHatch = 0;

    HPEN hWhitePen = ExtCreatePen(PS_GEOMETRIC | PS_JOIN_ROUND | PS_ENDCAP_ROUND, 10, &lb, 0, NULL);
    HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 71, 255));
    HBRUSH hNoBrush = GetStockObject(NULL_BRUSH);

    SelectObject(hdc, hBlueBrush);
    SelectObject(hdc, hBluePen);
    Ellipse(hdc, cx - r_outer, cy - r_outer, cx + r_outer, cy + r_outer);

    SelectObject(hdc, hWhitePen);
    SelectObject(hdc, hNoBrush);
    Ellipse(hdc, cx - r_inner, cy - r_inner, cx + r_inner, cy + r_inner);

    POINT vPoints[] = {
        {cx - 36, cy - 76},
        {cx,      cy - 4},
        {cx + 36, cy - 76}
    };
    Polyline(hdc, vPoints, 3);

    POINT wPoints[] = {
        {cx - 84, cy - 10},
        {cx - 38, cy + 80},
        {cx,      cy + 4},
        {cx + 38, cy + 80},
        {cx + 84, cy - 10}
    };
    Polyline(hdc, wPoints, 5);

    DeleteObject(hBlueBrush);
    DeleteObject(hBluePen);
    DeleteObject(hWhitePen);
}