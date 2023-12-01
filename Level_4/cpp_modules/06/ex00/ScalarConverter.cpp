#include "ScalarConverter.hpp"

//!CONSTRUCTORS AND DESTRUCTORS
ScalarConverter::ScalarConverter() : _name("ScalarConverter"){
    std::cout << "ScalarConverter default Constructor called" << std::endl;
    _grade = min_grade;
}

ScalarConverter::ScalarConverter(std::string n, int i) : _name(n) {
    _grade = min_grade;
    std::cout << "ScalarConverter Constructor called" << std::endl;
    set_grade(i);
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter Destructor called" << std::endl;
}

//!CANONICAL FORM
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
    if (this == &obj)
        return *this;
    this->_grade = obj.getGrade();
    return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
    *this = obj;
}

//!GETTERS AND SETTERS
std::string ScalarConverter::getName() const{
    return this->_name;
}

int ScalarConverter::getGrade() const{
    return this->_grade;
}

//!FUNCTIONS
void ScalarConverter::increment(){
    set_grade(_grade - 1);
}
void ScalarConverter::decrement(){
    set_grade(_grade + 1);
}

void ScalarConverter::set_grade(int i){
    this->_grade = i;
}

//!OVERLOAD OPERATOR
std::ostream	&operator<<(std::ostream &out, const ScalarConverter &obj){
    return (out << obj.getName() << ", ScalarConverter grade " << obj.getGrade() << ".");
}