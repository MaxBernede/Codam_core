#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	//check that we cant create it
	//Serializer S;
	Data d;
	uintptr_t	raw = Serializer::serialize(&d);
	std::cout << "Data :" << &d << std::endl;
	std::cout << "raw :" << raw << std::endl;
	Data	*ptr = Serializer::deserialize(raw);
	std::cout << "Data :" << ptr << std::endl;

	// int i= 10;
	// int *ptr_i = &i;

	// uintptr_t ptr_as_int = reinterpret_cast<uintptr_t>(ptr_i);
    // int* ptr_again = reinterpret_cast<int*>(ptr_as_int);

    // // Output the value to demonstrate the conversion
    // std::cout << "Value through pointer: " << *ptr_again << std::endl;
	return (0);
}
