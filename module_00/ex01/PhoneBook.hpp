#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "PhoneContact.hpp"

class PhoneBook {
 public:
  PhoneBook();
  ~PhoneBook();

  void  setContacts();
  void  exitProgram();
  void  runCommand(const string &userInput);
  void  runProgram();
  void  searchContact();
  void  printContact();
  void  displayContactTable();

 private:
  void  displayContactTableField(string field_string);
  void  displayContactTableRow(int index, PhoneContact &contact);
  void  displayContactTableHeader();

  PhoneContact contacts_[8];
  int index_;
  int amount_;
  int is_exited_;
};

#endif  // PHONEBOOK_HPP
