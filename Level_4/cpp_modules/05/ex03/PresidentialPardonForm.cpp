#include "PresidentialPardonForm.hpp"

//!CONSTRUCTORS AND DESTRUCTORS
PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("PresidentialPardonForm", 25, 5), target(t) {
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

//!CANONICAL FORM
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    target = obj.target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {
    *this = obj;
}

//!FUNCTIONS
void PresidentialPardonForm::exe() const{
    std::cout << target << " have been pardonned by Zaphod Beeblebrox" << std::endl;
}