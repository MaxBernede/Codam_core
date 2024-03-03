#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

enum Type { CHAR, INT, FLOAT, DOUBLE, ERROR};

class ScalarConverter {
public:
    static void convert(const std::string& str);
};

#endif
