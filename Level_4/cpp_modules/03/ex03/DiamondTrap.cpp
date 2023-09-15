#include "DiamondTrap.hpp"

//Creators and Destructors
DiamondTrap::DiamondTrap(const std::string &n) : ClapTrap(n), FragTrap(n), ScavTrap(n){
    std::cout << "DiamondTrap Constructor called" << std::endl;
	this->name = n;
	FragTrap::ClapTrap::name = n + "_clap_name";
    this->health = FragTrap::health;
    this->energy = ScavTrap::energy;
    this->attack_dmg = FragTrap::attack_dmg;
    std::cout << this->name << " " << health << "health " << energy << "energy " << attack_dmg << "attack"<< std::endl;
    std::cout << this->name << " " << FragTrap::name << " " << ScavTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << name << " Destructor called" << std::endl;
}


//Canonical form
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj){
    this->name = obj.name;
    this->health = obj.health;
    this->energy = obj.energy;
    this->attack_dmg = obj.attack_dmg;
    return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj){
	*this = obj;
}


//Functions
void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void){
    std::cout << "Who Am i :\nDiam_name : " << this->name << "\nClap_name : " << ClapTrap::name << std::endl;
}
