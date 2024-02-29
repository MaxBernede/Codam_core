#include "Array.hpp"

int main()
{
    Array<int> intArray;
    intArray.print();
    intArray.array[0] = 42;
    intArray.print();

    //test for overloaded constructor
    {
    Array<int> neww;
    neww = intArray;
    neww.print();
    neww.array[0] = 21;
    neww.print();
    intArray.print();
    }
    //test for copy constructor
    {
    Array<int> neww(intArray);
    }
    return 0;
}