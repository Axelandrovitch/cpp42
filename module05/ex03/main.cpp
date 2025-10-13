#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "=== TEST 1: robotomy request ===" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    }
    
    std::cout << "\n=== TEST 2: shrubbery creation ===" << std::endl;
    {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("shrubbery creation", "home");
        
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    
    std::cout << "\n=== TEST 3: presidential pardon ===" << std::endl;
    {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("presidential pardon", "Jean Bob");
        
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    
    std::cout << "\n=== TEST 4: Inexistant Form===" << std::endl;
    {
        Intern intern;
        AForm* form = NULL;
        
        try {
            form = intern.makeForm("unknown form", "target");
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        if (form) {
            delete form;
        }
    }
    
    std::cout << "\n=== TEST 5: Signature and execution ===" << std::endl;
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* form = NULL;
        
        try {
            form = intern.makeForm("robotomy request", "Employee");
            
            if (form) {
                std::cout << *form << std::endl;
                boss.signForm(*form);
                boss.executeForm(*form);
                boss.executeForm(*form); // Tester le random 50%
                delete form;
            }
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
            if (form) {
                delete form;
            }
        }
    }
    
    {
        Intern intern;
        AForm* forms[3];
        
        try {
            forms[0] = intern.makeForm("shrubbery creation", "garden");
            forms[1] = intern.makeForm("robotomy request", "Bob");
            forms[2] = intern.makeForm("presidential pardon", "Criminal");
            
            for (int i = 0; i < 3; i++) {
                if (forms[i]) {
                    std::cout << *forms[i] << std::endl;
                    delete forms[i];
                }
            }
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
