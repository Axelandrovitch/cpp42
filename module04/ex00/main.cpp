#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "=== ANIMAL TESTS ===\n";
  Animal meta;
  Dog dog;
  Cat cat;

  std::cout << dog.getType() << std::endl;
  std::cout << cat.getType() << std::endl;
  dog.makeSound();
  cat.makeSound();
  meta.makeSound();

  std::cout << "\n=== POLYMORPHISM TESTS ===\n";
  Animal& dogRef = dog;
  Animal& catRef = cat;

  dogRef.makeSound();
  catRef.makeSound();

  std::cout << "\n=== WRONG ANIMAL TESTS ===\n";
  WrongAnimal wrongMeta;
  WrongCat wrongCat;

  std::cout << wrongCat.getType() << std::endl;
  wrongCat.makeSound();
  wrongMeta.makeSound();

  std::cout << "\n=== COPY TESTS ===\n";
  Dog dog2;
  Dog dogCopy(dog2);
  Cat cat2;
  Cat catAssign;
  catAssign = cat2;

  dogCopy.makeSound();
  catAssign.makeSound();

  std::cout << "\n=== DESTRUCTION ===\n";
  return 0;
}
