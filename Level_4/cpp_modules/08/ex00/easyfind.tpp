#include "easyfind.hpp"

template <typename T>
int *easyfind(T &values, int search){
	try{
	typename T::iterator it = std::find(values.begin(), values.end(), search);
	if (it != values.end()){
		std::cout << "val found at index : " << std::distance(values.begin(), it) << std::endl;
		return &(*it);
	}
	//int val_size = values.size();
	// for (int i = 0; i < val_size; i++){
	// 	if (values[i] == search){
	// 		std::cout << "val found at index : " << i << std::endl;
	// 		return &values[i];
	// 	}
	// }
	}
	catch(std::exception e){
		std::cout << "Error catched" << std::endl;
	}
	std::cout << "Not found" << std::endl;
	return nullptr;
}