#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <string>

#include "PhoneContact.hpp"

using std::string;

PhoneBook::PhoneBook()
  : contacts_(),
    index_(),
    amount_(),
    is_exited_() {}

PhoneBook::~PhoneBook() {}

void PhoneBook::displayContactTableField(string field_string) {
  std::string sub_string = field_string.substr(0, 10);
  if (sub_string.length() == 10) {
    sub_string.erase(sub_string.begin()+9);
    sub_string.push_back('.');
  }
  std::cout << std::setw(10) << sub_string;
  sub_string.clear();
}

void PhoneBook::displayContactTableRow(int index, PhoneContact &contact) {
  std::cout << '|' << std::setw(10) << index;
  std::cout << '|';
  displayContactTableField(contact.getFirstName());
  std::cout << '|';
  displayContactTableField(contact.getLastName());
  std::cout << '|';
  displayContactTableField(contact.getNickname());
  std::cout << "|\n";
}

void PhoneBook::displayContactTableHeader() {
  std::cout << "+----------+----------+----------+----------+\n"
            << "|Index     |First Name|Last Name |Nickname  |\n"
            << "+----------+----------+----------+----------+\n";
}

void PhoneBook::displayContactTable() {
  displayContactTableHeader();
  for (int i = 0; i < amount_; ++i) {
    displayContactTableRow(i, contacts_[i]);
    std::cout << "+----------+----------+----------+----------+\n";
  }
}

void PhoneBook::setContacts() {
  PhoneContact& contact = contacts_[index_];
  contact.setFirstName();
  contact.setLastName();
  contact.setNickname();
  contact.setPhoneNumber();
  contact.setDarkestSecret();
  index_ = (index_ + 1) % 8;
  if (amount_ != 8) {
    amount_ += 1;
  }
}

void PhoneBook::searchContact() {
  displayContactTable();
  std::cout << "Enter the index you are looking for: ";
  int index;
  std::cin.clear();
  std::cin >> index;
  if (std::cin.eof()) {
      std::cout << "EOF\n";
      std::exit(0);
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (std::cin.fail()) {
    std::cout << "Error: invalid input for integer\n";
  } else if (index >= amount_ || index < 0) {
    std::cout << "Error: invalid index\n";
  } else {
    std::cout << "First Name: " <<
                  contacts_[index].getFirstName() << '\n';
    std::cout << "Last Name: " <<
                  contacts_[index].getLastName() << '\n';
    std::cout << "Nickname: " <<
                  contacts_[index].getNickname() << '\n';
    std::cout << "Phone Number: " <<
                  contacts_[index].getPhoneNumber() << '\n';
    std::cout << "Darkest Secret: " <<
                  contacts_[index].getDarkestSecret() << '\n';
  }
}

void PhoneBook::exitProgram() {
  std::cout << "EXIT the program.\n";
}

void PhoneBook::runCommand(const string &user_input) {
  if (user_input == "EXIT") {
    is_exited_ = true;
  } else if (user_input == "ADD") {
    setContacts();
  } else if (user_input == "SEARCH") {
    searchContact();
  } else {
    std::cout << "Error: command not found: " << user_input << "\n"
              << "Usage: ADD | SEARCH | EXIT\n";
  }
}

void PhoneBook::runProgram() {
  std::cout << "The program starts...\n"
            << "Usage: ADD | SEARCH | EXIT\n";
  for (;;) {
    string  user_input;
    std::cout << "> ";
    std::cin.clear();
    std::getline(std::cin, user_input);
    if (std::cin.eof()) {
      std::cout << "EOF\n";
      std::exit(0);
    }
    if (user_input.empty()) {
      continue;
    }
    runCommand(user_input);
    if (is_exited_ == true) {
      break;
    }
  }
  exitProgram();
}
