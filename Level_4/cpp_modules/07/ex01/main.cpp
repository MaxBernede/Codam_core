#include "iter.hpp"

int main( void ) {
	std::string array[] = {"a", "b", "c", "d", "e", "f", "g"};
    int size = sizeof(array) / sizeof(array[0]);

    iter(array, size, print<std::string &>);
    

    int int_array[] = {1, 3, 152, 0, -1};
    size = sizeof(int_array) / sizeof(int_array[0]);

    iter(int_array, size, print<int>);

    float float_array[] = {1.215f, 3.52, 152.0005, 0.4f, -1.6f};
    size = sizeof(float_array) / sizeof(float_array[0]);

    iter(float_array, size, print<float>);
	return 0;
}