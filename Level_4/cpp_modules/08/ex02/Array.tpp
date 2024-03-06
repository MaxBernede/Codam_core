#include "Array.hpp"


template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw() {
    return "Index out of bounds";
}

template <typename T>
Array<T>::Array() : size_n(1){
    std::cout << "Array Default constructor called" << std::endl;
    array = new T[size_n];
}


template <typename T>
Array<T>::Array(unsigned int n) : size_n(n){
    std::cout << "Array Constructor called" << std::endl;
    array = new T[size_n + 1]; 
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
    for (int i = 0; i < size_n; i++)
        std::cout << " " << *(array + i);
    std::cout << std::endl;
}

// <template typename T>
// T* Array::getArray() const {
//     return *array;
// }

template <typename T>
int Array<T>::size() const{
    return size_n;
}

template <typename T>
T& Array<T>::operator[](int index) {
    try {
        if (index >= 0 && index < size_n) 
            return array[index];
        else
            throw IndexOutOfBoundException();
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return array[0];
}

// Canonical form
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
    std::cout << "Array Assignation operator called" << std::endl;
    if (this == &obj) {
        return *this;
    }
    if (this->array != nullptr) {
        delete[] this->array;
    }
    this->size_n = obj.size();
    this->array = new T[size_n];
    for (int i = 0; i < size_n; i++) {
        this->array[i] = obj.array[i];
    }
    return *this;
}

template <typename T>
Array<T>::Array(const Array<T> &obj) {
    std::cout << "Array Copy constructor called" << std::endl;
    this->size_n = obj.size();
    this->array = new T[size_n];
    for (int i = 0; i < size_n; i++) {
        this->array[i] = obj.array[i];
    }
    *this = obj;
}
