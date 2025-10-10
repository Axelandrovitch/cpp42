#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat bobby("Bobby", 151);
        std::cout << bobby << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    try {
        Bureaucrat bobbynator("bobbynator", 0);
        std::cout << bobbynator << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error" << e.what() << std::endl;
    }

    try {
        Bureaucrat bobbynette("bobbynette", 2);
        std::cout << bobbynette << std::endl;

        bobbynette.incrementGrade();
        std::cout << "After increment: " << bobbynette << std::endl;

        bobbynette.incrementGrade();
        std::cout << "After increment: " << bobbynette << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    try {
        Bureaucrat dave("Dave", 149);
        std::cout << dave << std::endl;

        dave.decrementGrade();
        std::cout << "After decrement: " << dave << std::endl;

        dave.decrementGrade();
        std::cout << "After decrement: " << dave << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

