#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
  : _name("NoName"),
    _formSigned(false),
    _gradeToSign(DEFAULTGRADE),
    _gradeToExecute(DEFAULTGRADE)
{
      std::cout << "Form default constructor called\n";
};

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
  : _name(name),
    _formSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
  std::cout << "Form parametric constructor called\n";
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException();
  }
};

Form::Form(const Form &other)
  : _name(other._name),
    _formSigned(other._formSigned),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{
  std::cout << "Form copy constructor called\n";
}

Form& Form::operator=(const Form &other) {
  if (this != &other)
  {
    std::cerr << "Cannot assign Form (const attributes). "
      << "Returning unmodified object.\n";
  }
  return *this;
} 

Form::~Form() {
  std::cout << "Form destructor called\n";
}

const std::string Form::getName() const {
  return _name;
}

int Form::getGradeToSign() const {
  return _gradeToSign;
}

int Form::getGradeToExecute() const {
  return _gradeToExecute;
}

bool Form::getFormSignedFlag() const {
  return _formSigned;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, Form &f) {
  os << f.getName() << ", form grade to sign: " << f.getGradeToSign()
    << " grade to execute: " << f.getGradeToExecute()
    << " form signed: " << f.getFormSignedFlag();
  return os;
}

void Form::beSigned(Bureaucrat &b) {
  if (b.getGrade()  > _gradeToSign) {
    throw GradeTooLowException();
  }
  if (getFormSignedFlag() == false) {
    _formSigned = true;
  }
}
