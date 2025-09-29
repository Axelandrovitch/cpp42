#include "ScavTrap.hpp"

int main() {
    std::cout << "=== CONSTRUCTION ===\n";
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavy");
    
    std::cout << "\n=== ATTACK TEST ===\n";
    clap.attack("Target1");
    scav.attack("Target2");
    
    std::cout << "\n=== GUARDGATE TEST ===\n";
    scav.guardGate();
    
    std::cout << "\n=== HITS TEST ===\n";
    clap.takeDamage(5);
    scav.takeDamage(30);
    
    std::cout << "\n=== REPARATION TEST ===\n";
    clap.beRepaired(3);
    scav.beRepaired(10);
    
    std::cout << "\n=== NO ENERGY LEFT TEST ===\n";
    for (int i = 0; i < 11; i++) {
        std::cout << "Attack " << i + 1 << ": ";
        clap.attack("Target");
    }
    
    std::cout << "\n=== DEATH TEST ===\n";
    scav.takeDamage(100);
    scav.attack("Target");
    scav.guardGate();
    
    std::cout << "\n=== COPY TEST===\n";
    ScavTrap scavCopy(scav);
    scavCopy.attack("CopyTarget");
    
    std::cout << "\n=== ASSIGNATION TEST ===\n";
    ScavTrap scavAssign("Temp");
    scavAssign = scav;
    scavAssign.attack("AssignTarget");
    
    std::cout << "\n=== DESTRUCTION ===\n";
    return 0;
}
