#include "Weapon.hpp"

Weapon::Weapon(std::string str){
	type = str;
}

Weapon::Weapon(){
	type = "bare hands";
}

Weapon::~Weapon(){
	std::cout << "Weapon destroyed : " << type << std::endl;
}

const std::string &Weapon::getType(void)
{
    return type;
}

void    Weapon::setType(std::string str)
{
    type = str;
}