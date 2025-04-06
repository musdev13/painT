#ifndef UPGRADES_H
#define UPGRADES_H

#include <array>
#include <string>

struct UpgradeData {
    bool unlocked;
    int cost;
    std::string name;
};

class Upgrades {
public:
    int lvl;
    std::array<UpgradeData, 2> catalogue1;

    Upgrades(int lvl, std::array<bool, 2> unlockedStatus);
};

#endif
