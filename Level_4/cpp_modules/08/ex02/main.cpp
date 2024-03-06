#include "Array.hpp"

int main()
{
    Array<int> intArray;
    std::cout << "Construction of an empty array" << std::endl;
    intArray.print();
    intArray[0] = 42;
    intArray.print();
    std::cout << "Size of the array: " << intArray.size() << std::endl;
    std::cout << std::endl;

    //test for creation of an array of size 5
    {
    std::cout << "Construction of an array of size 5" << std::endl;
    Array<int> neww(5);
    neww.print();
    std::cout << "Size of the array: " << neww.size() << std::endl;
    }
    std::cout << std::endl;

    //test for overloaded constructor
    {
    Array<int> neww;
    neww = intArray;
    neww.print();
    neww[0] = 21;
    neww.print();
    intArray.print();
    }
    std::cout << std::endl;

    //test for copy constructor
    {
    Array<int> neww(intArray);
    neww.print();
    neww[0] = 111;
    neww.print();
    intArray.print();
    }
    std::cout << std::endl;

    //test for exception
    {
    Array<int> neww(5);
    neww[5] = 42;
    }

    return 0;
}