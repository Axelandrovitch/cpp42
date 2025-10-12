#ifndef FORM_HPP
#define FORM_HPP
#define DEFAULTGRADE 150

#include <iostream>
class Bureaucrat;

class Form {
  private:
    const std::string _name;
    bool              _formSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;

  public:
    Form();
    Form(const std::string name, const int gradeToSign, const int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

		const std::string getName()	const;
		int getGradeToSign()	const;
		int getGradeToExecute()	const;
    bool getFormSignedFlag() const;

    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };

    void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, Form &f);

#endif
