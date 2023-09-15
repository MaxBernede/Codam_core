#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string n) : FragTrap(), ScavTrap(){
    std::cout << "DiamondTrap Constructor called" << std::endl;
    this->name = n;
    this->health = FragTrap::health;
    this->energy = ScavTrap::energy;
    this->attack_dmg = FragTrap::attack_dmg;
    std::cout << this->name << " " << health << "health " << energy << "energy " << attack_dmg << "attack"<< std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void){
    std::cout << "Who Am i :\nDiam_name : " << this->name << "\nClap_name : " << ClapTrap::name << std::endl;
}
