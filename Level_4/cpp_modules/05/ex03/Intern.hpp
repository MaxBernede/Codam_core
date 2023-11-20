#ifndef INTERN_HPP
#define INTERN_HPP

    #include <iostream>
    #include <string>
    #include "Bureaucrat.hpp"
    #include "AForm.hpp"
    #include "ShrubberyCreationForm.hpp"
    #include "RobotomyRequestForm.hpp"
    #include "PresidentialPardonForm.hpp"

    class Bureaucrat;

    class Intern {
    public:
        Intern();
        ~Intern();

        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        AForm *makeForm(std::string n, std::string target);
    };

#endif
