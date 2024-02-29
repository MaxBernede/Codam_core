#include "Node.hpp"

int main()
{
	Node<int> node;
	node.data = 5;
	std::cout << node.data << std::endl;
	return 0;
}