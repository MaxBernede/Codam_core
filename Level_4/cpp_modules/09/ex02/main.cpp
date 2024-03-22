#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac == 1){
		std::cout << "Usage: ./Pmergeme \"Args\"" << std::endl;
		return 0;
	}
	PmergeMe pmergeMe(av);
	
	return 0;
}