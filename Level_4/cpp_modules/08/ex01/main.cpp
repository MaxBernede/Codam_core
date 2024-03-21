#include "Span.hpp"

int main( void )
{

    {
    std::cout << "Test adding list" << std::endl;
    Span S(5);
    std::vector<int> list = {1, 2, 3, 4, 5};
    S.addList(list);
    S.show_array();
    }
    // {
    // Span sp = Span(5);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // }
    // {
    // std::cout << "Test adding too much args" << std::endl;
    // Span S(1);
    // try{
    //     S.addNumber(0);
    //     S.addNumber(1);
    // }
    // catch (const std::exception &e){
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }
    // }

    // {
    // std::cout << "Test not enough args for function" << std::endl;
    // Span S(1);
    // try{
    //     S.addNumber(0);
    //     std::cout << S.longestSpan();
    // }
    // catch (const std::exception &e){
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }
    // }

    // {
    // std::cout << "Test copy constructor" << std::endl;
    // Span S(3);
    // S.addNumber(0);
    // S.addNumber(1);
    // Span S2(S);
    // S2.addNumber(2);
    // S2.show_array();
    // S.show_array();
    // }

    // {
    // std::cout << "Test overload = operator" << std::endl;
    // Span S(3);
    // S.addNumber(0);
    // S.addNumber(1);
    // Span S2 = S;
    // S2.addNumber(99);
    // S2.show_array();
    // S.show_array();
    // }

    // {
    // std::srand(static_cast<unsigned int>(std::time(NULL)));
    // Span S(10000);

    // try{
    //     for (int i = 0; i < 10000; i++)
    //         S.addNumber((rand() % 10000000) + 1);
    // }
    // catch (const std::exception &e){
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }
    // std::cout << "Longest Span is : " << S.longestSpan() << std::endl;
    // std::cout << "Shortest Span is : " << S.shortestSpan() << std::endl;
	// return 0;
    // }
    return 0;
}