#include "Bureaucrat.hpp"

int main(){
    Bureaucrat	Amigo("Il amigo", 1);
	Bureaucrat	Ragazza("La ragazza", 150);

	Form F;
	try{
		Form Flow("Flow", 149, 149);
		std::cout << std::endl;
		Ragazza.signForm(Flow);
		Ragazza.increment();
		Ragazza.increment();
		std::cout << Flow.getIsSigned() << std::endl;
		std::cout << "2 increments" << std::endl;
		Ragazza.signForm(Flow);
		std::cout << Flow.getIsSigned() << std::endl;
	}
	catch (std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}