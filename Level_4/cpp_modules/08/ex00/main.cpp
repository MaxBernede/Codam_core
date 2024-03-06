#include "easyfind.hpp"
#include <iostream>
#include <iomanip>
#include <vector>


int main( void ) {
	std::vector<int> values;
	for (int i {1}; i <= 100; ++i)
		values.push_back(i);
	std::cout << std::endl;
	return 0;
}