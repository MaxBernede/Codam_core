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


int Fixed::getRawBits() const{
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

//Comparison operators
bool Fixed::operator>(const Fixed& obj) const{
    return _raw > obj.getRawBits();
}

bool Fixed::operator<(const Fixed& obj) const{
    return _raw < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed& obj) const{
    return _raw >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed& obj) const{
    return _raw <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed& obj) const{
    return _raw == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed& obj) const{
    return _raw != obj.getRawBits();
}

//Arithmetic operators
Fixed &Fixed::operator*(const Fixed& obj){
    this->_raw = roundf((this->toFloat() * obj.toFloat()) * (1 << this->_fractional_bits));
    return *this;
}

Fixed &Fixed::operator/(const Fixed& obj){
    this->_raw = roundf((this->toFloat() / obj.toFloat()) * (1 << this->_fractional_bits));
    return *this;
}

Fixed &Fixed::operator+(const Fixed& obj){
    this->_raw = roundf((this->toFloat() + obj.toFloat()) * (1 << this->_fractional_bits));
    return *this;
}

Fixed &Fixed::operator-(const Fixed& obj){
    this->_raw = roundf((this->toFloat() - obj.toFloat()) * (1 << this->_fractional_bits));
    return *this;
}

//Member functions
Fixed &Fixed::min(Fixed &obj1, Fixed &obj2){
    if (obj1.getRawBits() <= obj2.getRawBits())
        return (obj1);
    return (obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2){
    if (obj1.getRawBits() >= obj2.getRawBits())
        return (obj1);
    return (obj2);
}

Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2){
    if (obj1.getRawBits() <= obj2.getRawBits())
        return (obj1);
    return (obj2);
}

Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2){
    if (obj1.getRawBits() >= obj2.getRawBits())
        return (obj1);
    return (obj2);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &obj){
    return (out << obj.toFloat());
}
