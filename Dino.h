#ifndef MITKO_DINO_H
#define MITKO_DINO_H

#include <string>

enum Class { herbivorous, carnivorous, flying, aquatic };
enum Period { Trias, Kreda, Jura, Empty };
enum Food { Grass, Meat, Fish };

class Dino
{
private:
    std::string name;
    bool gender;
    // 0 -> Male
    // 1 -> Female
    Period dinoPeriod;
    Class dinoClass;
    std::string type;
    Food dinoFood;

public:
    Dino() = default;
    Dino(std::string, bool, Period, Class, std::string);

    // Check if the Dinos can live together
    bool operator==(const Dino&);

    inline std::string getName() { return this->name; }
    inline void setName(const std::string& _name) { this->name = _name; }

    inline bool getGender() { return this->gender; }
    inline void setGender(const bool& _gender) { this->gender = _gender; }

    inline Period getDinoPeriod() { return this->dinoPeriod; }
    inline void setDinoPeriod(const Period& _dinoPeriod) { this->dinoPeriod = _dinoPeriod; }

    inline Class getDinoClass() { return this->dinoClass; }
    inline void setDinoClass(const Class& _dinoClass) { this->dinoClass = _dinoClass; }

    inline std::string getType() { return this->type; }
    inline void setType(const std::string& _type) { this->type = _type; }

    inline Food getFood() { return this->dinoFood; }
    inline void setFood();
};


#endif //MITKO_DINO_H
