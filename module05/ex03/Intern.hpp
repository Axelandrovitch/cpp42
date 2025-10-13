#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern {
  private:
    // Pointeurs vers fonctions membres pour créer les forms
    AForm* createShrubbery(const std::string &target) const;
    AForm* createRobotomy(const std::string &target) const;
    AForm* createPresidential(const std::string &target) const;

  public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm* makeForm(const std::string &formName, const std::string &target) const;

    class FormNotFoundException : public std::exception {
      public:
        const char *what() const throw();
    };
};

#endif
