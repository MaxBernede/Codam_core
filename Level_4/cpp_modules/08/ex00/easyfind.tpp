#include "easyfind.hpp"

template <typename T>
int *easyfind(T &values, int search){
	try{
	int val_size = values.size();
	for (int i = 0; i < val_size; i++){
		if (values[i] == search){
			std::cout << "val found at index : " << i << std::endl;
			return &values[i];
		}
	}
	}
	catch(std::exception e){
		std::cout << "Error catched" << std::endl;
	}
	std::cout << "Not found" << std::endl;
	return nullptr;
}