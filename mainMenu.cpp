// mainMenu.cpp
#include <iostream>
#include <windows.h>

// Функция для отображения главного меню
void ShowMainMenu() {
    int choice = 0;
    bool badChoice = false;

    while (true) {
        system("cls"); // Очищаем экран
        printf("\n\n\n\n\n\n\n\t\t\t    PainT (ver. 0.1)\n\n\n\n\n\n\n");
        std::cout << "|== Главное меню ======================================================|\n";
        std::cout << "1. Рисовать\n";
        std::cout << "2. Настройки\n";
        std::cout << "3. Выйти\n";
        if (!badChoice) std::cout << "\n\n\n";
        else printf("\n\nТакого выбора нет\n");
        printf(">_:");
        std::cin >> choice;

        switch (choice) {
            case 1:
                badChoice = false;
                std::cout << "Вы выбрали 'Рисовать'.\n";
                // Здесь можно добавить логику рисования
                system("pause");
                break;
            case 2:
                badChoice = false;
                std::cout << "Вы выбрали 'Настройки'.\n";
                // Здесь можно добавить логику настроек
                system("pause");
                break;
            case 3:
                badChoice = false;
                std::cout << "Выход из программы...\n";
                return; // Выход из программы
            default:
                badChoice = true;
                break;
        }
    }
}
