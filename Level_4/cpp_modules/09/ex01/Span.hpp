#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

class Span {
public:
    Span(unsigned int n);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    void show_array();

    unsigned int get_max();
    // Copy constructor
    Span(const Span &obj);
    // Operator overload
    Span &operator=(const Span &obj);
    class NotEnoughArg : public std::exception {
        public:
            const char *what() const throw();
        };
private:
    Span();
    unsigned int N;
    std::vector<int> array;
};

#endif
