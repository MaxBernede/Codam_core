#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap Constructor called" << std::endl;
    this->name = "Fraggy";
    this->health = 100;
    this->energy = 100;
    this->attack_dmg = 30;
}

FragTrap::FragTrap(std::string n){
    std::cout << "FragTrap Constructor called" << std::endl;
    this->name = n;
    this->health = 100;
    this->energy = 100;
    this->attack_dmg = 30;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << name << " shouts : High Fives Guys !!" << std::endl;
}