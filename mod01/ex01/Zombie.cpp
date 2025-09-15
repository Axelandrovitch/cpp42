#include "Zombie.hpp"

Zombie::Zombie() : _name("Unnamed") {
    std::cout << "Zombie created (default)." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << _name << " created." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

void Zombie::setName(std::string name) {
    _name = name;
}

void Zombie::announce(void) const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

