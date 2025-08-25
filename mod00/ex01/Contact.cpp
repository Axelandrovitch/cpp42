#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}
Contact::Contact(const Contact& other) { *this = other; }
Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        this->name = other.name;
        this->lastName = other.lastName;
        this->nickName = other.nickName;
        this->darkestSecret = other.darkestSecret;
        this->phoneNumber = other.phoneNumber;
    }
    return *this;
}

bool Contact::setName(const std::string& name) {
    if (name.empty()) return false;
    this->name = name;
    return true;
}

bool Contact::setLastName(const std::string& lastName) {
    if (lastName.empty()) return false;
    this->lastName = lastName;
    return true;
}

bool Contact::setNickName(const std::string& nickName) {
    if (nickName.empty()) return false;
    this->nickName = nickName;
    return true;
}

bool Contact::setDarkestSecret(const std::string& darkestSecret) {
    if (darkestSecret.empty()) return false;
    this->darkestSecret = darkestSecret;
    return true;
}

bool Contact::setPhoneNumber(const std::string& phoneNumber) {
    if (phoneNumber.empty()) return false;
    this->phoneNumber = phoneNumber;
    return true;
}

std::string Contact::getName() const { return this->name; }
std::string Contact::getLastName() const { return this->lastName; }
std::string Contact::getNickName() const { return this->nickName; }
std::string Contact::getDarkestSecret() const { return this->darkestSecret; }
std::string Contact::getPhoneNumber() const { return this->phoneNumber; }

