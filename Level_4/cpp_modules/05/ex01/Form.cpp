#include "Form.hpp"

//!EXCEPTIONS
const char *Form::GradeTooLowException::what() const throw(){
    return "Grade too low Exception" ;
}
const char *Form::GradeTooHighException::what() const throw(){
    return "Grade too high Exception" ;
}

//!CONSTRUCTORS AND DESTRUCTORS
Form::Form() : name("Form"), is_signed(false), grade_required(min_grade), grade_execute(min_grade){
    std::cout << "Form default Constructor called" << std::endl;
}

Form::Form(std::string n, int req, int exe) : name(n), is_signed(false), grade_required(req), grade_execute(exe){
    std::cout << "Form Constructor called" << std::endl;
    if (req < max_grade || exe < max_grade)
        throw GradeTooHighException();
    if (req > min_grade || exe > min_grade)
        throw GradeTooLowException();
}

Form::~Form() {
    std::cout << "Form Destructor called" << std::endl;
}

//!CANONICAL FORM
Form &Form::operator=(const Form &obj)
{
    if (this == &obj)
        return *this;
    is_signed = obj.getIsSigned();
    return *this;
}

Form::Form(const Form &obj) :name(obj.name), is_signed(obj.is_signed), grade_required(obj.getGradeRequired()), grade_execute(obj.getGradeExecute()){
    *this = obj;
}


//!GETTERS AND SETTERS
const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return is_signed;
}

int Form::getGradeRequired() const {
    return grade_required;
}

int Form::getGradeExecute() const {
    return grade_execute;
}

//!FUNCTIONS
void Form::beSigned(Bureaucrat &B) {
    if (B.getGrade() > grade_required){
        std::cout << "Form not signed : " << std::endl;
        throw GradeTooLowException();
    }
    is_signed = true;
}

//!OVERLOAD OPERATOR
std::ostream	&operator<<(std::ostream &out, const Form &obj){
    return (out << obj.getName() << ", form is signed : " << obj.getIsSigned() << ", exe : " << obj.getGradeExecute() << ", required : " << obj.getGradeRequired() << ".");
}