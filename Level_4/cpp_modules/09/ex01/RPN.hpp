#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN {
public:
    RPN() = delete;
    RPN(std::string) = delete;
    ~RPN() = delete;
    RPN(const RPN &obj) = delete;
    RPN &operator=(const RPN &obj) = delete;

    static int calculate(std::string str);
    static int operation(std::stack<std::string> *stak, std::string token, std::string num_1, std::string num_2);
};

#endif
