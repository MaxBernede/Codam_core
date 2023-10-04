#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	~Fixed();

	// Copy constructor
	Fixed(const Fixed &obj);
	// Operator overload
	Fixed &operator=(const Fixed &obj);

	//Comparison
	bool operator>(const Fixed& obj) const;
	bool operator<(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;

	//Arithmetic
	Fixed &operator*(const Fixed& obj);
	Fixed &operator/(const Fixed& obj);
	Fixed &operator+(const Fixed& obj);
	Fixed &operator-(const Fixed& obj);

	//Member Functions
	Fixed &min(Fixed &obj1, Fixed &obj2);
	Fixed &max(Fixed &obj1, Fixed &obj2);
	Fixed &min(const Fixed &obj1, const Fixed &obj2);
	Fixed &max(const Fixed &obj1, const Fixed &obj2);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
private:
	int	_raw;
	static const int _fractional_bits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);


#endif
