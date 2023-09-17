#include "Dog.hpp"

// Constructors and Destructor
Dog::Dog() : Animal("Dog"), brain(new Brain()){
    std::cout << "Dog default Constructor called" << std::endl;
}

Dog::Dog(std::string n) : Animal(n), brain(new Brain()) {
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
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