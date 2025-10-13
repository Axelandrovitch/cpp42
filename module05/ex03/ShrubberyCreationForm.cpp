#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("ShrubberyCreationForm", 145, 137, "default")
{
  std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
  : AForm("ShrubberyCreationForm", 145, 137, target)
{
  std::cout << "ShrubberyCreationForm parametric constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
  : AForm(other)
{
  std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::executeAction() const {
  std::string filename = getTarget() + "_shrubbery";
  std::ofstream file(filename.c_str());
  
  if (!file.is_open()) {
    std::cerr << "Error: Could not create file " << filename << std::endl;
    return;
  }
  
  file << "       ###\n";
  file << "      #o###\n";
  file << "    #####o###\n";
  file << "   #o#\\#|#/###\n";
  file << "    ###\\|/#o#\n";
  file << "     # }|{  #\n";
  file << "       }|{\n";
  file << "\n";
  file << "      ccee88oo\n";
  file << "  C8O8O8Q8PoOb o8oo\n";
  file << " dOB69QO8PdUOpugoO9bD\n";
  file << "CgggbU8OU qOp qOdoUOdcb\n";
  file << "    6OuU  /p u gcoUodpP\n";
  file << "      \\\\\\//  /douUP\n";
  file << "        \\\\\\////\n";
  file << "         |||/\\\n";
  file << "         |||\\/\n";
  file << "         |||||\n";
  file << "   .....//||||\\....\n";
  
  file.close();
  std::cout << "Shrubbery has been planted at " << getTarget() << std::endl;
}
