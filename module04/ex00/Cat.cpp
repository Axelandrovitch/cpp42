#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal() {
  _type = "Cat";
  std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  std::cout << "Cat assignement operator called\n";
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat deconstructor called\n";
}

void Cat::makeSound() const {
  std::cout << "Miaou Miaou!\n";
}
