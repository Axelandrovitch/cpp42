#include <iostream>

int main(void) {

  std::string brain = "HI THIS IS BRAIN";
  std::string* stringPTR = &brain;
  std::string& stringREF = brain;

  std::cout << "Memory address of the string variable: " << &brain << std::endl;
  std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
  
  std::cout << "Value of brain string variable: " << brain << std::endl;
  std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value of stringREF: " << stringREF << std::endl;

  return 0;
}
