#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== TEST 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 2: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");
        
        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot); // Tester le 50%
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 3: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 4: Grade insuffisant pour signer ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Criminal");
        
        intern.signForm(pardon); // Devrait échouer
        intern.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 5: Grade insuffisant pour executer ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat employee("Employee", 50);
        PresidentialPardonForm pardon("Someone");
        
        boss.signForm(pardon); // Boss peut signer
        employee.executeForm(pardon); // Employee ne peut pas executer (grade 50 > 5)
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 6: Executer sans signer ===" << std::endl;
    try {
        Bureaucrat john("John", 1);
        ShrubberyCreationForm shrub("garden");
        
        john.executeForm(shrub); // Pas signé, devrait échouer
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
