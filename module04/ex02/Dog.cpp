#include "Dog.hpp"

Dog::Dog(): Animal() {
  _type = "Dog";
  _brain = new Brain();
  std::cout << "Dog default constructor called\n";
};

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << "Dog copy constructor called\n";
  _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
    delete _brain;
    _brain = new Brain(*other._brain);
  }
  std::cout << "Dog assignment operator called\n";
  return *this;
}

Dog::~Dog() {
  delete _brain;
  std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const {
  std::cout << "Waf Waf !\n";
}

Brain* Dog::getBrain() const {
  return _brain;
}
