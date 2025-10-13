#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  : AForm("PresidentialPardonForm", 25, 5, "default")
{
  std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
  : AForm("PresidentialPardonForm", 25, 5, target)
{
  std::cout << "PresidentialPardonForm parametric constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
  : AForm(other)
{
  std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called\n";
}

void PresidentialPardonForm::executeAction() const {
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
