#include "ClapTrap.hpp"

int main(void) {

  ClapTrap trapTrap("traptrap");
  ClapTrap copyTrapTrap(trapTrap);
  ClapTrap assignementOperatorTraptrap("AssigmentOperatorTrapTrap");
  ClapTrap loopyTrapTrap("loopyTrapTrap");
  assignementOperatorTraptrap = trapTrap;

  trapTrap.attack("otherTrapTrap");
  trapTrap.takeDamage(5);
  trapTrap.beRepaired(10);
  trapTrap.takeDamage(20);
  std::cout << "\n";

  copyTrapTrap.attack("otherTrapTrap");
  copyTrapTrap.takeDamage(5);
  copyTrapTrap.beRepaired(10);
  copyTrapTrap.takeDamage(20);
  std::cout << "\n";

  assignementOperatorTraptrap.attack("otherTrapTrap");
  assignementOperatorTraptrap.takeDamage(5);
  assignementOperatorTraptrap.beRepaired(10);
  assignementOperatorTraptrap.takeDamage(20);
  std::cout << "\n";

  for (int i = 10; i > 0; i--) {
  loopyTrapTrap.attack("otherTrapTrap");
  loopyTrapTrap.beRepaired(10);
  std::cout << "\n";
  }
  return 0;
}
