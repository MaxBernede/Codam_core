#include "FragTrap.hpp"

//Creators and Destructors
FragTrap::FragTrap() : ClapTrap(){
    std::cout << "FragTrap default Constructor called" << std::endl;
    this->name = "Scavy";
    this->health = 100;
    this->energy = 50;
    this->attack_dmg = 20;
}

FragTrap::FragTrap(std::string n) : ClapTrap(){
    std::cout << "FragTrap Constructor called" << std::endl;
    this->name = n;
    this->health = 100;
    this->energy = 50;
    this->attack_dmg = 20;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}


//Canonical form
FragTrap &FragTrap::operator=(const FragTrap &obj){
    this->name = obj.name;
    this->health = obj.health;
    this->energy = obj.energy;
    this->attack_dmg = obj.attack_dmg;
    return *this;
}

FragTrap::FragTrap(const FragTrap &obj){
	*this = obj;
}


//Functions
void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << name << " shouts : High Fives Guys !!" << std::endl;
}