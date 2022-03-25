#include "PhoneContact.hpp"

#include <iostream>

PhoneContact::PhoneContact()
  : first_name_(),
    last_name_(),
    nickname_(),
    phone_number_(),
    darkest_secret_() {}

PhoneContact::~PhoneContact() {}

std::string PhoneContact::getFirstName() {
  return first_name_;
}

std::string PhoneContact::getLastName() {
  return last_name_;
}

std::string  PhoneContact::getNickname() {
  return nickname_;
}

void PhoneContact::setFirstName() {
  std::cout << "First Name: ";
  std::getline(std::cin, first_name_);
  if (std::cin.eof()) {
    std::cout << "EOF\n";
    std::exit(0);
  }
}

void PhoneContact::setLastName() {
  std::cout << "Last Name: ";
  std::getline(std::cin, last_name_);
  if (std::cin.eof()) {
    std::cout << "EOF\n";
    std::exit(0);
  }
}

std::string PhoneContact::getPhoneNumber() {
  return phone_number_;
}

std::string PhoneContact::getDarkestSecret() {
  return darkest_secret_;
}

void PhoneContact::setNickname() {
  std::cout << "Nickname: ";
  std::getline(std::cin, nickname_);
  if (std::cin.eof()) {
    std::cout << "EOF\n";
    std::exit(0);
  }
}

void PhoneContact::setPhoneNumber() {
  std::cout << "Phone Number: ";
  std::getline(std::cin, phone_number_);
  if (std::cin.eof()) {
    std::cout << "EOF\n";
    std::exit(0);
  }
}

void PhoneContact::setDarkestSecret() {
  std::cout << "Darkest Secret: ";
  std::getline(std::cin, darkest_secret_);
  if (std::cin.eof()) {
    std::cout << "EOF\n";
    std::exit(0);
  }
}
