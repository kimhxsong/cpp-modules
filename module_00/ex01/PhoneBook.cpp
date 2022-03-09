//
// Created by Hyeonsong Kim on 3/9/22.
//s
#include <iostream>
#include <string>

#include "PhoneBook.hpp"

using std::string;

PhoneBook::PhoneBook(void)
    : mContacts()
    , mIsExited()
{};

PhoneBook::~PhoneBook(void) {};

void    PhoneBook::addContact(void)
{
    std::cout << "ADD is running...\n";
}

void    PhoneBook::searchContact(void)
{
    std::cout << "SEARCH is running...\n";
}

void    PhoneBook::exitProgram(void)
{
    std::cout << "EXIT the program.\n";
}

void    PhoneBook::runCommand(const string &userInput)
{
    if (userInput.compare("EXIT") == 0) {
        mIsExited = true;
    } else if (userInput.compare("ADD") == 0) {
        this->addContact();
    } else if (userInput.compare("SEARCH") == 0) {
        this->searchContact();
    } else {
        std::cout << "Error: command not found: " << userInput << std::endl;
    }
}

void    PhoneBook::runProgram(void)
{
    std::cout << "The program starts...\n";
    while (1) {
        string  userInput;
        std::cout << "> ";
        std::getline(std::cin, userInput);
        if (userInput.empty()) {
            continue ;
        }
        this->runCommand(userInput);
        if (mIsExited == true) {
            break ;
        }
    }
    this->exitProgram();
}
