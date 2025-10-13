#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
  : _name("NoName"),
    _formSigned(false),
    _gradeToSign(DEFAULTGRADE),
    _gradeToExecute(DEFAULTGRADE),
    _target("NoTarget")
{
      std::cout << "AForm default constructor called\n";
};

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute, const std::string target)
  : _name(name),
    _formSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute),
    _target(target)
{
  std::cout << "AForm parametric constructor called\n";
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException();
  }
};

AForm::AForm(const AForm &other)
  : _name(other._name),
    _formSigned(other._formSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{
  std::cout << "AForm copy constructor called\n";
}

AForm& AForm::operator=(const AForm &other) {
  if (this != &other)
  {
    std::cerr << "Cannot assign AForm (const attributes). "
      << "Returning unmodified object.\n";
  }
  return *this;
} 

AForm::~AForm() {
  std::cout << "AForm destructor called\n";
}

const std::string AForm::getName() const {
  return _name;
}

int AForm::getGradeToSign() const {
  return _gradeToSign;
}

int AForm::getGradeToExecute() const {
  return _gradeToExecute;
}

bool AForm::getFormSignedFlag() const {
  return _formSigned;
}

const std::string AForm::getTarget() const {
  return _target;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

void AForm::beSigned(Bureaucrat &b) {
  if (b.getGrade()  > _gradeToSign) {
    throw GradeTooLowException();
  }
  if (getFormSignedFlag() == false) {
    _formSigned = true;
  }
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!_formSigned) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > _gradeToExecute) {
    throw GradeTooLowException();
  }
  executeAction();
}
std::ostream &operator<<(std::ostream &os, AForm &f) {
  os << f.getName() << ", form grade to sign: " << f.getGradeToSign()
    << " grade to execute: " << f.getGradeToExecute()
    << " form signed: " << f.getFormSignedFlag()
    << " target: " << f.getTarget();
  return os;
}
