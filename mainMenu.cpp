#include <cstdio>
#include <windows.h>
#include <conio.h>
#include "globals.h"
#include <thread>
#include <chrono>

void updateInsp(){
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(15));
        mus.insp++;
    }
}

void ShowMainMenu() {
    int choice = 0;
    bool running = true;

    while (running) {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t    PainT (ver. 0.1)\n\n\n\n\n\n\n");
        printf("|== Главное меню ======================================================|\n");
        printf("1. Рисовать\n");
        printf("2. Настройки\n");
        printf("3. Выйти\n");
        printf("\n\n\n");
        printf(">_:");
        
        choice = _getch() - '0';

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
                system("pause");
                break;
            case 3:
                printf("Выход из программы...\n");
                exit(1);
            default:
                break;
        }
    }
}
