#include "Span.hpp"

int main( void )
{
    {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
    }
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
    // Span S(10);

    // try{
    //     S.addNumber(0);
    //     for (int i = 0; i < 9; i++)
    //         S.addNumber(i);
    // }
    // catch (const std::exception &e){
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }
    // std::cout << "Longest Span is : " << S.longestSpan() << std::endl;
    // std::cout << "Shortest Span is : " << S.shortestSpan() << std::endl;
	// return 0;
    // }
}