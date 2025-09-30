#include "FragTrap.hpp"

int main() {
    FragTrap frag("Fraggy");
    
    frag.attack("Target1");
    frag.takeDamage(20);
    frag.beRepaired(15);
    
    frag.highFivesGuys();
    
    FragTrap fragCopy(frag);
    fragCopy.attack("Target2");
    
    FragTrap fragAssign("Temp");
    fragAssign = frag;
    fragAssign.highFivesGuys();
    
    return 0;
}
