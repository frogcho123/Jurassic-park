#include "Menu.h"

bool isItAGoodCage(Cage cage, Dino dino)
{
    if (!cage.getDinosInCage().empty())
    {
        return cage.getDinosInCage().at(0) == dino;
    }
    else
    {
        if (dino.getDinoClass() == flying && cage.getCageClimate() == air)
        {
            return true;
        }
        if (dino.getDinoClass() == aquatic && cage.getCageClimate() == water)
        {
            return true;
        }
        if (dino.getDinoClass() == carnivorous && cage.getCageClimate() == land)
        {
            return true;
        }
        return dino.getDinoClass() == herbivorous && cage.getCageClimate() == land;
    }

}
Dino createADino()
{
    std::string name;
    std::cout << "Enter a name: ";
    std::cin >> name;

    bool gender;
    std::cout << "Enter a gender (0/1): ";
    std::cin >> gender;

    int period;
    std::cout << "Enter a period (0..2) -> Trias, Kreda, Jura : ";
    std::cin >> period;

    int dinoClass;
    std::cout << "Enter a class (0..3) -> herbivorous, carnivorous, flying, aquatic: ";
    std::cin >> dinoClass;

    std::string dinoType;
    std::cout << "Enter a type: ";
    std::cin >> dinoType;

    return Dino(name, gender, (Period)period, (Class)dinoClass, dinoType);
}
Cage createACage()
{
    int size;
    std::cout << "Enter a size: ";
    std::cin >> size;

    int climate;
    std::cout << "Enter a climate (0..2) -> land, air, water: ";
    std::cin >> climate;

    return Cage(size, (Climate)climate);
}

void Menu::logic()
{
    bool close = false;
    do
    {
        zooUI.printMenu();
        switch (zooUI.getOption())
        {
        case 1:
        {
            bool done = false;
            Dino newDino = createADino();
            for (unsigned int index = 0; index < this->zoo.getCages().size(); index++)
            {
                if (isItAGoodCage(this->zoo.getCages().at(index), newDino))
                {
                    done = this->zoo.getCages().at(index).addDino(newDino);
                    if (!done)
                    {
                        std::cout << "You can't add a new Dino at the moment, please add a new Cage!\n";
                    }
                    else
                    {
                        std::cout << "A Dino with name " + newDino.getName() << " is created!\n";
                        break;
                    }
                }
            }
            break;
        }
        case 2:
        {
            Cage newCage = createACage();
            zoo.addCage(newCage);
            std::cout << "You added a new cage!\n";
            break;
        }
        case 3:
        {
            bool done = false;

            std::string lfDinoName;
            std::cin >> lfDinoName;

            for (auto cage : zoo.getCages())
            {
                if (cage.deleteDino(lfDinoName))
                {
                    done = true;
                    std::cout << "You released a Dino with name " + lfDinoName + "!\n";
                    break;
                }
            }
            if (!done)
            {
                std::cout << "There isn't a Dino in this Zoo with the name " + lfDinoName << "!\n";
            }
            break;
        }
        case 4:
        {
            zoo.loadFood();
            std::cout << "You loaded the food storage!\n";
            break;
        }
        case 5:
        {
            std::cout << "Have a nice day!\n";
            close = true;
            break;
        }
        }
    } while (!close);
}
