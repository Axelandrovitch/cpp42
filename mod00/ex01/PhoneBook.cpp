#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
  std::cout << "PhoneBook created" << std::endl;
  return ;
}

PhoneBook::~PhoneBook(void){
  std::cout << "PhoneBook destroyed" << std::endl;
  return ;
}

void PhoneBook::WhatAmI(void){
  std::cout << "I am an instance of a PhoneBook... So sad :(" << std::endl;
  return ;
}
