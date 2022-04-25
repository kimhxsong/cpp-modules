#include <iostream>
#include <iomanip>
#include <list>

#include "MutantStack.h"

void basic_test() {
  std::cout << "TEST-1: MSTACK" << std::endl;
  
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << "Top : " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Size : " << mstack.size() << std::endl;

  for (size_t i = 0; i < 10; ++i) { mstack.push(i); }

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  for (; it != ite; ++it) {
    std::cout << *it << std::endl;
  }
  std::stack<int> s(mstack);
}

void	list_test()
{
  std::cout << "TEST-2: REPLACE WITH STD::LIST" << std::endl;
  std::list<int> li;

  li.push_back(5);
  li.push_back(17);

  std::cout << "Top : " << li.back() << std::endl;
  li.pop_back();
  std::cout << "Size : " << li.size() << std::endl;

  for (size_t i = 0; i < 10; ++i) {
    li.push_back(i);
  }

  std::list<int>::iterator it = li.begin();
  std::list<int>::iterator ite = li.end();

  ++it;
  --it;
  for(; it != ite; ++it) {
    std::cout << *it << std::endl;
  }
  std::list<int> li2(li);
}

void	const_iterator_test()
{
  std::cout << "TEST-3: CONST ITERATOR" << std::endl;
  MutantStack<int> ms;
  for (int i = 0; i < 10; ++i) { ms.push(i); }
  MutantStack<int>::const_iterator cit = ms.begin();
  MutantStack<int>::const_iterator cite = ms.end();
  for (; cit != cite; ++cit) {
    std::cout << *cit << " ";
    // (*cit)++; COMPILE ERROR
  }
  std::cout << std::endl;
}

void reverse_iterator_test() {
  std::cout << "TEST-4: REVERSE ITERATOR" << std::endl;
  
  MutantStack<int> ms;

  for (int i = 0; i < 10; ++i) { ms.push(i); }

  MutantStack<int>::reverse_iterator it = ms.rbegin();
  MutantStack<int>::reverse_iterator ite = ms.rend();

  for (; it != ite; ++it) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;
}

int main() {
  basic_test();
  list_test();
  const_iterator_test();
  reverse_iterator_test();
  return (0);
}
