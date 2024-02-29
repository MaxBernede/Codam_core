#include "Array.hpp"

template <typename T>
Array<T>::Array() : size(1){
    std::cout << "Array Default constructor called" << std::endl;
    array = new T[size];
}


template <typename T>
Array<T>::Array(unsigned int n) : size(n){
    std::cout << "Array Constructor called" << std::endl;
    array = new T[size + 1]; 
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array Destructor called" << std::endl;
    if (this->array != nullptr)
        delete[] array;
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << " " << *(array + i);
    std::cout << std::endl;
}

// // Canonical form
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
    if (this == &obj) {
        return *this;
    }
    if (this->array != nullptr) {
        delete[] this->array;
    }
    this->size = obj.size;
    this->array = new T[size];
    for (int i = 0; i < size; i++) {
        this->array[i] = obj.array[i];
    }
    return *this;
}

// template <typename T>
// Array<T>::Array(const Array<T> &obj) {
//     *this = obj;
// }
