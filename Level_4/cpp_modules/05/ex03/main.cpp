#include "Intern.hpp"


int main(){
	Bureaucrat	King("King", 1);
	{
	std::cout << "\n\n\n";
	Intern someRandomIntern;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	King.signForm(*rrf);
	King.executeForm(*rrf);
	if (rrf != NULL)
		delete rrf;
	}
	{
	std::cout << "\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("wrong one", "test");
	if (rrf != NULL)
		delete rrf;
	}
	{
	std::cout << "\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "test");
	if (rrf != NULL)
		delete rrf;
	}
	{
	std::cout << "\n";
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "test");
	if (rrf != NULL)
		delete rrf;
	}
	return 0;
}
