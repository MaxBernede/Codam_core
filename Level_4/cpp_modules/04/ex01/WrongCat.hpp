#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
    WrongCat();
    WrongCat(std::string);
    ~WrongCat();

    // Copy constructor
    WrongCat(const WrongCat &obj);
    // Operator overload
    WrongCat &operator=(const WrongCat &obj);

    void makeSound() const;
};

#endif
