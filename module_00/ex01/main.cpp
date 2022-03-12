#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
  (void)argv;
  if (argc != 1) {
    std::cout << "Error: Too many arguments\n";
    return (1);
  }
  PhoneBook  phoneBook;
  phoneBook.runProgram();
  return (0);
}