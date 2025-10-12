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
        Bureaucrat bobbynator("Bobbynator", 0);
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
        Bureaucrat bobbynow("Bobbynow", 149);
        std::cout << bobbynow<< std::endl;

        bobbynow.decrementGrade();
        std::cout << "After decrement: " << bobbynow << std::endl;

        bobbynow.decrementGrade();
        std::cout << "After decrement: " << bobbynow << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

