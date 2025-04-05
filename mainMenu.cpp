// mainMenu.cpp
#include <cstdio>
#include <windows.h>
#include <conio.h> // Для _getch()
#include "globals.h"
#include <thread>
#include <chrono>

void updateInsp(){
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        mus.insp++;
    }
}

// Функция для отображения главного меню
void ShowMainMenu() {
    int choice = 0;
    bool running = true;

    while (running) {
        system("cls"); // Очищаем экран
        printf("\n\n\n\n\n\n\n\t\t\t    PainT (ver. 0.1)\n\n\n\n\n\n\n");
        printf("|== Главное меню ======================================================|\n");
        printf("1. Рисовать\n");
        printf("2. Настройки\n");
        printf("3. Выйти\n");
        printf("\n\n\n");
        printf(">_:");
        
        // Используем _getch() для получения ввода сразу при нажатии клавиши
        choice = _getch() - '0'; // Преобразуем символ в цифру

        switch (choice) {
            case 1:
                {
                    std::thread tupdateInsp(updateInsp);
                    gameMenu();
                    return;
                    break;
                }
            case 2:
                printf("Вы выбрали 'Настройки'.\n");
                // Здесь можно добавить логику настроек
                system("pause");
                break;
            case 3:
                printf("Выход из программы...\n");
                exit(1); // Выход из программы
            default:
                break;
        }
    }
}
