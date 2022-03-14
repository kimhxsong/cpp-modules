//
// Created by Hyeonsong Kim on 3/9/22.
//s
#include <iostream>
#include <iomanip>
#include <string>

#include "PhoneBook.hpp"
#include "PhoneContact.hpp"

using std::string;

PhoneBook::PhoneBook(void)
  : mContacts()
  , mIndex()
  , mAmount()
  , mIsExited()
{};

PhoneBook::~PhoneBook(void) {};

void  PhoneBook::displayContactTableField(string fieldString)
{
  std::string subString = fieldString.substr(0, 10);
  if (subString.length() == 10) {
    subString.pop_back();
    subString.push_back('.');
  }
  std::cout << std::setw(10) << subString;
  subString.clear();
}

void  PhoneBook::displayContactTableRow(size_t index, PhoneContact &contact)
{
  std::cout << '|' << std::setw(10) << index;
  std::cout << '|' ;
  displayContactTableField(contact.getFirstName());
  std::cout << '|' ;
  displayContactTableField(contact.getLastName());
  std::cout << '|' ;
  displayContactTableField(contact.getNickname());
  std::cout << "|\n";
}

void  PhoneBook::displayContactTableHeader(void)
{
  std::cout << "+----------+----------+----------+----------+\n"
            << "|Index     |First Name|Last Name |Nickname  |\n"
            << "+----------+----------+----------+----------+\n";
}

void  PhoneBook::displayContactTable(void)
{
  displayContactTableHeader();
  for(size_t i = 0; i < mAmount; ++i) {
    displayContactTableRow(i, mContacts[i]);
    std::cout << "+----------+----------+----------+----------+\n";
  }
}

void  PhoneBook::addContact(void)
{
  PhoneContact &contact = mContacts[mIndex];

  contact.setContact();
  mIndex = (mIndex + 1) % 8;
  if (mAmount != 8) {
    ++mAmount;
  }
}

void  PhoneBook::searchContact(void)
{
  string userInput;

  displayContactTable();
}

void  PhoneBook::exitProgram(void)
{
  std::cout << "EXIT the program.\n";
}

void  PhoneBook::runCommand(const string &userInput)
{
  if (userInput.compare("EXIT") == 0) {
    mIsExited = true;
  } else if (userInput.compare("ADD") == 0) {
    addContact();
  } else if (userInput.compare("SEARCH") == 0) {
    searchContact();
  } else {
    std::cout << "Error: command not found: " << userInput << std::endl;
  }
}

void  PhoneBook::runProgram(void)
{
  std::cout << "The program starts...\n";
  while (1) {
    string  userInput;
    std::cout << "> ";
    std::getline(std::cin, userInput);
    if (std::cin.eof())
    {
      std::cout << "EOF\n";
      std::exit(0);
    }
    if (userInput.empty()) {
      continue ;
    }
    runCommand(userInput);
    if (mIsExited == true) {
      break ;
    }
  }
  exitProgram();
}
