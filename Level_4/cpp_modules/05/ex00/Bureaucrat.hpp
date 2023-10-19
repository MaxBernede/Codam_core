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
    void set_grade(int);
    std::string getName() const;
    int getGrade() const;
    void increment();
    void decrement();

    class GradeTooHighException : public std::exception {
    public:
        std::string exception();
    };
    class GradeTooLowException : public std::exception {
    public:
        std::string exception();
    };
private:
    const std::string _name;
    int _grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
