#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Tax Form", 100, 50);
        
        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;
        
        bob.signForm(form1);
        std::cout << form1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n---\n" << std::endl;
    
    try {
        Bureaucrat john("John", 150);
        Form form2("Important Document", 50, 25);
        
        std::cout << john << std::endl;
        std::cout << form2 << std::endl;
        
        john.signForm(form2);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n---\n" << std::endl;
    
    try {
        Form invalidForm("Invalid", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
