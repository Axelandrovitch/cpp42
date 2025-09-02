#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class PhoneBook {
private:
    Contact _contacts[8];
    int _count;
    int _oldest;

public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook(const PhoneBook& other);
    PhoneBook& operator=(const PhoneBook& other);

    void addContact();
    void searchContact() const;
    void displayContacts() const;
};

#endif

