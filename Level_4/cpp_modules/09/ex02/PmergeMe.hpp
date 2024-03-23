#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
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
    void calculate_vector();
    void calculate_deque();
    template <typename T> T merge(T &left, T &right);
    template <typename T> T merge_sort(T &container);

private:
    PmergeMe();
    std::vector<int> _vector;
    std::deque<int> _deque;
    std::string _duration_vector;
    std::string _duration_deque;

};

#endif
