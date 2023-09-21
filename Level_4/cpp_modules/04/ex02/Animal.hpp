#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(std::string);
    //virtual destructor because in the main it's kept as Animal while dog is derived
    virtual ~Animal();

    // Copy constructor
    Animal(const Animal &obj);
    // Operator overload
    virtual Animal &operator=(const Animal &obj);

    virtual void makeSound() const = 0;
    std::string getType() const;

protected:
    std::string type;
};

#endif
