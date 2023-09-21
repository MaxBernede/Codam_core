#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
    Brain();
    Brain(std::string);
    virtual ~Brain();

    // Copy constructor
    Brain(const Brain &obj);
    // Operator overload
    Brain &operator=(const Brain &obj);
    void    set_idea(std::string);
    void    get_ideas(void);

private:
    std::string ideas[100];
};

#endif
