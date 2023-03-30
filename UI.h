#ifndef MITKO_UI_H
#define MITKO_UI_H

#include <iostream>
#include <string>

class UI
{
private:
    std::string menu;
    int option;
public:
    UI();

    inline void printMenu()
    {
        std::cout << this->menu;
        this->setOption();
    }

    inline int getOption() { return this->option; }
    inline void setOption() { std::cin >> this->option; }
};

#endif //MITKO_UI_H
