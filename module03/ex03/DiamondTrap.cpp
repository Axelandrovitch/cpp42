#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name):
  ClapTrap(name + "ClapTrapName"),
  ScavTrap(name),
  FragTrap(name),
  _name(name)
{
  _hitPoints = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;

  std::cout << "DiamondTrap " << _name << " constructed!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
  ClapTrap(other),
  ScavTrap(other),
  FragTrap(other),
  _name(other._name)
{
  std::cout << "DiamondTrap " << _name << " copy constructed!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    ScavTrap::operator=(other);
    FragTrap::operator=(other);
    _name = other._name;
  }
  std::cout << "DiamondTrap " << _name << " assigned!\n";
  return *this;
}

DiamondTrap::~DiamondTrap(){
  std::cout << "DiamondTrap " << _name << " destroyed!\n";
}

void DiamondTrap::WhoAmI() {
  std::cout << "My name is " << _name << "\n"
    << "And my ClapTrap name is " << ClapTrap::_name << "\n";
}

