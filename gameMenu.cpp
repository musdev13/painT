#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <windows.h>

#include "globals.h"

void gameMenuRend(bool running){
    while (running){
        system("cls");
        printf("Game menu %d", mus.insp);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void gameMenu(){
    bool running = true;
    int choice = 0;
    std::thread tgameMenuRend(gameMenuRend, running);
    while (running)
    {
        choice = _getch()-'0';
        switch (choice)
        {
        case 3:
            tgameMenuRend.detach();
            exit(0);
            break;
        
        default:
            break;
        }
    }
    
}