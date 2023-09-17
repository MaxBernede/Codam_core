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
    std::cout << type << " Operator = Called" << std::endl;
    this->type = obj.type;
    delete this->brain;
    brain = new Brain(*(obj.brain));
    return *this;
}

Dog::Dog(const Dog &obj) {
    *this = obj;
}

Brain *Dog::get_brain() const{
    return brain;
}

void Dog::makeSound() const{
    std::cout << type << " goes : Woof Woof!" << std::endl;
}