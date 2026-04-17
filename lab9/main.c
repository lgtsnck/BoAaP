#include <windows.h>
#include "matrix_logic.h"

// Глобальные переменные для хранения матриц (до и после обработки)
Matrix g_orig, g_proc;

// Оконная процедура для отрисовки матриц в интерфейсе
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Подпись и отрисовка исходной матрицы (левая часть окна)
        TextOut(hdc, 50, 5, "BEFORE PROCESSING:", 18);
        DrawMatrix(hdc, g_orig, 50, 50);

        // Подпись и отрисовка измененной матрицы (правая часть окна)
        TextOut(hdc, 350, 5, "AFTER PROCESSING:", 17);
        DrawMatrix(hdc, g_proc, 350, 50);

        EndPaint(hWnd, &ps);
    } else if (msg == WM_DESTROY) {
        PostQuitMessage(0);
    }
    return DefWindowProc(hWnd, msg, wp, lp);
}

int main() {
    // Читаем матрицу из файла
    g_orig = ReadMatrixFromFile("../data.txt");
    if (!g_orig.data) return 1; // Если данных нет, закрываемся

    // Создаем копию матрицы, чтобы оригинал остался нетронутым для сравнения
    g_proc = CopyMatrix(g_orig);
    // Обрабатываем копию (передаем по адресу, так как матрица может измениться)
    ProcessMatrix(&g_proc);

    // Стандартная регистрация класса окна WinAPI
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "MatrixWin";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("MatrixWin", "Matrix Visualization", WS_OVERLAPPEDWINDOW,
                             100, 100, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(hwnd, SW_SHOW);

    // Главный цикл сообщений
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    FreeMatrix(&g_orig);
    FreeMatrix(&g_proc);
    return 0;
}