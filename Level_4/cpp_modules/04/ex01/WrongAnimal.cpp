#include "WrongAnimal.hpp"

// Constructors and Destructor
WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default Constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string n) {
    std::cout << "WrongAnimal Constructor called" << std::endl;
    type = n;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

// Canonical form
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    *this = obj;
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound() const{
    std::cout << type << " goes : WrongAnimal noise" << std::endl;
}