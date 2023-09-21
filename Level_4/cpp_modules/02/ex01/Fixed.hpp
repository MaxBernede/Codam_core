#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <string>

class Fixed {
public:
	Fixed();
	Fixed(int);
	~Fixed();

	// Copy constructor
	Fixed(const Fixed &obj);
	// Operator overload
	Fixed &operator=(const Fixed &obj);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
private:
	int	_number;
	static const int _fractional_bits = 8;
};

#endif
