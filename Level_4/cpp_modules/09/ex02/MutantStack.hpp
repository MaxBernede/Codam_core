#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>


//Class std::stack is a container with a std::deque as default underlaying container
//We can access the underlaying container with the member function c
//We can then use the iterators of the underlaying container to access the elements
template <typename T>
class MutantStack : public std::stack<T>{
public:
    MutantStack();
    ~MutantStack();

    MutantStack(const MutantStack &obj);
    MutantStack &operator=(const MutantStack &obj);
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

# include "MutantStack.tpp"

#endif
