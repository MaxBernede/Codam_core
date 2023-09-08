#include "Weapon.hpp"

Weapon::Weapon(std::string str){
	type = str;
}

Weapon::Weapon(){
	type = "bare hands";
}

Weapon::~Weapon(){
	std::cout << "Destructor of Weapon\n";
}

std::string &Weapon::getType(void)
{
    return type;
}

void    Weapon::setType(std::string str)
{
    type = str;
}