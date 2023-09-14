#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "ClapTrap default Constructor called" << std::endl;
    this->name = "Clappy";
    this->health = 10;
    this->energy = 10;
    this->attack_dmg = 0;
}

ClapTrap::ClapTrap(std::string n){
    std::cout << "ClapTrap Constructor called" << std::endl;
    this->name = n;
    this->health = 10;
    this->energy = 10;
    this->attack_dmg = 0;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

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
    //std::cout << "Health is now : " << health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energy && health > 0){
        std::cout << "ClapTrap " << name << " repaired itself for " << amount << " points of health!" << std::endl;
        health += amount;
        energy--;
        // std::cout << "Health is now : " << health << std::endl;
    }
    else
        std::cout << "Not enough energy or health to perform the action" << std::endl;
}
