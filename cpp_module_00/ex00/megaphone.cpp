#include <iostream>

int		main(int argc, char *argv[])
{
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (1);
    }
    for (int i = 1; i < argc; ++i) {
        std::string megaString(argv[i]);
        const size_t len = megaString.length();
        for (size_t j = 0; j < len; ++j) {
            megaString[j] = std::toupper(megaString[j]);
        }
        std::cout << megaString;
        megaString.clear();
    }
    std::cout << std::endl;
    return (0);
}