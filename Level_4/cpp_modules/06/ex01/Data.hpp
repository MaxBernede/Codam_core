#pragma once

# include <iostream>

class Data
{
public:
	Data();
	Data(int value);
	int getValue() const;
	void setValue(int value);
	int value;
	std::string str;
};
