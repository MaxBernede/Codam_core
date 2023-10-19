#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() {
    std::cout << "Default Constructor called" << std::endl;
    _raw = 0;
}

Fixed::Fixed(const int n){
    std::cout << "Int Constructor called" << std::endl;
    this->_raw = n << this->_fractional_bits;
}

Fixed::Fixed(const float f){
    std::cout << "Float Constructor called" << std::endl;
    this->_raw =  roundf(f * (1 << this->_fractional_bits));
}

Fixed::~Fixed() {
    std::cout << "Fixed Destructor called" << std::endl;
}

// Canonical form
Fixed &Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy assignment operator called " << std::endl;
    this->_raw = obj._raw;
    return *this;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_raw);
}

void  Fixed::setRawBits(int const raw){
    _raw = raw;
}

float Fixed::toFloat( void ) const{
    return (((float)_raw) / (1 << this->_fractional_bits));
}

int Fixed::toInt( void ) const{
    return (_raw >> this->_fractional_bits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &obj){
    return (out << obj.toFloat());
}