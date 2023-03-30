#ifndef MITKO_ZOO_H
#define MITKO_ZOO_H

#include "Cage.h"

class Zoo
{
private:
    std::vector<Cage> cages;
    int foodStorage[3] = { 0, 0, 0 };
    // 0 -> grass
    // 1 -> meat
    // 3 -> fish
public:
    Zoo();

    inline std::vector<Cage> getCages() { return this->cages; }
    inline void addCage(Cage cage) { this->cages.push_back(cage); };

    inline int* getFood() { return this->foodStorage; }
    void loadFood();
};

#endif //MITKO_ZOO_H