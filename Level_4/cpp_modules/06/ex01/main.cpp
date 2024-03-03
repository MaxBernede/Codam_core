#include "Serializer.hpp"

#include <iostream>

//static void	testSerializer(double val, const char *str);


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

// int	main(void)
// {
// 	testSerializer(23.23, "Lorem ipsum");
// 	return (0);
// }

// static void	testSerializer(double val, const char *str)
// {
// 	Data		file;
// 	uintptr_t	raw = Serializer::serialize(&file);
// 	Data		*ptr = Serializer::deserialize(raw);
// 	Data		*comp = &file;

// 	file.value = val;
// 	ptr->str = str;
// 	std::cout << "Address" << std::endl;
// 	std::cout	<< "file\t"	<< &file	<< '\n'
// 				<< "ptr\t"	<< ptr		<< '\n'
// 				<< "comp\t"	<< comp		<< '\n'
// 				<< "raw\t"	<< raw		<< '\n';
// 	std::cout << "Content" << std::endl;
// 	std::cout	<< "file\t"	<< file.value	<< '\t'	<< file.str	<< '\n'
// 				<< "ptr\t"	<< ptr->value	<< '\t'	<< ptr->str	<< '\n'
// 				<< std::flush;
// }
