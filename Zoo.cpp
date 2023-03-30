#include "Zoo.h"

Zoo::Zoo()
{
    Cage tempAqua(1, water);
    Cage tempAir(3, air);
    Cage tempLand(10, land);

    this->cages.push_back(tempAqua);
    this->cages.push_back(tempAir);
    this->cages.push_back(tempLand);
}

void Zoo::loadFood()
{
    for (auto cage : this->cages)
    {
        for (auto dino : cage.getDinosInCage())
        {
            foodStorage[dino.getFood()]++;
        }
    }
}