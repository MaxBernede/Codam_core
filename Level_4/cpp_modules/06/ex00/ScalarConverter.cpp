#include "ScalarConverter.hpp"

// Constructors and Destructor
ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter Destructor called" << std::endl;
}

bool isFloat(const std::string& str) {
    if (str.empty() || (str.size() == 1 && (str[0] == '+' || str[0] == '-'))) {
        return false;
    }
    bool decimal = false;

    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];

        if (c == '+' || c == '-') {
            if (i != 0)
                return false;
        }
        else if (c == '.'){
            if (decimal)
                return false;
            decimal = true;
        }
        else if (!std::isdigit(c) && (i != (str.size()-1) && c == 'f'))
            return false;
    }
    try {
        std::stof(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
    if (std::isdigit(str[0]) || (str.size() > 1 && std::isdigit(str[1])))
        return true;
    return false;
}

bool isInteger(const std::string& str) {
    try {
        for (size_t i = 0; i < str.size(); i++){
            if (i == 0 && (str[i] == '+' || str[i] == '-'))
                i++;
            if (!std::isdigit(str[i]))
                return false;
        }
        std::stoi(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
}

Type find_type(std::string str){
    if (str.size() == 1 && !isdigit(str[0]))
        return CHAR;
    else if (isInteger(str))
        return INT;
    if (isFloat(str) && str[str.size()-1] == 'f')
        return FLOAT;
    else if (isFloat(str))
        return DOUBLE;
    return ERROR;
}

std::string print_type(Type type){
    std::string array[] = {"char", "int", "float", "double"};
    return array[type];
}

// Member functions
void ScalarConverter::convert(std::string str){
    std::cout << "ScalarConverter convert called with " << str << std::endl;
    Type type = find_type(str);
    if (type == ERROR){
        std::cout << "Arg is none of the correct ones, Error" << std::endl;
        return ;
    }
    std::cout << "type is : " << print_type(type) << std::endl;
    if (isFloat(str))
        std::cout << ": " << std::stod(str) << std::endl;
    
}

void ScalarConverter::not_a_class(){
    ;
}