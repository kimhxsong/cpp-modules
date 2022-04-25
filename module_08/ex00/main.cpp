#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

#include "easyfind.h"

int main(void) {
  std::deque<int> d;
  std::list<int> l;
  std::vector<int> v;

  for (int i = 0 ; i < 42 ; ++i) {
    d.push_back(i);
    l.push_back(i);
    v.push_back(i);
  }

  try {
    easyfind(d, 42);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    easyfind(d, -1);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << *easyfind(d, 21) << std::endl;
    std::cout << *easyfind(l, 21) << std::endl;
    std::cout << *easyfind(v, 21) << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
