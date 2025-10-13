#ifndef AFORM_HPP
#define AFORM_HPP
#define DEFAULTGRADE 150

#include <iostream>
class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool              _formSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    const std::string _target;

  protected:
    virtual void executeAction() const = 0;
  public:
    AForm();
    AForm(const std::string name, const int gradeToSign, const int gradeToExecute, const std::string target);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

		const std::string getName()	const;
		int getGradeToSign()	const;
		int getGradeToExecute()	const;
    bool getFormSignedFlag() const;
    const std::string getTarget() const;

    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
      public:
        const char *what() const throw();
    };

    void beSigned(Bureaucrat &b);
    void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, AForm &f);

#endif
