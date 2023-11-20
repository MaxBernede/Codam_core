#include "Intern.hpp"


int main(){
	// Bureaucrat	King("King", 1);
	// Bureaucrat	Teacher("Teacher", 46);
	// ShrubberyCreationForm S("sh");
	// RobotomyRequestForm R("Human");
	// PresidentialPardonForm P("Bad teacher");
	{
	std::cout << "\n\n\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	}
	{
	std::cout << "\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("wrong one", "test");
	delete rrf;
	}
	{
	std::cout << "\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "test");
	delete rrf;
	}
	{
	std::cout << "\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "test");
	delete rrf;
	}
	// try{
	// 	King.signForm(S);
	// 	King.signForm(R);
	// 	King.signForm(P);
	// 	std::cout << std::endl;
	// 	King.executeForm(S);
	// 	King.executeForm(R);
	// 	King.executeForm(P);
	// }
	// catch (std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// Bureaucrat	Ragazza("La ragazza", 139);

	// ShrubberyCreationForm S("home");
	// std::cout << std::endl;
	// try{
	// 	Ragazza.executeForm(S);
	// }
	// catch (std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// Ragazza.increment();
	// Ragazza.increment();
	// try{
	// 	Ragazza.executeForm(S);
	// }
	// catch (std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// Ragazza.signForm(S);
	// try{
	// 	Ragazza.executeForm(S);
	// }
	// catch (std::exception& e){
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	return 0;
}
