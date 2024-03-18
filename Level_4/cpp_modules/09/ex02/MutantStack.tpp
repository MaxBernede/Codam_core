#include "MutantStack.hpp"

// Constructors and Destructor
template <typename T>
MutantStack<T>::MutantStack() {
    std::cout << "MutantStack default Constructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack Destructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &obj) {
    std::cout << "MutantStack Assignation operator called" << std::endl;
    //copy depending on vars;
    if (this != &obj) {
        this->c = obj.c;
    }
    this->c = obj.c;
    return *this;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj) {
    std::cout << "MutantStack copy Constructor called" << std::endl;
    *this = obj;
}
