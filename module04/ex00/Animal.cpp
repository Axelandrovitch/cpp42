#include "Animal.hpp"

Animal::Animal(): _type("Animal") {
  std::cout << "Animal default constructor called\n";
};

Animal::Animal(const Animal& other) : _type(other._type) {
  std::cout << "Animal copy constructor\n";
}

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    _type = other._type;
  }
  std::cout << "Animal assignement operator called\n";
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructor called\n";
};

std::string Animal::getType() const {
  return _type;
}

void Animal::makeSound() const {
  std::cout << "*Animal sound\n";
}
