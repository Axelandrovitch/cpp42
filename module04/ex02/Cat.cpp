#include "Cat.hpp"

Cat::Cat() : Animal() {
  _type = "Cat";
  _brain = new Brain();
  std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat copy constructor called\n";
  _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
    delete _brain;
    _brain = new Brain(*other._brain);
  }
  std::cout << "Cat assignement operator called\n";
  return *this;
}

Cat::~Cat() {
  delete _brain;
  std::cout << "Cat deconstructor called\n";
}

void Cat::makeSound() const {
  std::cout << "Miaou Miaou!\n";
}

Brain* Cat::getBrain() const {
  return _brain;
}
