#include "RobotomyRequestForm.hpp"

//!CONSTRUCTORS AND DESTRUCTORS
RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("RobotomyRequestForm", 72, 45), target(t) {
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

//!CANONICAL FORM
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    target = obj.target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) {
    *this = obj;
}

//!FUNCTIONS
void RobotomyRequestForm::exe() const{
	std::cout << "** Drilling noises **"<<std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (rand() % 2 == 1)
		std::cout << target << " have been robotomized successfully" <<std::endl;
	else
		std::cout << "The robotomization failed :(" <<std::endl;
	
}