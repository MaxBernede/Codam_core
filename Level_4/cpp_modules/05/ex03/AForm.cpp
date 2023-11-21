#include "AForm.hpp"

//!EXCEPTIONS
const char *AForm::GradeTooLowException::what() const throw(){
    return "Grade too low Exception" ;
}
const char *AForm::GradeTooHighException::what() const throw(){
    return "Grade too high Exception" ;
}

//!CONSTRUCTORS AND DESTRUCTORS
AForm::AForm() : name("AForm"), is_signed(false), grade_required(min_grade), grade_execute(min_grade){
    std::cout << "AForm default Constructor called" << std::endl;
}

AForm::AForm(std::string n, int req, int exe) : name(n), is_signed(false), grade_required(req), grade_execute(exe){
    std::cout << "AForm Constructor called" << std::endl;
    if (req < max_grade || exe < max_grade)
        throw GradeTooHighException();
    if (req > min_grade || exe > min_grade)
        throw GradeTooLowException();
}

AForm::~AForm() {
    std::cout << "AForm Destructor called" << std::endl;
}

//!CANONICAL AFORM
AForm &AForm::operator=(const AForm &obj)
{
    if (this == &obj)
        return *this;
    is_signed = obj.getIsSigned();
    return *this;
}

AForm::AForm(const AForm &obj) :name(obj.name), is_signed(obj.is_signed), grade_required(obj.getGradeRequired()), grade_execute(obj.getGradeExecute()){
    *this = obj;
}


//!GETTERS AND SETTERS
const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return is_signed;
}

int AForm::getGradeRequired() const {
    return grade_required;
}

int AForm::getGradeExecute() const {
    return grade_execute;
}

//!FUNCTIONS
void AForm::beSigned(Bureaucrat &B){
    if (B.getGrade() > grade_required){
        std::cout << name << " not signed : " << std::endl;
        throw GradeTooLowException();
    }
    is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > this->getGradeExecute()){
        std::cout << name << " not executed : " << std::endl;
        throw GradeTooLowException();
    }
    if (is_signed){
        std::cout << executor.getName() << " executed " << name << std::endl;
        exe();
    }
    else
        std::cout << name << " not executed because is not signed" << std::endl;
}

//!OVERLOAD OPERATOR
std::ostream	&operator<<(std::ostream &out, const AForm &obj){
    return (out << obj.getName() << ", Aform is signed : " << obj.getIsSigned() << ", exe : " << obj.getGradeExecute() << ", required : " << obj.getGradeRequired() << ".");
}