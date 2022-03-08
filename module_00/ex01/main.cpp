#include <iostream>
#include <string>

using std::string;

//PHONECONTACT
class PhoneContact
{
public:
    PhoneContact(void) {};
    ~PhoneContact(void) {};

private:
};

// PHONEBOOK
class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);
    string  getInput(void);
    void    setInput(void);
    void    runPrompt(void);
    bool    findCommand(void);
    void    exit(void);
    void    addContact(void);
    void    searchContact(void);

private:
    string  mInput;
    int     mIndex;
    void    (PhoneBook::*fn)(void);
};

PhoneBook::PhoneBook(void)
    : mInput(0)
    , mIndex(0)
{
    fn = NULL;
}

PhoneBook::~PhoneBook(void) {};

string PhoneBook::getInput() {
    if (mInput.empty() == true)
        return ("NULL");
    return (mInput);
}

void PhoneBook::setInput(void) {
    std::getline(std::cin, mInput);
    if (mInput.empty() == true) {
        std::cout << "input is empty\n";
    }
}

static const (PhoneBook::*fn)[] = {
    PhoenBook::exit,
    PhoneBook::addContact,
    PhoneBook::searchContact
};

bool    PhoneBook::findCommand(void) {
   const char  *cInput = mInput.c_str();

    if (std::strcmp("EXIT", cInput) == 0)
        this->fn = PhoneBook::exit();
    else if (std::strcmp("ADD", cInput) == 0)    
        this->fn = PhoneBook::addContact();
    else if (std::strcmp("SEARCH", cInput) == 0)
        this->fn = PhoneBook::searchContact();
    else
    {
        std::cout << mInput << ": command not found\n";
        return (false);
    }
    return (true);
}

void    PhoneBook::runPrompt() {
    std::cout << "Please enter the command...\n";
    setInput();
}

int main(int argc, char *argv[])
{
    (void)argv;
    if (argc != 1)
    {
        std::cerr << "Error: Too many arguments\n";
        return (1);
    }
    return (0);
}