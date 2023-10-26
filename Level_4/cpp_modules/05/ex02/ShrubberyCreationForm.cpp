#include "ShrubberyCreationForm.hpp"

//!CONSTRUCTORS AND DESTRUCTORS
ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 145, 137), target(t) {
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

//!CANONICAL FORM
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    target = obj.target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) {
    *this = obj;
}

//!FUNCTIONS
void ShrubberyCreationForm::exe() {
    std::cout << "TREE" << std::endl;
}