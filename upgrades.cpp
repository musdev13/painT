#include "upgrades.h"

Upgrades::Upgrades(int lvl, std::array<bool, 2> unlockedStatus) {
    this->lvl = lvl;

    catalogue1[0] = {unlockedStatus[0], 50, "Купить Тел. (Уск. Вдохн.)"};
    catalogue1[1] = {unlockedStatus[1], 100, "Учиться рисов. (Больш. денег)"};
}
