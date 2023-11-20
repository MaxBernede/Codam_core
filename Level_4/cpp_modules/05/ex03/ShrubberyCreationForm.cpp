#include "ShrubberyCreationForm.hpp"

//!CONSTRUCTORS AND DESTRUCTORS
ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 145, 137), target(t) {
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

//!CANONICAL FORM
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    target = obj.target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) {
    *this = obj;
}

//!FUNCTIONS
void ShrubberyCreationForm::exe() const{
	std::fstream my_file;
    std::string file_name;
    file_name = target + "_shrubbery";
	my_file.open(file_name.c_str(), std::ios::trunc | std::ios::out);
	if (!my_file)
		std::cout << "Error: File not created!" << std::endl;
	else {
		my_file << "         |\n        -+-\n         A\n        /=\\               /\\  /\\    ___  _ __  _ __ __    __\n      i/ O \\i            /  \\/  \\  / _ \\| '__|| '__|\\ \\  / /\n      /=====\\           / /\\  /\\ \\|  __/| |   | |    \\ \\/ /\n      /  i  \\           \\ \\ \\/ / / \\___/|_|   |_|     \\  /\n    i/ O * O \\i                                       / /\n    /=========\\        __  __                        /_/    _\n    /  *   *  \\        \\ \\/ /        /\\  /\\    __ _  ____  | |\n  i/ O   i   O \\i       \\  /   __   /  \\/  \\  / _` |/ ___\\ |_|\n  /=============\\       /  \\  |__| / /\\  /\\ \\| |_| |\\___ \\  _\n  /  O   i   O  \\      /_/\\_\\      \\ \\ \\/ / / \\__,_|\\____/ |_|\ni/ *   O   O   * \\i\n/=================\\\n       |___|\n";
		my_file.close();
	}
}