#include "Bureaucrat.hpp"

int main(){
    Bureaucrat	Amigo("Il amigo", 1);
	Bureaucrat	Ragazza("La ragazza", 150);

	std::cout << std::endl << Amigo << std::endl;
	std::cout << Ragazza << std::endl;

	try{
		Bureaucrat Shoulderror("Lerore", 0);
	}
	catch (std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try{
		Amigo.increment();
	}
	catch (std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try{
		Ragazza.decrement();
	}
	catch (std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

return 0;
}