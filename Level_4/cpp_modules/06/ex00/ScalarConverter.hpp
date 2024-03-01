#pragma once

#include <iostream>
#include <string>

enum Type { CHAR, INT, FLOAT, DOUBLE, ERROR};

class ScalarConverter {
public:
    ScalarConverter();
    ~ScalarConverter();

    static void convert(std::string str);
    virtual void not_a_class() = 0;
};

