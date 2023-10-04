#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(std::string);
    ~Bureaucrat();

    // Copy constructor
    Bureaucrat(const Bureaucrat &obj);
    // Operator overload
    Bureaucrat &operator=(const Bureaucrat &obj);

private:
    const std::string name;
    int grade;
};

#endif
