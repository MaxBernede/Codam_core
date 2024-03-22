#include "PmergeMe.hpp"

void PmergeMe::print_first(std::string str) {
	std::cout << str;
	int counter = 0;
    for (auto it = _deque.begin(); it != _deque.end(); ++it) {
        std::cout << ' ' << *it;
        ++counter;
		if (counter == 5){
			if (_deque.size() > 5)
				std::cout << " ...";
			break;
		}
    }
	std::cout << std::endl;
}

void PmergeMe::calculate_list(){
	auto start = std::chrono::high_resolution_clock::now();
	_list.sort();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	_duration_list = std::to_string(duration.count());
}

void PmergeMe::calculate_deque(){
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(_deque.begin(), _deque.end());
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	_duration_deque = std::to_string(duration.count());
}

PmergeMe::PmergeMe(char **av) {
	//std::cout << "Constructor called" << std::endl;
	for (int i = 1; av[i]; i++) {
		int n;
		try {
			n = std::atoi(av[i]);
			_deque.push_back(n);
		} 
		catch (...) {
			std::cout << "Error: One argument is an invalid int: " << av[i] << std::endl;
			return ;
		}
	}
	_list.insert(_list.begin(), _deque.begin(), _deque.end());
	print_first("Before: ");
	calculate_list();
	calculate_deque();
	print_first("After: ");
	std::cout << "Time to process a range of " << _list.size() << " elements: with std::list : " << _duration_list << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements: with std::deque : " << _duration_deque << " us" << std::endl;
}

PmergeMe::~PmergeMe() {
	//std::cout << "Destructor called" << std::endl;
	;
}