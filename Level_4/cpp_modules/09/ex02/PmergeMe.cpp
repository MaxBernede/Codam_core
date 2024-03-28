#include "PmergeMe.hpp"

int PmergeMe::add_number(char *nb){
	int n;
	try {
		std::string str(nb);
		if (str.find_first_not_of("+0123456789") != std::string::npos){
			std::cout << "Error: One argument is not a number: " << nb << std::endl;
			return 1;
		}
		if (nb[0] == '-'){
			std::cout << "Error: One argument is negative: " << nb << std::endl;
			return 1;
		}
		n = std::atoi(nb);
		if (n < 0){
			std::cout << "Error: One argument is invalid: " << nb << std::endl;
			return 1;
		}
		_deque.push_back(n);
	} 
	catch (...) {
		std::cout << "Error: One argument is an invalid int: " << nb << std::endl;
		return 1;
	}
	return 0;
}

PmergeMe::PmergeMe(char **av) {
	//std::cout << "Constructor called" << std::endl;
	for (int i = 1; av[i]; i++) {
		if (add_number(av[i]))
			return;
	}
	_vector.insert(_vector.begin(), _deque.begin(), _deque.end());
	print_first("Before: ");
	calculate_vector();
	calculate_deque();
	print_first("After: ");
	std::cout << "Time to process a range of " << _vector.size() << " elements: with std::vector : " << _duration_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements: with std::deque : " << _duration_deque << " us" << std::endl;
}

PmergeMe::~PmergeMe() {
	//std::cout << "Destructor called" << std::endl;
	;
}

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

void PmergeMe::calculate_vector(){
	auto start = std::chrono::high_resolution_clock::now();
	_vector = merge_sort(_vector);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	_duration_vector = std::to_string(duration.count());
}

void PmergeMe::calculate_deque(){
	auto start = std::chrono::high_resolution_clock::now();
	_deque = merge_sort(_deque);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	_duration_deque = std::to_string(duration.count());
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
	std::cout << "Assignation operator called" << std::endl;
	_vector = obj._vector;
	_deque = obj._deque;
	_duration_vector = obj._duration_vector;
	_duration_deque = obj._duration_deque;
	return *this;
}

template <typename T>
T PmergeMe::merge(T &left, T &right){
	T result;
	int l = 0;
	int r = 0;

	while (l < (int)left.size() && r < (int)right.size()){
		if (left[l] < right[r]){
			result.push_back(left[l]);
			l++;
		}
		else {
			result.push_back(right[r]);
			r++;
		}
	}
	while (l < (int)left.size()){
		result.push_back(left[l]);
		l++;
	}
	while (r < (int)right.size()){
		result.push_back(right[r]);
		r++;
	}
	return result;
}

template <typename T>
T PmergeMe::merge_sort(T &container){
	if (container.size() < 2)
		return container;

	T left = T(container.begin(), container.begin() + container.size() / 2);
	T right = T(container.begin() + container.size() / 2, container.end());

	left = merge_sort(left);
	right = merge_sort(right);

	return merge(left, right);
}