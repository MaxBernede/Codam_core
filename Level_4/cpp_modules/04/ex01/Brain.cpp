#include "Brain.hpp"

// Constructors and Destructor
Brain::Brain() {
    std::cout << "Brain default Constructor called" << std::endl;
    this->name = "Brain";
}

Brain::Brain(std::string n) {
    std::cout << "Brain Constructor called" << std::endl;
    this->name = n;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

// Canonical form
Brain &Brain::operator=(const Brain &obj) {
    this->name = obj.name;
    return *this;
}

Brain::Brain(const Brain &obj) {
    *this = obj;
}
