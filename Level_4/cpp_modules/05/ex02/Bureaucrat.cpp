#include "Bureaucrat.hpp"

//!EXCEPTIONS
const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low Exception" ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high Exception" ;
}

//!CONSTRUCTORS AND DESTRUCTORS
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

//!CANONICAL FORM
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this == &obj)
        return *this;
    this->_grade = obj.getGrade();
    if (_grade < max_grade)
        throw GradeTooHighException();
    if (_grade > min_grade)
        throw GradeTooLowException();
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    *this = obj;
}

//!GETTERS AND SETTERS
std::string Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

//!FUNCTIONS
void Bureaucrat::increment(){
    set_grade(_grade - 1);
}
void Bureaucrat::decrement(){
    set_grade(_grade + 1);
}

void Bureaucrat::set_grade(int i){
    if (i < this->max_grade)
        throw GradeTooHighException();
    if (i > this->min_grade)
        throw GradeTooLowException();
    this->_grade = i;
}

void Bureaucrat::signForm(AForm &form){
	try{
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e){
        std::cout << _name << " couldn't sign " << form.getName() << " because "<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form){
    try{
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout << "Error: Form was not executed" << std::endl;
    }
}

//!OVERLOAD OPERATOR
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj){
    return (out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".");
}