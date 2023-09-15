#include "ScavTrap.hpp"

//Creators and Destructors
ScavTrap::ScavTrap() : ClapTrap(){
    std::cout << "ScavTrap default Constructor called" << std::endl;
    this->name = "Scavy";
    this->health = 100;
    this->energy = 50;
    this->attack_dmg = 20;
    this->guard_mode = false;
}

ScavTrap::ScavTrap(const std::string &n) : ClapTrap(){
    std::cout << "ScavTrap Constructor called" << std::endl;
    this->name = n;
    this->health = 100;
    this->energy = 50;
    this->attack_dmg = 20;
    this->guard_mode = false;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}


//Canonical form
ScavTrap &ScavTrap::operator=(const ScavTrap &obj){
    this->name = obj.name;
    this->health = obj.health;
    this->energy = obj.energy;
    this->attack_dmg = obj.attack_dmg;
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &obj){
	*this = obj;
}


//Functions
void ScavTrap::attack(const std::string& target){
    if (energy && health > 0){
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_dmg << " points of damage!" << std::endl;
        energy--;
    }
    else
        std::cout << "Not enough energy or health to perform the action" << std::endl;

}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
    this->guard_mode = true;
}

