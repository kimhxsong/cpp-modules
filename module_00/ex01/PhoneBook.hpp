//
// Created by Hyeonsong Kim on 3/9/22.
//

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "PhoneContact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);
	void  addContact(void);
	void  exitProgram(void);
	void  runCommand(const string &userInput);
	void  runProgram(void);
	void  searchContact(void);
	void  displayContactTable(void);
	void  displayContactTableField(string fieldString);
	void  displayContactTableRow(size_t index, PhoneContact &contact);
	void  displayContactTableHeader(void);

private:
	PhoneContact  mContacts[8];
	size_t        mIndex;
	size_t        mAmount;
	int           mIsExited;
};

#endif //PHONEBOOK_HPP
