#include "Data.hpp"

Data::Data() : value(0)
{
	std::cout << "Default constructor Data()" << std::endl;
}

Data::Data(int value) : value(value)
{
	std::cout << "Constructor Data(" << value << ")" << std::endl;
}

int	Data::getValue() const
{
	return (value);
}

void	Data::setValue(int value)
{
	this->value = value;
}

