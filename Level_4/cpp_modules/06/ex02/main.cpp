#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

void identify(Base* p){
	//std::cout << "Pointer" << std::endl;
	if (dynamic_cast<BaseA *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<BaseB *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<BaseC *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error with type" << std::endl;
}

void identify(Base& p){
	//std::cout << "Reference" << std::endl;
	try {
		if (dynamic_cast<BaseA *>(&p))
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &error){
		;
	}
	try {
		if (dynamic_cast<BaseB *>(&p))
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &error){
		;
	}
	try {
		if (dynamic_cast<BaseC *>(&p))
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &error){
		;
	}
}

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	// for (int i = 0; i < 20 ; i++){
	// 	generate();
	// }
	Base *base = generate();
	std::cout << "Identify by pointer: ";
	identify(base);
	std::cout << "Identify by address: ";
	identify(*base);
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