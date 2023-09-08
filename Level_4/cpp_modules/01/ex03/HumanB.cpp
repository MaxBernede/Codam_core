#include "HumanB.hpp"

void    HumanB::attack(void)
{
    if (!weapon)
        std::cout << name << " start a fist fight " << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string str)
{
    this->name = str;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << name << " Destroyed " << std::endl;
}

void    HumanB::setWeapon(Weapon &w)
{
    weapon = &w;
}