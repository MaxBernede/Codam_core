#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() {
    std::cout << "Fixed default Constructor called" << std::endl;
    _number = 0;
}

Fixed::Fixed(const int n){
    std::cout << "Fixed Constructor called" << std::endl;
    this->_number = n << this->_fractional_bits;
}

Fixed::Fixed(const float f){
    std::cout << "Fixed Constructor called" << std::endl;
    this->_number =  roundf(f * (1 << this->_fractional_bits));
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

float Fixed::toFloat( void ) const{

}

int Fixed::toInt( void ) const{

}