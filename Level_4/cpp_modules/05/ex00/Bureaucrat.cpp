#include "Bureaucrat.hpp"

// Constructors and Destructor
Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat default Constructor called" << std::endl;
    this->name = "Bureaucrat";
}

Bureaucrat::Bureaucrat(std::string n) {
    std::cout << "Bureaucrat Constructor called" << std::endl;
    this->name = n;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

// Canonical form
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    //copy depending on vars;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    *this = obj;
}
