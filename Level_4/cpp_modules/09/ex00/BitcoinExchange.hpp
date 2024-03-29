#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <regex>


class BitcoinExchange {
public:
    BitcoinExchange() = delete;
    BitcoinExchange(std::string);
    ~BitcoinExchange();

    // Copy constructor
    BitcoinExchange(const BitcoinExchange &obj);
    // Operator overload
    BitcoinExchange &operator=(const BitcoinExchange &obj);

    //member functions
    void    printDatas();
    int     file_working(std::string);
    void    checkDatas(std::string);
    void    print_price(std::string, float);
    int     check_errors(std::string date, std::string value, float *price);
private:
    std::map<std::string, std::string> _datas;
    std::ifstream _file;
    std::string _filename;
};

#endif
