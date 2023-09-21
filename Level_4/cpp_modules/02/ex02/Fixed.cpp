#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    fixpoint_nb = 0;
}

Fixed::Fixed(int n){
    std::cout << "Copy constructor called" << std::endl;
    fixpoint_nb = n;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return 0;
}

void Fixed::setRawBits(int const raw){
    fixpoint_nb = raw;
}