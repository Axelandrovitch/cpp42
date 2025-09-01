#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}
PhoneBook::~PhoneBook() {}
PhoneBook::PhoneBook(const PhoneBook& other) { *this = other; }
PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
    if (this != &other) {
        this->_count = other._count;
        this->_oldest = other._oldest;
        for (int i = 0; i < 8; i++)
            this->_contacts[i] = other._contacts[i];
    }
    return *this;
}

static std::string truncateField(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::addContact() {
    std::string input;
    Contact newContact;

    std::cout << "First name: ";
    std::getline(std::cin, input);
    while (!newContact.setName(input)) {
        std::cout << "Invalid. Retry: ";
        std::getline(std::cin, input);
    }

    std::cout << "Last name: ";
    std::getline(std::cin, input);
    while (!newContact.setLastName(input)) {
        std::cout << "Invalid. Retry: ";
        std::getline(std::cin, input);
    }

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    while (!newContact.setNickName(input)) {
        std::cout << "Invalid. Retry: ";
        std::getline(std::cin, input);
    }

    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    while (!newContact.setPhoneNumber(input)) {
        std::cout << "Invalid. Retry: ";
        std::getline(std::cin, input);
    }

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    while (!newContact.setDarkestSecret(input)) {
        std::cout << "Invalid. Retry: ";
        std::getline(std::cin, input);
    }

    if (_count < 8) {
        _contacts[_count] = newContact;
        _count++;
    } else {
        _contacts[_oldest] = newContact;
        _oldest = (_oldest + 1) % 8;
    }
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < _count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateField(_contacts[i].getName()) << "|"
                  << std::setw(10) << truncateField(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateField(_contacts[i].getNickName()) << std::endl;
    }
}

void PhoneBook::searchContact() const {
    if (_count == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    displayContacts();

    std::cout << "Enter index: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = std::atoi(input.c_str());
    if (index < 0 || index >= _count) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout << "First name: " << _contacts[index].getName() << std::endl;
    std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
    std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

