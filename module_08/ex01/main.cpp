#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>

#include "Span.h"

int main() {
  {
    Span sp = Span(5);

    try {
      sp.addNumber(6);
      sp.addNumber(3);
      sp.addNumber(17);
      sp.addNumber(9);
      sp.addNumber(11);
      sp.addNumber(11);
    } catch (const std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::multiset<int>::iterator first = sp.data().begin();
    std::multiset<int>::iterator last = sp.data().end();
    std::cout << *first << '\n';
    std::cout << *--last << '\n';

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }

  {
    Span sp2 = Span(5);

    std::vector<int> v;
    v.push_back(6);
    v.push_back(3);
    v.push_back(17);
    v.push_back(9);
    v.push_back(11);

    sp2.addNumbers(v.begin(), v.end());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
  }

  {
    Span sp3 = Span(10000);
    std::vector<int> v;
    for (size_t i = 0; i < 10000; ++i) {
      v.push_back(i * 4);
    }

    sp3.addNumbers(v.begin(), v.end());
    try {
      sp3.addNumber(40000);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    sp3.resize(10001);
    sp3.addNumber(40000);

    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
  }

  {
    Span sp4;
    try {
      std::cout << sp4.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
  return 0;
}
