#include "easyfind.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <map>

int main( void ) {
	{
	std::vector<int> values;
	for (int i {1}; i <= 100; ++i)
		values.push_back(i);
	for (int i: values)
		std::cout << i << ' ';
	easyfind(values, 30);
	std::cout << std::endl;
	}
	{
	std::array<int, 7> arr = {1, 2 , 3 , 5 , 8 , 9 , 7};
    easyfind(arr, 10);
	easyfind(arr, 7);
    std::cout << std::endl;
	}
	{
	std::map<int, int> mapTest;
	mapTest[1] = 10;
	mapTest[2] = 20;
	easyfind(mapTest, 5);
	easyfind(mapTest, 10);
	}
	// {
	// int i = 7;
	// easyfind(i, 5);
	// }
	return 0;
}