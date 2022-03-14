#include <iostream>
#include <string>
#include "Karen.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		if (argc == 1) {
			std::cout << "too few arguments\n";
		} else {
			std::cout << "too many arguments\n";
		}
		return (0);
	}
	std::string	logLevel = argv[1];
	Karen		karen;
	karen.filter(logLevel);
	return (0);
}