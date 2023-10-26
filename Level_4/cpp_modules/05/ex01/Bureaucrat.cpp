#include "Bureaucrat.hpp"

//Exceptions on grade too high or low
const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low Exception" ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high Exception" ;
}

// Constructors and Destructor
Bureaucrat::Bureaucrat() : _name("Bureaucrat"){
    std::cout << "Bureaucrat default Constructor called" << std::endl;
    _grade = min_grade;
}

Bureaucrat::Bureaucrat(std::string n, int i) : _name(n) {
    _grade = min_grade;
    std::cout << "Bureaucrat Constructor called" << std::endl;
    set_grade(i);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

// Canonical form
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this == &obj)
        return *this;
    // this->_name = obj.getName();
    // this->_grade = obj.getGrade();
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    *this = obj;
}

std::string Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

void Bureaucrat::increment(){
    set_grade(_grade - 1);
}
void Bureaucrat::decrement(){
    set_grade(_grade + 1);
}

// functions
void Bureaucrat::set_grade(int i){
    try{
        if (i < this->max_grade)
            throw GradeTooHighException();
        if (i > this->min_grade)
            throw GradeTooLowException();
        this->_grade = i;
    }
    catch (const std::exception& ex) {
        std::cerr << "Caught an exception :" << ex.what() << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj){
    return (out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".");
}