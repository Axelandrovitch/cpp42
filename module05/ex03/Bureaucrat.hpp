#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int	            	_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string getName()	const;
		int getGrade()	const;

    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };

		void incrementGrade();
		void decrementGrade();
    void signForm(AForm &f);
    void executeForm(AForm &f) const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &b);

#endif
