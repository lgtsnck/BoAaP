#include <stdio.h>
#include <windows.h>
#include "bezier_curve.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            DrawLinePattern(hdc);

            EndPaint(hWnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int main(void) {
    printf("Запуск графического окна...\n");

    HINSTANCE hInstance = GetModuleHandle(NULL);
    const char CLASS_NAME[] = "HouseWindowClass";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClass(&wc)) {
        printf("Ошибка регистрации класса.\n");
        return 1;
    }

    HWND hWnd = CreateWindowEx(
        0, CLASS_NAME, "lab3",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        400, 400, NULL, NULL, hInstance, NULL
    );

    if (hWnd == NULL) return 1;

    ShowWindow(hWnd, SW_SHOW);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    printf("Программа завершена.\n");
    return 0;
}