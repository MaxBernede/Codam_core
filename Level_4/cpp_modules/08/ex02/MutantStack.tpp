#include "MutantStack.hpp"

// Constructors and Destructor
template <typename T, class Container>
MutantStack<T, Container>::MutantStack() {
    std::cout << "MutantStack default Constructor called" << std::endl;
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack() {
    std::cout << "MutantStack Destructor called" << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &obj) {
    //copy depending on vars;
    return *this;
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &obj) {
    *this = obj;
}
