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
