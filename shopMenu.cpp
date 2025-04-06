#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <windows.h>

#include "globals.h"

void shopMenuRend(bool* running){
    while (*running){
        system("cls");
        printf("Вдохн.: %d  |  Деньг.: %d\n\n", mus.insp, mus.money);
        printf("|== Магазин ===========================================================|");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("1. \n");
        printf("2. \n");
        printf("3. Назад\n\n");
        printf(">_: ");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void shopMenu(){
    bool running = true;
    int choice = 0;
    std::thread tshopMenuRend(shopMenuRend, &running);
    while (running){
        choice = _getch()-'0';

        switch (choice)
        {
        case 3:
            running = false;
            tshopMenuRend.detach();
            gameMenu();
            return;
            break;
        
        default:
            break;
        }
    }
}