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
	static Fixed &min(Fixed &obj1, Fixed &obj2);
	static Fixed &max(Fixed &obj1, Fixed &obj2);
	static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
	static const Fixed &max(const Fixed &obj1, const Fixed &obj2);

	//Increase decrease
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

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
