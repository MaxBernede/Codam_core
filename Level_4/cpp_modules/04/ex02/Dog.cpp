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
    delete brain;
    brain = new Brain(*obj.brain);
    return *this;
}

//this line automatically gives the new dog a new brain based on the previous dog one
Dog::Dog(const Dog &obj) : Animal(obj), brain(new Brain(*obj.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = obj;
}

Brain *Dog::get_brain() const{
    return brain;
}

void Dog::makeSound() const{
    std::cout << type << " goes : Woof Woof!" << std::endl;
}