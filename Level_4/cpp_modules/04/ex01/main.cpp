#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal *arr[10];
    // std::cout << "No constructors because abstract class" << std::endl;
    // for (int i = 0; i < 5 ; i++)
    //     arr[i] = new Dog;
    // std::cout << std::endl;
    // for (int i = 5; i < 10 ; i++)
    //     arr[i] = new Cat;
    // std::cout << std::endl;
    // for (int i = 0; i < 10; i++)
    //     delete arr[i];

    // std::cout << "TEST FROM EXERCISE ***************" << std::endl;
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;
    // std::cout << "END TEST FROM EXERCISE ***************" << std::endl;

    Dog basic;
    //std::cout << basic.getType() << " " << std::endl;
    std::cout << std::endl;
    // Brain *dog_brain = basic.get_brain();
    // dog_brain->set_idea("Tango");
    // dog_brain->set_idea("Ballar");
    // dog_brain->set_idea("Ice cream");
    // dog_brain->get_ideas();
    {
    //dog constructor called but type is Animal due to object slicing
    //to not have this problem, the use of a pointer or reference is mandatory
    Dog tmp = basic;
    std::cout << std::endl;
    }
    return 0;
}