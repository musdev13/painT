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
        switch (upgrades.lvl)
        {
        case 0:
            if (!upgrades.catalogue1[0].unlocked) printf("1. %s (%d)\n", upgrades.catalogue1[0].name, upgrades.catalogue1[0].cost);
            else printf("\n");
            if (!upgrades.catalogue1[1].unlocked) printf("2. %s (%d)\n", upgrades.catalogue1[1].name, upgrades.catalogue1[1].cost);
            else printf("\n");
            break;
        
        default:
            printf("\n\n");
            break;
        }
        
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
        
        case 1:
            switch (upgrades.lvl)
            {
            case 0:
                if ((upgrades.catalogue1[0].cost <= mus.money) && !upgrades.catalogue1[0].unlocked){
                    mus.money -= upgrades.catalogue1[0].cost;
                    upgrades.catalogue1[0].unlocked = true;
                }
                break;
            
            default:
                break;
            }
            break;
        
        case 2:
            switch (upgrades.lvl)
            {
            case 0:
                if ((upgrades.catalogue1[1].cost <= mus.money) && !upgrades.catalogue1[1].unlocked){
                    mus.money -= upgrades.catalogue1[1].cost;
                    upgrades.catalogue1[1].unlocked = true;
                }
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }
    }
}