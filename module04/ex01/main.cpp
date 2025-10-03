#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "---- Deleting animals ----\n";
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    std::cout << "---- Testing deep copy ----\n";
    Dog basic;
    basic.makeSound();
    basic.getBrain()->setIdea(0, "I want a bone!");

    Dog copy = basic;
    std::cout << "Copy dog idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;

    return 0;
}

