#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
public:
    Dog();
    Dog(std::string);
    ~Dog();

    // Copy constructor
    Dog(const Dog &obj);
    // Operator overload
    Dog &operator=(const Dog &obj);

    void makeSound() const;
};

#endif
