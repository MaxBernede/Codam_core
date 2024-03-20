#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class PmergeMe {
public:
    PmergeMe() = delete;
    PmergeMe(std::string) = delete;
    ~PmergeMe() = delete;
    PmergeMe(const PmergeMe &obj) = delete;
    PmergeMe &operator=(const PmergeMe &obj) = delete;

};

#endif
