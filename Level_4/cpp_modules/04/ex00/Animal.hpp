#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(std::string);
    ~Animal();

    // Copy constructor
    Animal(const Animal &obj);
    // Operator overload
    Animal &operator=(const Animal &obj);

    const void makeSound();
    const std::string& getType();

protected:
    std::string type;
};

#endif
