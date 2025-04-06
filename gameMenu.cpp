#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <windows.h>

#include "globals.h"

void gameMenuRend(bool* process, bool* wCount, bool* running){
    while (*running){
        if (!*wCount){
        system("cls");
        printf("Вдохн.: %d  |  Деньг.: %d\n\n", mus.insp, mus.money);
        printf("|== Статус ============================================================|");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (mus.insp > 0 and !*process) {
            printf("1. Рисовать\n");
            printf("2. Магазин\n");
            printf("3. Выход\n");
            printf("\n>_: ");
        }
        else if (*process) printf("В процессе\n\n\n\n");
        else {
            printf("1. Рисовать (не хватает вдохн.)\n");
            printf("2. Магазин\n");
            printf("3. Выход\n");
            printf("\n>_: ");
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));}
    }
}

void paintingProcess(bool* process){
    std::this_thread::sleep_for(std::chrono::seconds(10));
    *process = false;
}

void gameMenu(){
    bool running = true;
    int choice = 0;
    bool process = false;
    bool wCount = false;
    int inspCountToUse;
    std::thread tgameMenuRend(gameMenuRend, &process, &wCount, &running);
    while (running)
    {
        choice = _getch()-'0';
        switch (choice)
        {
        case 3:
            tgameMenuRend.detach();
            exit(0);
            break;
        
        case 1:
            if (mus.insp > 0 and !process){
                wCount = true;
                system("cls");
                printf("Введите кол. вдохн. для исп.\tИм. %d\n>_: ",mus.insp);
                std::cin >> inspCountToUse;
                if (inspCountToUse <= mus.insp){
                    wCount = false;
                    mus.insp -= inspCountToUse;
                    process = true;
                    std::thread tpaintingProcess(paintingProcess, &process);
                    tpaintingProcess.join();
                    mus.money += (inspCountToUse*5)+inspCountToUse;
                }
                else{
                    wCount = false;
                }
            }
            break;
        
        case 2:
            running = false;
            tgameMenuRend.detach();
            shopMenu();
            return;
            break;
        
        default:
            break;
        }
    }
    
}