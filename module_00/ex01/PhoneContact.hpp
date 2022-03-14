//
// Created by Hyeonsong Kim on 3/9/22.
//

#ifndef PHONECONTACT_HPP
#define PHONECONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

using std::string;

class PhoneContact {
public:
    PhoneContact(void);
    ~PhoneContact(void);

    void    setContact(void);
    void    setFirstName(void);
    string  getFirstName(void);
    void    setLastName(void);
    string  getLastName(void);
    void    setNickname(void);
    string  getNickname(void);
    void    setPhoneNumber(void);
    string  getPhoneNumber(void);
    void    setDarkestSecret(void);
    string  getDarkestSecret(void);

private:
    string  mFirstName;
    string  mLastName;
    string  mNickname;
    string  mPhoneNumber;
    string  mDarkestSecret;
};

#endif //PHONECONTACT_HPP
