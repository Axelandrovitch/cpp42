#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Phonebook" << std::endl;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else if (!command.empty()) {
            std::cout << "Unknown command." << std::endl;
        }
    }
    return 0;
}

