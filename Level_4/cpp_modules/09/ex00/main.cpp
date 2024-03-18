#include "BitcoinExchange.hpp"
int main(int ac, char **av) {
if (ac == 2){
	BitcoinExchange base("data.csv");
	//base.printDatas();
	base.checkDatas(av[1]);
}
else
	std::cout << "Usage: ./bitcoin [file.txt]" << std::endl;
return 0;
}