#include "ScalarConverter.hpp"

// Constructors and Destructor
ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter Destructor called" << std::endl;
}

bool isFloat(const std::string& s) {
    try {
        std::stof(s);
        return true;
    } catch (...) {
        return false;
    }
}

// Member functions
void ScalarConverter::convert(std::string str){
    std::cout << "ScalarConverter convert called with " << str << std::endl;
    if (str.length() == 1 && !isdigit(str[0]))
        std::cout << "char: " << str[0] << std::endl;
    else
        std::cout << "int: " << std::stoi(str) << std::endl;

    if (isFloat(str))
        std::cout << ": " << std::stod(str) << std::endl;
    
}