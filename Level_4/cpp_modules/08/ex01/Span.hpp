#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <array>

class Span {
public:
    Span();
    Span(unsigned int n);
    ~Span();

    void addNumber(int n);

    unsigned int get_max();
    // Copy constructor
    Span(const Span &obj);
    // Operator overload
    Span &operator=(const Span &obj);

private:
    unsigned int N;
    unsigned int len;
    int array[];
};

#endif
