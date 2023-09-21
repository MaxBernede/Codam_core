#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() {
    std::cout << "Fixed default Constructor called" << std::endl;
    _number = 0;
}

Fixed::Fixed(int n) : _number(n) {
    std::cout << "Fixed Constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Fixed Destructor called" << std::endl;
}

// Canonical form
Fixed &Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy assignment operator called " << std::endl;
    this->_number = obj._number;
    return *this;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_number);
}

void  Fixed::setRawBits(int const raw){
    _number = raw;
}
