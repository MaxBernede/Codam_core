#include "Bureaucrat.hpp"

int main(){
    Bureaucrat	Amigo("Il amigo", 1);
	Bureaucrat	Ragazza("La ragazza", 150);

	std::cout << "Created two bureaucrat!" << std::endl;
	std::cout << Amigo << std::endl;
	std::cout << Ragazza << std::endl;

	std::cout << "\nLet's try creating Thor with grade 0" << std::endl;
	/* GradeTooHighException */
	try
	{
		Bureaucrat Thor("Thor", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot create Thor!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nLet's try creating John with grade 151" << std::endl;
	/* GradeTooLowException */
	try
	{
		Bureaucrat John("Thor", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot create John!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nLet's try promoting Amigo!" << std::endl;
	/* Increment throwing exception */
	try
	{
		Amigo.increment();
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot increment the grade of Amigo!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\nLet's try demoting Ragazza!" << std::endl;
	/* Decrement throwing exception */
	try
	{
		Ragazza.decrement();
	}
	catch (std::exception& e)
	{
		std::cout << "Cannot decrement the grade of Ragazza!" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
	}

return 0;
}