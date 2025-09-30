#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap " << _name << " constructed with Default Constructor\n";
}

FragTrap::FragTrap(const FragTrap&other) : ClapTrap(other) {
    std::cout << "FragTrap " << _name << " constructed with Copy Constructor\n";
}

FragTrap &FragTrap::operator=(const FragTrap&other) {
  if (this != &other)
  {
    this->_name = other.getname();
    this->_hitPoints = other.gethitPoints();
    this->_energyPoints = other.getenergyPoints();
    this->_attackDamage = other.getattackDamage();
  }
  std::cout << "FragTrap " << _name << " assigned with Assigment Operator\n";
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor called\n";
}

void FragTrap::highFivesGuys(void) {
  std::cout << "High Five Guys!\n";
}
