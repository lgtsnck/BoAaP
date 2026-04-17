#include <stdio.h>
#include <windows.h>
#include "house.h"
#include "vw_logo.h"
#include "scene.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_PAINT: {
            // Отрисовка окна
            PAINTSTRUCT ps;
            // Подготовка окна и возврат контекста
            HDC hdc = BeginPaint(hWnd, &ps);

            // Передача дескриптора контекста в функции отрисовки
            DrawComplexScene(hdc);
            DrawHouse(hdc);
            DrawVWLogo(hdc);

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

    //printf("Запуск графического окна...\n");

    // Получаем идентификатор текущего приложения
    HINSTANCE hInstance = GetModuleHandle(NULL);
    const char CLASS_NAME[] = "lab2";

    // Описываем класс окна, настройки внешнего вида и поведения
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    // Если класс не задан, завершаем работу
    if (!RegisterClass(&wc)) {
        printf("Ошибка регистрации класса.\n");
        return 1;
    }

    // Создание окна
    HWND hWnd = CreateWindowEx(
        0, CLASS_NAME, "lab2",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        1000, 600, NULL, NULL, hInstance, NULL
    );

    // Если ничего не передано, завершаем работу
    if (hWnd == NULL) return 1;

    // Показ окна приложения
    ShowWindow(hWnd, SW_SHOW);

    // Запуск окна до передачи вызова завершения
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //printf("Программа завершена.\n");
    return 0;
}