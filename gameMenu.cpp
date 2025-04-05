#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <windows.h>

#include "globals.h"

void gameMenuRend(){
    while (true){
        system("cls");
        printf("Вдохн.: %d  |  Деньг.: %d\n\n", mus.insp, mus.money);
        printf("|== Статус ============================================================|");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (mus.insp > 0) printf("1. Рисовать\n");
        else printf("1. Рисовать (не хватает вдохн.)\n");
        printf("2. Магазин\n");
        printf("3. Выход\n");
        printf("\n>_: ");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void gameMenu(){
    bool running = true;
    int choice = 0;
    std::thread tgameMenuRend(gameMenuRend);
    while (running)
    {
        choice = _getch()-'0';
        switch (choice)
        {
        case 3:
            // tgameMenuRend.detach();
            exit(0);
            break;
        
        default:
            break;
        }
    }
    
}