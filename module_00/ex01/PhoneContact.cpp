//
// Created by Hyeonsong Kim on 3/9/22.
//
#include <iostream>
#include "PhoneContact.hpp"

PhoneContact::PhoneContact(void)
    : mFirstName()
    , mLastName()
    , mNickname()
    , mPhoneNumber()
    , mDarkestSecret()
{};

PhoneContact::~PhoneContact(void) {};

void    PhoneContact::setFirstName(void)
{
    std::cout << "First Name: ";
    std::getline(std::cin, mFirstName);
    if (std::cin.eof()) {
        std::cout << "EOF\n";
        std::exit(0);
    }
}

std::string  PhoneContact::getFirstName(void)
{
  return (mFirstName);
}

void    PhoneContact::setLastName(void)
{
    std::cout << "Last Name: ";
    std::getline(std::cin, mLastName);
    if (std::cin.eof()) {
        std::cout << "EOF\n";
        std::exit(0);
    }
}

std::string  PhoneContact::getLastName(void)
{
  return (mLastName);
}

void    PhoneContact::setNickname(void)
{
    std::cout << "Nickname: ";
    std::getline(std::cin, mNickname);
    if (std::cin.eof()) {
        std::cout << "EOF\n";
        std::exit(0);
    }
}

std::string  PhoneContact::getNickname(void)
{
  return (mNickname);
}

void    PhoneContact::setPhoneNumber(void)
{
    std::cout << "Phone Number: ";
    std::getline(std::cin, mPhoneNumber);
    if (std::cin.eof()) {
        std::cout << "EOF\n";
        std::exit(0);
    }
}

std::string PhoneContact::getPhoneNumber(void)
{
  return (mPhoneNumber);
}

void    PhoneContact::setDarkestSecret(void)
{
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, mDarkestSecret);
    if (std::cin.eof()) {
        std::cout << "EOF\n";
        std::exit(0);
    }
}

std::string PhoneContact::getDarkestSecret(void)
{
  return (mDarkestSecret);
}


void    PhoneContact::setContact(void)
{
  setFirstName();
  setLastName();
  setNickname();
  setPhoneNumber();
  setDarkestSecret();
}
