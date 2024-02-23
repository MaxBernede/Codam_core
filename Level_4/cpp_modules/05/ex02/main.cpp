#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	Bureaucrat	King("King", 1);
	Bureaucrat	Teacher("Teacher", 124);
	ShrubberyCreationForm S("sh");
	RobotomyRequestForm R("Human");
	PresidentialPardonForm P("Bad teacher");

	try{
		std::cout << "\n\n";
		King.signForm(S);
		King.signForm(R);
		Teacher.signForm(P);
		std::cout << std::endl;
		Teacher.executeForm(S);
		King.executeForm(R);
		Teacher.executeForm(P);
		std::cout << "\n\n";
	}
	catch (std::exception& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
