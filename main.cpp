// main.cpp
#include <iostream>
#include <windows.h>
#include "globals.h"

// Функция для изменения размера консоли
void ResizeConsole() {
    HWND hwnd = GetConsoleWindow();
    Sleep(10);
    HWND owner = GetWindow(hwnd, GW_OWNER);

    if (owner == NULL) {
        SetWindowPos(hwnd, nullptr, 0, 0, 50, 50, SWP_NOZORDER | SWP_NOMOVE);
    } else {
        SetWindowPos(owner, nullptr, 0, 0, 700, 500, SWP_NOZORDER | SWP_NOMOVE);
    }
}

Artist mus(1,0);

int main() {
    ResizeConsole();  // Изменяем размер консоли
    system("title painT");

    // Запускаем главное меню
    ShowMainMenu();

    return 0;
}
