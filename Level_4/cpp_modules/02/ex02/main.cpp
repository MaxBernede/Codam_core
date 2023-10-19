#include "Fixed.hpp"

int main( void ) {
{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );

//Test arithmetics
std::cout << b << std::endl;
std::cout << c << std::endl;
std::cout << d << std::endl;
std::cout << e << std::endl;

//test comparison
if (a == b)
	return 0;
if (c <= d)
	std::cout << c << " " << d << std::endl;

//public members
std::cout << Fixed::min( a, b ) << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::max( c, d ) << std::endl;
std::cout << Fixed::min( d, e ) << std::endl;

//Increment

std::cout << "start of increment\n" << a << std::endl;
a++;
std::cout << a << std::endl;
--a;
--a;
std::cout << a << std::endl;
return 0;
}



//codam tests
{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
}




return 0;
}