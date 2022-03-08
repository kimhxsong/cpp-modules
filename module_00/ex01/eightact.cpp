#include <string.h>
#include <iostream>
#include "eightact.hpp"

struct ContactField {
    char first_name[10];
    char last_name[10];
    char nickname[10];
    char phone_number[10];
    char darkest_secret[10];
};

class PhoneBook {
public:
    void  exit(void);
    void  add(void);
    void  search(void);

private:
    uint8_t index;

};
int main(int argc, char *argv[])
{
    std::string contact[8];

    (void)argv;
    if (argc != 1)
        return (1);
    std::string input;

	return (0);
}
