<<<<<<< HEAD
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdio>
=======
#pragma once

#include <iostream>
#include <string>
>>>>>>> 7b9f7abdb1ff73840d29d8dd7f566e3bc7078d45

class ScalarConverter {
public:
    ScalarConverter();
<<<<<<< HEAD
    ~ScalarConverter();

    static void convert(std::string str);

};

#endif
=======
    ScalarConverter(std::string, int);
    ~ScalarConverter();

    // Copy constructor
    ScalarConverter(const ScalarConverter &obj);
    // Operator overload
    ScalarConverter &operator=(const ScalarConverter &obj);
    void set_grade(int);
    std::string getName() const;
    int getGrade() const;
    void increment();
    void decrement();

private:
    static const int max_grade = 1;
    static const int min_grade = 150;
    const std::string _name;
    int _grade;
};

std::ostream	&operator<<(std::ostream &out, const ScalarConverter &obj);
>>>>>>> 7b9f7abdb1ff73840d29d8dd7f566e3bc7078d45
