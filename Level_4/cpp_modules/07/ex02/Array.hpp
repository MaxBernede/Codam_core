#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int size);
    ~Array(); // Destructor to free memory
    void print();

    // Canonical form
    Array<T>& operator=(const Array<T>& obj);
    //Array(const Array<T> &obj);

    T* array;
private:
    int size;
};

#include "Array.tpp"

#endif
