#include "ScalarConverter.hpp"

//!So we can't instantiate it (private)
ScalarConverter::ScalarConverter(){
    ;
}

//! PRINTS
static void print_char(char ch)
{
    std::cout << "char: '" << ch << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(ch) << std::endl;
    std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

static void print_int(int i)
{
    if (isprint((unsigned char)i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: '" << "Non displayable" << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void print_float(float f)
{
    if (isprint(f))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: '" << "Non displayable" << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void print_double(double d)
{
    if ((d <= 2147483647 && d >= -2147483648) && isprint(d))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: '" << "Non displayable" << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << std::endl;
    std::cout << "double: " << d << std::endl;
}

static void print_error(void)
{
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;
}

//! IS 

static bool has_digit(const std::string& str) {
    for(char c : str) {
        if(std::isdigit(c))
            return true;
    }
    return false;
}

static bool is_float(const std::string& str) {
    if (str.empty() || (str.size() == 1 && (str[0] == '+' || str[0] == '-'))) {
        return false;
    }
    if (!has_digit(str))
        return false;
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

static bool is_double(const std::string& str) {
    if (str.empty() || (str.size() == 1 && (str[0] == '+' || str[0] == '-'))) {
        return false;
    }
    if (!has_digit(str))
        return false;
    try {
        std::stod(str);
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

static bool is_int(const std::string& str) {
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

static bool is_char(const std::string& str){
    if (str.size() != 1)
        return false;
    if (isdigit(str[0]) || !isprint(str[0]))
        return false;
    return true;
        
}

static Type get_type(const std::string& str){
    if (is_char(str))
        return CHAR;
    if (is_int(str))
        return INT;
    if (is_float(str) && str[str.size()-1] == 'f')
        return FLOAT;
    if (is_double(str))
        return DOUBLE;
    return ERROR;
    
}

void ScalarConverter::convert(const std::string& str){
    switch (get_type(str))
    {
        case CHAR:
            print_char(str[0]);
            break;
        case INT:
            print_int(stoi(str));
            break;
        case FLOAT:
            print_float(stof(str));
            break;
        case DOUBLE:
            print_double(stod(str));
            break;
        case ERROR:
            print_error();
            break;
    }
    std::cout << std::endl;
}