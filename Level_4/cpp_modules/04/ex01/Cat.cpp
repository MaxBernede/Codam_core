#include "Cat.hpp"

// Constructors and Destructor
Cat::Cat() : Animal("Cat"), brain(new Brain()){
    std::cout << "Cat default Constructor called" << std::endl;
}

Cat::Cat(std::string n) : Animal(n), brain(new Brain()) {
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
}

// Canonical form
Cat &Cat::operator=(const Cat &obj) {
    this->type = obj.type;
    return *this;
}

Cat::Cat(const Cat &obj) {
    *this = obj;
}

void Cat::makeSound() const{
    std::cout << type << " goes : Meow!" << std::endl;
}
