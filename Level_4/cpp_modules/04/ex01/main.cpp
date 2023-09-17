#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    //const Animal* meta = new Animal();
    // const Animal* i = new Cat("el gato");
    // std::cout << std::endl;
    // const Animal* j = new Dog("Snoopy");
    // std::cout << std::endl;
    // // std::cout << i->getType() << " " << std::endl;
    // std::cout << j->getType() << " " << std::endl;
    // // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // //meta->makeSound();

    // //delete meta;
    // delete i;
    // std::cout << std::endl;
    // delete j;

    Animal *arr[10];
    std::cout << "No cons?" << std::endl;
    for (int i = 0; i < 5 ; i++)
        arr[i] = new Dog;
    std::cout << std::endl;
    for (int i = 5; i < 10 ; i++)
        arr[i] = new Cat;
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        delete arr[i];
    return 0;
}