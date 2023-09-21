#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(std::string);
    virtual ~WrongAnimal();

    // Copy constructor
    WrongAnimal(const WrongAnimal &obj);
    // Operator overload
    WrongAnimal &operator=(const WrongAnimal &obj);

    void makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};

#endif
