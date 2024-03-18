#include "MutantStack.hpp"
#include <stack>
int main()
{
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.top() << std::endl;
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);

MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
}


{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(10);
mstack.push(15);
std::cout << "From start to finish :" << std::endl;
MutantStack<int>::iterator it = mstack.begin();
while (it != mstack.end()) {
	std::cout << *it << " ";
	++it;
}
std::cout << std::endl;
std::cout << "From finish to start :" << std::endl;
MutantStack<int>::reverse_iterator rit = mstack.rbegin();
while (rit != mstack.rend()) {
	std::cout << *rit << " ";
	++rit;
}
}

std::cout << "---------------------" << std::endl;
{
	std::cout << "Test with a copy of the stack" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(10);
	mstack.push(15);
	MutantStack<int> mstack2(mstack);
	mstack2.push(20);
	std::cout << "From start to finish :" << std::endl;
	MutantStack<int>::iterator it = mstack2.begin();
	while (it != mstack2.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	MutantStack<int>::iterator it2 = mstack.begin();
	std::cout << "From start to finish of the original stack :" << std::endl;
	while (it2 != mstack.end()) {
		std::cout << *it2 << " ";
		++it2;
	}
}

std::cout << "---------------------" << std::endl;
{
	std::cout << "Test with an assignation of the stack" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(10);
	mstack.push(15);
	MutantStack<int> mstack2 = mstack;
	mstack2.push(20);
	std::cout << "From start to finish :" << std::endl;
	MutantStack<int>::iterator it = mstack2.begin();
	while (it != mstack2.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	MutantStack<int>::iterator it2 = mstack.begin();
	std::cout << "From start to finish of the original stack :" << std::endl;
	while (it2 != mstack.end()) {
		std::cout << *it2 << " ";
		++it2;
	}
}

return 0;
}