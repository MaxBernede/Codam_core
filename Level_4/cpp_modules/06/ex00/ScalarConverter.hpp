#pragma once

#include <iostream>
#include <string>

class ScalarConverter {
public:
    ScalarConverter();
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
