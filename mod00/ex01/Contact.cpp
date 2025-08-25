#include "Contact.hpp"
#include <iostream>

void Contact::setName(const std::string& name){
  this->name = name;
}

void Contact::setLastName(const std::string& lastName){
  this->lastName= lastName;
}

void Contact::setNickName(const std::string& nickName){
  this->nickName = nickName;
}

void Contact::setDarkestSecret(const std::string& darkestSecret){
  this->darkestSecret= darkestSecret;
}

void Contact::setPhoneNumber(const std::string& phoneNumber){
  this->phoneNumber = phoneNumber;
}

std::string Contact::getName() { return this->name;}
std::string Contact::getLastName() {return this->lastName;}
std::string Contact::getNickName() {return this->nickName;}
std::string Contact::getDarkestSecret() {return this->darkestSecret;}
std::string Contact::getPhoneNumber() {return this->phoneNumber;}
