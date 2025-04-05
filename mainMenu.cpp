// mainMenu.cpp
#include <cstdio>
#include <windows.h>
#include <conio.h> // Для _getch()
#include "globals.h"


// Функция для отображения главного меню
void ShowMainMenu() {
    int choice = 0;
    bool badChoice = false;
    bool running = true;

    while (running) {
        system("cls"); // Очищаем экран
        printf("\n\n\n\n\n\n\n\t\t\t    PainT (ver. 0.1)\n\n\n\n\n\n\n");
        printf("|== Главное меню ======================================================|\n");
        printf("1. Рисовать\n");
        printf("2. Настройки\n");
        printf("3. Выйти\n");
        if (!badChoice) 
            printf("\n\n\n");
        else 
            printf("\n\nТакого выбора нет\n");
        printf(">_:");
        
        // Используем _getch() для получения ввода сразу при нажатии клавиши
        choice = _getch() - '0'; // Преобразуем символ в цифру

        switch (choice) {
            case 1:
                running = false;
                gameMenu();
                return;
                break;
            case 2:
                badChoice = false;
                printf("Вы выбрали 'Настройки'.\n");
                // Здесь можно добавить логику настроек
                system("pause");
                break;
            case 3:
                badChoice = false;
                printf("Выход из программы...\n");
                return; // Выход из программы
            default:
                badChoice = true;
                break;
        }
    }
}
