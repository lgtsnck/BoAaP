#include <stdio.h>
#include "array_logic.h"
#include "visual.h"

// Глобальные переменные для хранения данных (оригинальных и обработанных)
ArrayData g_orig, g_proc;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Рисуем две гистограммы одну под другой
        DrawHistogram(hdc, g_orig, 50, 180, "Original Data");
        DrawHistogram(hdc, g_proc, 50, 420, "Processed Data");

        EndPaint(hWnd, &ps);
    } else if (msg == WM_DESTROY) {
        // Завершение программы при закрытии окна
        PostQuitMessage(0);
    }
    return DefWindowProc(hWnd, msg, wp, lp);
}

int main() {
    // Чтение данных из текстового файла
    g_orig = readArrayFromFile("../data.txt");

    if (g_orig.data == NULL) {
        MessageBox(NULL, "Файл не найден.", "Ошибка.", MB_ICONERROR);
        return 1;
    }

    // Обработка данных (создаем новый массив на основе старого)
    g_proc = processArray(g_orig);

    // Сохранение результата обработки в файл
    writeArrayToFile("../result.txt", g_proc);

    // ШАГ 4: Инициализация графического интерфейса
    HINSTANCE hi = GetModuleHandle(NULL);
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hi;
    wc.lpszClassName = "GraphWin";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wc);

    // Создаем окно размером 500x600
    HWND hwnd = CreateWindow("GraphWin", "Array Visualization", WS_OVERLAPPEDWINDOW,
                             100, 100, 500, 600, NULL, NULL, hi, NULL);
    ShowWindow(hwnd, SW_SHOW);

    // Цикл сообщений (стандарт для WinAPI)
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Очистка динамической памяти перед выходом
    freeArray(&g_orig);
    freeArray(&g_proc);

    return 0;
}