#include <cstddef>
#include <iostream>
#include <iomanip>

#include "iter.h"

template<typename T>  // template function for test
void print(const T& t) {
  std::cout << std::fixed << std::setprecision(1) << t << std::endl;
}

int main(int argc, char* argv[]) {
  iter(argv, argc, print);

  // char carr[] = {'a', 'b', 'c', 'd'};
  // int iarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // float farr[] = {1.0f, 2.0f, 3.0f, 4.0f};
  // double darr[] = {5.0, 6.0, 7.0, 8.0};

  // iter(carr, sizeof(carr), print);
  // iter(iarr, sizeof(iarr) / sizeof(int), print);
  // iter(farr, sizeof(farr) / sizeof(float), print);
  // iter(darr, sizeof(darr) / sizeof(double), print);

  return 0;
}
