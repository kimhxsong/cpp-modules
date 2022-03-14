#include <new>
#include <string>
#include <iostream>

int	main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout \
		<< "\n===The Address in momory of the string====\n"
		<< "stringORG: " << &str << std::endl 
		<< "stringPTR: " << stringPTR << std::endl
		<< "stringREF: " << &stringREF << std::endl;
	
	std::cout \
		<< "\n===Display the string=====================\n"
		<< "stringORG: " << str << std::endl 
		<< "stringPTR: " << *stringPTR << std::endl
		<< "stringREF: " << stringREF << "\n\n";
}