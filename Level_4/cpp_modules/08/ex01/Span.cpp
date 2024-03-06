#include "Span.hpp"

// Constructors and Destructor
Span::Span() : N(0), len(-1) {
    std::cout << "Span default Constructor called" << std::endl;
}

Span::Span(unsigned int n) : N(n), len(0) {
    std::cout << "Span Constructor called" << std::endl;
}

Span::~Span() {
    std::cout << "Span Destructor called" << std::endl;
}




// Canonical form
Span &Span::operator=(const Span &obj) {
    //copy depending on vars;
    if (&obj == this)
        return *this;
    return *this;
}

Span::Span(const Span &obj) {
    *this = obj;
}



//Member functions
void Span::addNumber(int i){
    try{
        if (len <= N)
            throw ("Exception too much args");
        this->array[len] = i;
        len++;
    }
    catch(std::exception e){
        throw ("Exception too much args");
    }
}

unsigned int Span::get_max(){
    return this->N;
}
