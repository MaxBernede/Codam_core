#include "Cat.hpp"

// Constructors and Destructor
Cat::Cat() {
    std::cout << "Cat default Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(std::string n) {
    std::cout << "Cat Constructor called" << std::endl;
    this->type = n;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
}

// Canonical form
Cat &Cat::operator=(const Cat &obj) {
    //copy depending on vars;
    return *this;
}

Cat::Cat(const Cat &obj) {
    *this = obj;
}
