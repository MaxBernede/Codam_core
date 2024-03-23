#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac == 1){
		std::cout << "Usage: ./Pmergeme \"Args\"" << std::endl;
		return 0;
	}
	PmergeMe pmergeMe(av);
	
	{
		std::cout << "Test copy constructor" << std::endl;
		PmergeMe pmergeMe2(pmergeMe);
		pmergeMe2.print_first("Copy: ");
	}
	pmergeMe.print_first("Original: ");

	{
		std::cout << "Test assignation operator" << std::endl;
		PmergeMe pmergeMe3 = pmergeMe;
		pmergeMe3.print_first("Assignation: ");
	}
	pmergeMe.print_first("Original: ");

	return 0;
}