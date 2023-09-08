#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << name << " Destroyed " << std::endl;
}

HumanA::HumanA(std::string str, Weapon &w)
{
    name = str;
    weapon = &w;
}