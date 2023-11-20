#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern Destructor called" << std::endl;
}

//!CANONICAL Intern
Intern &Intern::operator=(const Intern &obj)
{
    if (this == &obj)
        return *this;
    return *this;
}

Intern::Intern(const Intern &obj){
    *this = obj;
}

AForm *Intern::makeForm(std::string n, std::string target){
    const char *names[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    int found = -1;
    for (int i = 0; i < 3; i++){
        if (n == names[i]){
            found = i;
            break;
        }
    }
    if (found == -1){
        std::cout << "Error in the creation of the form." << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << n << std::endl;
    switch (found){
        case 0:
            return new RobotomyRequestForm(target);
        case 1:
            return new ShrubberyCreationForm(target);
        case 2:
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Error in the creation of the form." << std::endl;
            return NULL;
    }
}
