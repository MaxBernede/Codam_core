#include "Brain.hpp"

// Constructors and Destructor
Brain::Brain() {
    std::cout << "Brain default Constructor called" << std::endl;
    this->name = "Brain";
    for (int i = 0; i < 100; i++) {
        ideas[i] = "";
    }
}

Brain::Brain(std::string n) {
    std::cout << "Brain Constructor called" << std::endl;
    this->name = n;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "";
    }
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

void Brain::set_idea(std::string n){
    for (int i = 0; i < 100; ++i){
        if (ideas[i].empty()){
            ideas[i] = n;
            return;
        }
    }
}

void Brain::get_ideas(void){
    for (int i = 0; i < 100; ++i){
        if (ideas[i].empty())
            return;
        std::cout << ideas[i] << std::endl;
    }
}