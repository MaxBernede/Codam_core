#include "Animal.hpp"

// Constructors and Destructor
Animal::Animal() {
    std::cout << "Animal default Constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(std::string n) {
    std::cout << "Animal Constructor called" << std::endl;
    type = n;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

// Canonical form
Animal &Animal::operator=(const Animal &obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

Animal::Animal(const Animal &obj) {
    *this = obj;
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << type << " goes : Animal noise" << std::endl;
}