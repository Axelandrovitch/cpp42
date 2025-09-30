#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("SuperDiamond");
    
    diamond.attack("Target1");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.WhoAmI();
    
    DiamondTrap diamondCopy(diamond);
    diamondCopy.attack("Target2");
    diamondCopy.WhoAmI();
    
    DiamondTrap diamondAssign("Temp");
    diamondAssign = diamond;
    diamondAssign.attack("Target3");
    diamondAssign.WhoAmI();
    
    return 0;
}
