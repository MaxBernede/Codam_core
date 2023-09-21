#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <iomanip>

class Fixed
{
public:
	Fixed();
	Fixed(int n);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int fixpoint_nb;
	static const int fractional = 8;
};

#endif