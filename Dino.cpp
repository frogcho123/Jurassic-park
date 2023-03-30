#include "Dino.h"

bool Dino::operator==(const Dino& otherDino)
{
    return (this->dinoPeriod == otherDino.dinoPeriod) && (this->dinoClass == otherDino.dinoClass);
}

void Dino::setFood()
{
    if (this->dinoClass == herbivorous)
    {
        this->dinoFood = Grass;
    }
    else if (this->dinoClass == aquatic)
    {
        this->dinoFood = Fish;
    }
    else
    {
        this->dinoFood = Meat;
    }
}

Dino::Dino(std::string _name, bool _gender, Period _dinoPeriod, Class _dinoClass, std::string _type)
{
    this->name = _name;
    this->gender = _gender;
    this->dinoPeriod = _dinoPeriod;
    this->dinoClass = _dinoClass;
    this->type = _type;

    this->setFood();
}
