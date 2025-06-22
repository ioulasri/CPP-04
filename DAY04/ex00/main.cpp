#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"

#include "WrongAnimals.hpp"
int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    std::cout << "\n----- Wrong Animals -----" << std::endl;
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongI = new WrongCat();

    std::cout << wrongI->getType() << " " << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;

    return 0;
}