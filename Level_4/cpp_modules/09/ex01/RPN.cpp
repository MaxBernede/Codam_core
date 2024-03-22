#include "RPN.hpp"


void print_stack(std::stack<std::string> stak){
    while (!stak.empty()){
        std::cout << stak.top() << std::endl;
        stak.pop();
    }
}

int RPN::operation(std::stack<std::string> *stak, std::string token, std::string num_2, std::string num_1){
    int n1;
    int n2;
    try {
        n1 = std::stoi(num_1);
        n2 = std::stoi(num_2);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << ": one of the arg is not valid" << std::endl;
        return 1;
    }
    int result = 0;
    if (token == "+")
        result = n1 + n2;
    else if (token == "-")
        result = n1 - n2;
    else if (token == "*")
        result = n1 * n2;
    else if (token == "/"){
        if (n2 == 0){
            std::cout << "Error, division by zero" << std::endl;
            return 1;
        }
        result = n1 / n2;
    }
    stak->push(std::to_string(result));
    return 0;

}

int RPN::calculate(std::string str){
    std::stack<std::string> stak;
    std::istringstream iss(str);
    std::string token;
    
    while (iss >> token) {
        //std::cout << "Token: " << token << std::endl;
        if (token == "+" || token == "-" || token == "/" || token == "*"){
            if (stak.size() < 2){
                std::cout << "Error, stack size is too small for an operation" << std::endl;
                return 1;
            }
            std::string num_1 = stak.top();
            stak.pop();
            std::string num_2 = stak.top();
            stak.pop();
            if (operation(&stak, token, num_1, num_2)){
                return 1;
            }

        }
        else
            stak.push(token);
    }
    if (stak.size() != 1){
        std::cout << "Error, stack size is not 1" << std::endl;
        return 1;
    }
    std::cout << stak.top() << std::endl;
    return 0;
}