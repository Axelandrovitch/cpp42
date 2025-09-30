#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap " << _name << " constructed with Default Constructor\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap " << _name << " constructed with Copy Constructor\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other)
  {
    this->_name = other.getname();
    this->_hitPoints = other.gethitPoints();
    this->_energyPoints = other.getenergyPoints();
    this->_attackDamage = other.getattackDamage();
  }
  std::cout << "ScavTrap " << _name << " constructed with Assigment Operator\n";
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string& target) {
  if (_energyPoints <= 0 ) {
    std::cout << "ScavTrap " << _name << " has no energy left and can't attack!\n";
    return;
  }
  if (_hitPoints <= 0 ) {
    std::cout << "ScavTrap " << _name << " is dead and can't attack!\n";
    return;
  }
  std::cout << "ScavTrap " << _name << " attacks "
    << target << ", causing " << _attackDamage
    << " points of damage!\n";
  _energyPoints--;
}

void ScavTrap::guardGate() {
  if (_hitPoints <= 0) {
    std::cout << "ScavTrap " << _name << " is dead and can't enter Gate keeper mode\n";
    return;
  }
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode\n";
}
