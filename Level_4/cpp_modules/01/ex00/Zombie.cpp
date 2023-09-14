#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Constructor Called" << std::endl;
	name = "Zombie";
}

Zombie::Zombie(std::string n){
	std::cout << "Constructor Called" << std::endl;
	name = n;
}

Zombie::~Zombie(){
	std::cout << "Destructor Called on : " << name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
