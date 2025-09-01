#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}
Contact::Contact(const Contact& other) { *this = other; }
Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_lastName = other._lastName;
        this->_nickName = other._nickName;
        this->_darkestSecret = other._darkestSecret;
        this->_phoneNumber = other._phoneNumber;
    }
    return *this;
}

bool Contact::setName(const std::string& name) {
    if (name.empty())
      return false;
    this->_name = name;
    return true;
}

bool Contact::setLastName(const std::string& lastName) {
    if (lastName.empty())
      return false;
    this->_lastName = lastName;
    return true;
}

bool Contact::setNickName(const std::string& nickName) {
    if (nickName.empty())
      return false;
    this->_nickName = nickName;
    return true;
}

bool Contact::setDarkestSecret(const std::string& darkestSecret) {
    if (darkestSecret.empty())
      return false;
    this->_darkestSecret = darkestSecret;
    return true;
}

bool Contact::setPhoneNumber(const std::string& phoneNumber) {
    if (phoneNumber.empty())
      return false;
    this->_phoneNumber = phoneNumber;
    return true;
}

std::string Contact::getName() const { return this->_name; }
std::string Contact::getLastName() const { return this->_lastName; }
std::string Contact::getNickName() const { return this->_nickName; }
std::string Contact::getDarkestSecret() const { return this->_darkestSecret; }
std::string Contact::getPhoneNumber() const { return this->_phoneNumber; }

