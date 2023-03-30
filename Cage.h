#ifndef MITKO_CAGE_H
#define MITKO_CAGE_H

#include <string>
#include <vector>

#include "Dino.h"

enum Climate { land, air, water };

class Cage
{
private:
    int size = 0;
    // 1 -> small,
    // 3 -> medium,
    // 10 -> big

    Climate cageClimate;
    std::vector<Dino> dinos;
    Period cagePeriod = Empty;

public:
    Cage() = default;
    Cage(int, Climate);

    inline std::vector<Dino> getDinosInCage() { return this->dinos; }
    bool addDino(Dino);
    bool deleteDino(std::string);

    inline int getSize() { return this->size; }
    void setSize(int);

    inline Climate getCageClimate() { return this->cageClimate; }
    inline void setCageClimate(Climate climate) { this->cageClimate = climate; }

    inline Period getCagePeriod() { return this->cagePeriod; }
    void setCagePeriod();
};


#endif //MITKO_CAGE_H
