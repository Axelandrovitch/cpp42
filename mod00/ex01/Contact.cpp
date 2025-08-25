#include "Contact.hpp"
#include <iostream>

bool Contact::setName(const std::string& name){
  if (name.empty())
    return false;

  this->name = name;

  return true;
}

bool Contact::setLastName(const std::string& lastName){
  if (lastName.empty())
    return false;

  this->lastName= lastName;

  return true;
}

bool Contact::setNickName(const std::string& nickName){
  if (nickName.empty())
    return false;

  this->nickName = nickName;

  return true;
}

bool Contact::setDarkestSecret(const std::string& darkestSecret){
  if (darkestSecret.empty())
    return false;

  this->darkestSecret= darkestSecret;

  return true;
}

bool Contact::setPhoneNumber(const std::string& phoneNumber){
  if (phoneNumber.empty())
    return false;
  for (size_t i = 0; i < phoneNumber.length(); ++i) {
    char c = phoneNumber[i];
    if (!std::isdigit(c)) {
      std::cout << "Invalid phone number: digits only" << std::endl;
      return false;
    }
  }
  this->phoneNumber = phoneNumber;

  return true;
}

std::string Contact::getName() { return this->name;}
std::string Contact::getLastName() {return this->lastName;}
std::string Contact::getNickName() {return this->nickName;}
std::string Contact::getDarkestSecret() {return this->darkestSecret;}
std::string Contact::getPhoneNumber() {return this->phoneNumber;}
