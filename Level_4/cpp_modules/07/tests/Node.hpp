#ifndef	NODE_HPP
# define	NODE_HPP

# include <iostream>
# include <string>

template <typename T>
class Node {
public:
	Node();
	T data;
};

# include "Node.cpp"
#endif