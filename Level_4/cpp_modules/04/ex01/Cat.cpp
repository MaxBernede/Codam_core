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
    std::cout << type << " Operator = Called" << std::endl;
    this->type = obj.type;
    delete brain;
    brain = new Brain(*obj.brain);
    return *this;
}

//this line automatically gives the new Cat a new brain based on the previous Cat one
Cat::Cat(const Cat &obj) : Animal(obj), brain(new Brain(*obj.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = obj;
}

Brain *Cat::get_brain() const{
    return brain;
}

void Cat::makeSound() const{
    std::cout << type << " goes : Woof Woof!" << std::endl;
}