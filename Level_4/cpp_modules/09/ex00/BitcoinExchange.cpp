#include "BitcoinExchange.hpp"

int BitcoinExchange::file_working(std::string name) {
    std::ifstream file(name);
    if (file.is_open()){
        std::string line;
        //skip first one
        std::getline(file, line);
        while (std::getline(file, line)){
            //std::cout << line << std::endl;
            std::stringstream ss(line);
            std::string part1, part2;
            if (std::getline(ss, part1, ',')) {
                if (std::getline(ss, part2, ',')){
                    _datas.insert({part1, part2});
                }
            }
        }
        file.close();
        return 0;
    }
    else {
        std::cout << "Error: File not found" << std::endl;
        return 1;
    }
}

// Constructors and Destructor
BitcoinExchange::BitcoinExchange(std::string n) : _filename(n){
    //std::cout << "BitcoinExchange Constructor called" << std::endl;
    if (file_working(n) == 1)
        exit(1);
}

BitcoinExchange::~BitcoinExchange() {
    //std::cout << "BitcoinExchange Destructor called" << std::endl;
    ;
}

// Canonical form
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
    std::cout << "BitcoinExchange Operator Overload called" << std::endl;
    if (this != &obj) {
        _datas = obj._datas;
        _filename = obj._filename;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
    std::cout << "BitcoinExchange Copy Constructor called" << std::endl;
    *this = obj;
}

bool compareDates(const std::string& date1, const std::string& date2) {
    // ASCII comparison to know if date1 is before date2
    // Compare year
    if (date1.substr(0, 4) != date2.substr(0, 4)) {
        return date1.substr(0, 4) <= date2.substr(0, 4);
    }
    // Compare month
    if (date1.substr(5, 2) != date2.substr(5, 2)) {
        return date1.substr(5, 2) <= date2.substr(5, 2);
    }
    // Compare day
    return date1.substr(8, 2) <= date2.substr(8, 2);
}

void print_exact(std::string coins, float value) {
    float price = std::stof(coins);
    if (price < 0){
        std::cout << "Error: negative price." << std::endl;
        return ;
    }
    price = price * value;
    std::cout << price << std::endl;
}

void BitcoinExchange::print_price(std::string date, float value) {
    std::map<std::string, std::string> tmp;
    for (auto &i : _datas) {
        if (!i.first.length() || !i.second.length()){
            std::cout << "Error: values." << std::endl;
            return;
        }
        if (i.first == date) {
            print_exact(i.second, value);
            return;
        }
        if (compareDates(i.first, date))
            if (tmp.empty())
                tmp.insert(i);
            else{
                tmp.clear();
                tmp.insert(tmp.begin(), i);
            }
        else{
            print_exact(tmp.begin()->second, value);
            return;
        }
    }
    if (!tmp.empty())
        print_exact(tmp.begin()->second, value);
    else
        std::cout << "Error: no data." << std::endl;
}

bool isValidDate(const std::string& date) {
    // Regular expression to match "YYYY-MM-DD" format
    // "\\d" is a digit, "{n}" is the number of digits
    std::regex pattern("^\\d{4}-\\d{2}-\\d{2}$");
    return std::regex_match(date, pattern);
}

bool isValidDays(const std::string& months, const std::string& days) {
    //std::cout << "months: " << months << " days: " << days << std::endl;
    int m = std::stoi(months);
    int d = std::stoi(days);
    if (m > 12 || m < 1)
        return false;
    if (d > 31 || d < 1)
        return false;
    return true;
}

int BitcoinExchange::check_errors(std::string date, std::string value, float *price) {
    //std::cout << "date: " << date << " value: " << value << std::endl;
    if (!isValidDate(date) || !isValidDays(date.substr(5, 2), date.substr(8, 2))){
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    }
    // length of value is not possible because max value is 1000
    if (value.length() > 5){
        std::cout << "Error: too large number." << std::endl;
        return 1;
    }
    *price = std::stof(value);
    if (*price > 1000){
        std::cout << "Error: too large number." << std::endl;
        return 1;
    }
    if (*price < (float)0){
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }
    std::cout << date << " => " << *price << " = ";
    print_price(date, *price);
    return 0;
}

std::string removeSpaces(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

void BitcoinExchange::checkDatas(std::string file) {
    std::ifstream f(file);
    std::string line;
    if (!f.is_open()) {
        std::cout << "Error: File not found" << std::endl;
        exit(1);
    }
    //skip first one
    std::getline(f, line);
    while (std::getline(f, line)) {
        std::istringstream ss(line);
        std::string date, value;
        float price;
        if (std::getline(ss, date, '|') && std::getline(ss, value, '|')) {
            date = removeSpaces(date);
            value = removeSpaces(value);
            if (check_errors(date, value, &price) == 1)
                continue;
        }
        else {
            if (date != "")
                std::cout << "Error: bad input => " << date << std::endl;
            else
                std::cout << "Error: bad input" << std::endl;
            continue;
        }
    }
}

void BitcoinExchange::printDatas() {
    for (auto &i : _datas)
        std::cout << i.first << " " << i.second << std::endl;
}