#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern &other) {
  (void)other;
  std::cout << "Intern assignment operator called\n";
  return *this;
}

Intern::~Intern() {
  std::cout << "Intern destructor called\n";
}

AForm* Intern::createShrubbery(const std::string &target) const {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) const {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) const {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
  const std::string formNames[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
  };
  
  AForm* (Intern::*creators[3])(const std::string &) const = {
    &Intern::createShrubbery,
    &Intern::createRobotomy,
    &Intern::createPresidential
  };
  
  for (int i = 0; i < 3; i++) {
    if (formNames[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*creators[i])(target);
    }
  }
  
  std::cerr << "Error: Form \"" << formName << "\" does not exist" << std::endl;
  throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}
