#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <chrono>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe(char **av);
    ~PmergeMe();

    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);

    int  add_number(char *nb);
    void print_first(std::string str);
    void calculate_list();
    void calculate_deque();
private:
    PmergeMe();
    std::list<int> _list;
    std::deque<int> _deque;
    std::string _duration_list;
    std::string _duration_deque;

};

#endif
