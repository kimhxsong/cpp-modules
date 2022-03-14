#include <iostream>
#include <string>
#include "Karen.hpp"

Karen::Karen(void) {
	mTable[DEBUG].level = "DEBUG";
	mTable[DEBUG].fn = &Karen::debug;
	mTable[INFO].level = "INFO";
	mTable[INFO].fn = &Karen::info;
	mTable[WARNING].level = "WARNING";
	mTable[WARNING].fn = &Karen::warning;
	mTable[ERROR].level = "ERROR";
	mTable[ERROR].fn = &Karen::error;
}

Karen::~Karen(void) {}

void	Karen::complain(std::string level)
{
	for (size_t index = 0; index < 4; ++index) {
		if (level == mTable[index].level) {
			(this->*mTable[index].fn)();
			return ;
		}
	}	
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}

void	Karen::debug(void)
{
	std::cout
		<< "[ DEBUG ]\n"
		<< "I love to get extra bacon for my 7XL-double-cheese"
		<< "-triple-pickle-special-ketchup burger. I just love it!\n";
}

void	Karen::info(void)
{
	std::cout
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon cost more money."
		<< "You don’t put enough! If you did I would not have to ask for it!\n";
}

void	Karen::warning(void)
{
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free."
		<< "I’ve been coming here for years and you just started working here"
		<< "last month.\n";
}

void	Karen::error(void)
{
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now.\n";
}
