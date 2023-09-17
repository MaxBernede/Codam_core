#include "Brain.hpp"

// Constructors and Destructor
Brain::Brain() {
    std::cout << "Brain default Constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "";
    }
}

Brain::Brain(std::string n) {
    std::cout << "Brain Constructor called" << n << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "";
    }
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

// Canonical form
Brain &Brain::operator=(const Brain &obj) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = obj.ideas[i];
    }
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