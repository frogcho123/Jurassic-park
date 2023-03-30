#include "Cage.h"

Cage::Cage(int _size, Climate _cageClimate)
{
    this->setSize(_size);
    this->cageClimate = _cageClimate;
    this->setCagePeriod();
}

bool Cage::addDino(Dino dino)
{
    if (this->size > this->dinos.size())
    {
        this->dinos.push_back(dino);
        this->setCagePeriod();
        return true;
    }
    return false;
}

bool Cage::deleteDino(std::string dinoName)
{
    for (unsigned int index = 0; index < this->dinos.size(); index++)
    {
        if (this->dinos.at(index).getName() == dinoName)
        {
            this->dinos.erase(dinos.begin() + index);
            if (this->dinos.empty()) this->cagePeriod = Empty;
            return true;
        }
    }
    return false;
}

void Cage::setSize(int _size)
{
    if (_size <= 2) this->size = 1;
    else if (_size <= 9) this->size = 3;
    else this->size = 10;
}

void Cage::setCagePeriod()
{
    if (this->dinos.empty()) this->cagePeriod = Empty;
    else this->cagePeriod = dinos.at(0).getDinoPeriod();
}
