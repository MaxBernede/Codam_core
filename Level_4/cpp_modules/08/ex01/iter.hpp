#pragma once

#include <iostream>
#include <string>

template <typename T>
void print(T &arg){
    std::cout << "arg : " << arg << std::endl; 
}

template< typename T, typename F >
void iter( T * array, size_t size, F f) {
    for ( size_t i = 0; i < size; i++ ) {
        f(array[i]);
    }
}