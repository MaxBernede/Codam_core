#include "ClapTrap.hpp"

//Creators and Destructors
ClapTrap::ClapTrap(){
    this->name = "Clappy";
    this->health = 10;
    this->energy = 10;
    this->attack_dmg = 0;
    me() << "default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &n){
    this->name = n;
    this->health = 10;
    this->energy = 10;
    this->attack_dmg = 0;
    me() << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
    me() << "Destructor called" << std::endl;
}


//Canonical form
ClapTrap &ClapTrap::operator=(const ClapTrap &obj){
    this->name = obj.name;
    this->health = obj.health;
    this->energy = obj.energy;
    this->attack_dmg = obj.attack_dmg;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &obj){
	*this = obj;
}


//Utils
std::ostream &ClapTrap::me(){
    return std::cout << "ClapTrap " << name << " ";
}


//Functions 
void ClapTrap::attack(const std::string& target){
    if (energy && health > 0){
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_dmg << " points of damage!" << std::endl;
        energy--;
    }
    else
        std::cout << "Not enough energy or health to perform the action" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
    health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energy && health > 0){
        std::cout << "ClapTrap " << name << " repaired itself for " << amount << " points of health!" << std::endl;
        health += amount;
        energy--;
    }
    else
        std::cout << "Not enough energy or health to perform the action" << std::endl;
}