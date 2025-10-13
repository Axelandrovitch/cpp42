#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
  : AForm("RobotomyRequestForm", 72, 45, "default")
{
  std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
  : AForm("RobotomyRequestForm", 72, 45, target)
{
  std::cout << "RobotomyRequestForm parametric constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
  : AForm(other)
{
  std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called\n";
}

void RobotomyRequestForm::executeAction() const {
  std::cout << "* DRILLING NOISES * BZZZZZZ VRRRRR BZZZZ *" << std::endl;
  
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(0));
    seeded = true;
  }
  
  if (std::rand() % 2 == 0) {
    std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "The robotomy on " << getTarget() << " failed!" << std::endl;
  }
}
