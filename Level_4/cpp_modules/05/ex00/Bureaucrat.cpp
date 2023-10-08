#include "Bureaucrat.hpp"

//Exceptions on grade too high or low
std::string Bureaucrat::GradeTooLowException::exception(){
    return "Grade too low Exception" ;
}

std::string Bureaucrat::GradeTooHighException::exception(){
    return "Grade too high Exception" ;
}

// Constructors and Destructor
Bureaucrat::Bureaucrat() : _name("Bureaucrat"){
    std::cout << "Bureaucrat default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n) : _name(n) {
    std::cout << "Bureaucrat Constructor called" << std::endl;
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

std::string Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

void Bureaucrat::increment(){
    --_grade;
}
void Bureaucrat::decrement(){
    try{
        ++_grade;
    }
    // catch
}

// functions
void Bureaucrat::set_grade(int i){
    try{
        if (i < 1)
            throw GradeTooLowException();
        if (i > 150)
            throw GradeTooHighException();
    this->_grade = i;
    }
    catch (const std::exception& ex) {
        std::cerr << "Caught an exception :" << ex.what() << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj){
    return (out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".");
}