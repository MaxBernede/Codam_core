#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(std::string);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
    virtual void exe() const;
private:
    std::string target;
};

#endif
