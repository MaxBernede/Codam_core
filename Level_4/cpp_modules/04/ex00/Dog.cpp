#include "Dog.hpp"

// Constructors and Destructor
Dog::Dog() {
    std::cout << "Dog default Constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(std::string n) {
    std::cout << "Dog Constructor called" << std::endl;
    this->type = n;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

// Canonical form
Dog &Dog::operator=(const Dog &obj) {
    this->type = obj.type;
    return *this;
}

Dog::Dog(const Dog &obj) {
    *this = obj;
}

void Dog::makeSound() const{
    std::cout << type << " goes : Woof Woof!" << std::endl;
}