#ifndef MITKO_MENU_H
#define MITKO_MENU_H

#include "Zoo.h"
#include "UI.h"

class Menu
{
private:
    UI zooUI;
    Zoo zoo;
public:
    Menu() = default;

    void logic();
};

#endif //MITKO_MENU_H
