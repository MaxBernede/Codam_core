#include "Span.hpp"

int main( void )
{
    Span S(2);

    try{
        S.addNumber(12);
        S.addNumber(62);
    }
    catch (std::exception e){
        std::cout << "Exception caught" << std::endl ;
    }
    //S.addNumber(3);
	return 0;
}