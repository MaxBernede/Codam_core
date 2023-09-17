#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
public:
    Cat();
    Cat(std::string);
    ~Cat();

    // Copy constructor
    Cat(const Cat &obj);
    // Operator overload
    Cat &operator=(const Cat &obj);

    void makeSound() const;
};

#endif
