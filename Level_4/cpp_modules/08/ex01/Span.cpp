#include "Span.hpp"

const char *Span::NotEnoughArg::what() const throw(){
    return "Not enough arguments for function call";
}

// Constructors and Destructor
Span::Span(){
    ;
}

Span::Span(unsigned int n) : N(n){
    std::cout << "Span Constructor called" << std::endl;
}

Span::~Span() {
    std::cout << "Span Destructor called" << std::endl;
}


// Canonical form
Span &Span::operator=(const Span &obj) {
    if (this != &obj){
        this->N = obj.N;
        this->array = obj.array;
    }
    return *this;
}

Span::Span(const Span &obj) {
    this->N = obj.N;
    this->array = obj.array;
}

//Member functions
void Span::addNumber(int i){
    if (array.size() < N){
        array.push_back(i);
        std::cout << "Number added : " << i << std::endl;
    }
    else
        throw std::runtime_error("Too much arguments");
}

int Span::shortestSpan(){
    if (array.size() <= 1)
        throw NotEnoughArg();
    std::vector<int> tmp = array;
    std::sort(tmp.begin(), tmp.end());
    int min = INT32_MAX;
    for (int i = 0; i < (int)tmp.size() - 1; i++){
        if (tmp[i + 1] - tmp[i] < min){
            min = tmp[i + 1] - tmp[i];
            //std::cout << tmp[i] << " " << tmp[i + 1] << std::endl;
        }
    }
    return min;
}

int Span::longestSpan(){
    if (array.size() <= 1)
        throw NotEnoughArg();
    int min = *std::min_element(array.begin(), array.end());
    int max = *std::max_element(array.begin(), array.end());;
    return (max - min);
}

void Span::show_array(){
    for (int i = 0; i < (int)array.size(); i++){
        std::cout << array[i] << std::endl;
    }
}


unsigned int Span::get_max(){
    return this->N;
}
