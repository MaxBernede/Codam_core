#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
   Dog doggy;
   //just adding = 0 to the virtual function
   //Animal animol;

    // std::cout << "TEST FROM EXERCISE ***************" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    // std::cout << "END TEST FROM EXERCISE ***************" << std::endl;

    return 0;
}