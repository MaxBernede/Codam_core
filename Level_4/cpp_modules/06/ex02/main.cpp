#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	// for (int i = 0; i < 20 ; i++){
	// 	generate();
	// }
	return (0);
}

Base *generate(void){
	int i = rand() % 3;
	if (i == 0)
		return new BaseA;
	else if (i == 1)
		return new BaseB;
	else
		return new BaseC;
}