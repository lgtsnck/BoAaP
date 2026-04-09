#include <windows.h>
#include "matrix_logic.h"

Matrix g_orig, g_proc;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        TextOut(hdc, 50, 5, "BEFORE PROCESSING:", 18);
        DrawMatrix(hdc, g_orig, 50, 50);

        TextOut(hdc, 350, 5, "AFTER PROCESSING:", 17);
        DrawMatrix(hdc, g_proc, 350, 50);

        EndPaint(hWnd, &ps);
    } else if (msg == WM_DESTROY) {
        PostQuitMessage(0);
    }
    return DefWindowProc(hWnd, msg, wp, lp);
}

int main() {
    g_orig = ReadMatrixFromFile("../data.txt");
    if (!g_orig.data) return 1;

    g_proc = CopyMatrix(g_orig);
    ProcessMatrix(&g_proc);

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "MatrixWin";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("MatrixWin", "Matrix Visualization", WS_OVERLAPPEDWINDOW,
                             100, 100, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(hwnd, SW_SHOW);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    FreeMatrix(&g_orig);
    FreeMatrix(&g_proc);
    return 0;
}