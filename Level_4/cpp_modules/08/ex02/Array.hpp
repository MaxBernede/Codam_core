#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int size);
    ~Array();
    void print();

    // Canonical form
    T& operator[](int index);
    Array<T>& operator=(const Array<T>& obj);
    Array(const Array<T> &obj);

    int size() const;
    // T* getArray() const;
    class IndexOutOfBoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
private:
    T* array;
    int size_n;
};

#include "Array.tpp"

#endif
