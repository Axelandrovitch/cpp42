#include <iostream>

class ClapTrap {

  protected:
    std::string   _name;
    unsigned int  _hitPoints;
    unsigned int  _energyPoints;
    unsigned int  _attackDamage;

  public:

    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string  getname(void) const;
    unsigned int gethitPoints(void) const;
    unsigned int getenergyPoints(void) const;
    unsigned int getattackDamage(void) const;
};
