#include <iostream>
#include <string>

#include "Harl.hpp"

// harlFilter
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout <<
      "Usage: ./harlFilter [\"DEBUG\" | \"INFO\" | \"WARNING\" | \"ERROR\"]\n";
    return 1;
  }
  const std::string log_level(argv[1]);
  Harl harl;
  harl.filter(log_level);
  return (0);
}
