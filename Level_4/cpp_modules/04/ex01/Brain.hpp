#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
    Brain();
    Brain(std::string);
    ~Brain();

    // Copy constructor
    Brain(const Brain &obj);
    // Operator overload
    Brain &operator=(const Brain &obj);

private:
    std::string name;
    std::string ideas[100];
};

#endif
