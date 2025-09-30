#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap(const std::string& name):
  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed with Default Constructor\n";
  }

ClapTrap::ClapTrap(const ClapTrap &other):
  _name(other._name),
  _hitPoints(other._hitPoints),
  _energyPoints(other._energyPoints),
  _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap " << _name << " constructed with Copy Constructor\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other)
  {
    this->_name = other.getname();
    this->_hitPoints = other.gethitPoints();
    this->_energyPoints = other.getenergyPoints();
    this->_attackDamage = other.getattackDamage();
  }
  std::cout << "ClapTrap " << _name << " constructed with Assigment Operator\n";
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target) {
  if (_energyPoints <= 0 ) {
    std::cout << "ClapTrap " << _name << "has no energy left and can't attack!\n";
    return;
  }
  if (_hitPoints <= 0 ) {
    std::cout << "ClapTrap " << _name << "is dead and can't attack!\n";
    return;
  }
  std::cout << "ClapTrap " << _name << " attacks "
    << target << ", causing " << _attackDamage
    << " points of damage!\n";
  _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (amount <= 0) {
    std::cout << "Cannot damage with non positive value\n";
    return;
  }

  if (_hitPoints < amount) {
    _hitPoints = 0;
  } else {
    _hitPoints-=amount;
  }
  std::cout << "ClapTrap " << _name << " takes " << amount
    << " of damage!\nRemaining hit points " << _hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints <= 0 ) {
    std::cout << "ClapTrap " << _name << "has no energy left and can't be repaired!\n";
    return;
  }
  if (_hitPoints <= 0 ) {
    std::cout << "ClapTrap " << _name << "is dead and can't be repaired!\n";
    return;
  }
  if (amount <= 0) {
    std::cout << "Cannot repair with non positive value\n";
    return;
  }

  _energyPoints--;

  if (_hitPoints > UINT_MAX - amount) {
    _hitPoints = UINT_MAX;
  } else {
    _hitPoints+=amount;
  }
  std::cout << "ClapTrap " << _name << " gets repaired for "
    << amount << "\nRemaining hit points " << _hitPoints << "\n";
}

std::string  ClapTrap::getname(void) const { return _name; }
unsigned int ClapTrap::gethitPoints(void) const { return _hitPoints; }
unsigned int ClapTrap::getenergyPoints(void) const { return _energyPoints; }
unsigned int ClapTrap::getattackDamage(void) const { return _attackDamage; }

