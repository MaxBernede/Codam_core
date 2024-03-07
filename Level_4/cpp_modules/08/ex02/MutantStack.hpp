#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>

template <typename T, class Container>
class MutantStack : public std::stack<T, Container>{
public:
    MutantStack();
    ~MutantStack();

    MutantStack(const MutantStack &obj);
    MutantStack &operator=(const MutantStack &obj);
    typedef typename Container::iterator iterator;
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif
