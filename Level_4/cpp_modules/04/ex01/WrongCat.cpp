#include "WrongCat.hpp"

// Constructors and Destructor
WrongCat::WrongCat() {
    std::cout << "WrongCat default Constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(std::string n) {
    std::cout << "WrongCat Constructor called" << std::endl;
    this->type = n;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}

// Canonical form
WrongCat &WrongCat::operator=(const WrongCat &obj) {
    this->type = obj.type;
    return *this;
}

WrongCat::WrongCat(const WrongCat &obj) {
    *this = obj;
}

void WrongCat::makeSound() const{
    std::cout << type << " goes : I'm confused coz I'm wrong!" << std::endl;
}
