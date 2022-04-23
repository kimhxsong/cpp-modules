#include "Base.h"

#include <ctime>
#include <iostream>
#include <random>
#include <exception>

#include "A.h"
#include "B.h"
#include "C.h"

Base::~Base() {}

Base* generate() {
  std::srand(time(NULL));
  int i = std::rand() % 3;
  switch (i) {
    case 0:
      return new A;
    case 1:
      return new B;
    case 2:
      return new C;
    default:
      break;
  }
  return NULL;
}

void identify(Base* p) {
  std::string type_name;
  A *a;
  B *b;
  C *c;

  if (p == NULL) {
    throw std::logic_error("invalid argument");
  }
  if ((a = dynamic_cast<A*>(p)) != NULL) {
    type_name = "A";
  } else if ((b = dynamic_cast<B*>(p)) != NULL) {
    type_name = "B";
  } else if ((c = dynamic_cast<C*>(p)) != NULL) {
    type_name = "C";
  }

  std::cout << "Actual type name: " << type_name << '\n';
}

void identify(Base& p) {
  std::string type_name;

  while (true) {
    try {
      p = dynamic_cast<A&>(p);
      type_name = "A";
      break;
    } catch (const std::bad_cast& e) {}

    try {
      p = dynamic_cast<B&>(p);
      type_name = "B";
      break;
    } catch (const std::bad_cast& e) {}

    try {
      p = dynamic_cast<C&>(p);
      type_name = "C";
      break;
    } catch (const std::bad_cast& e) {}

    throw std::logic_error("invalid argument");
  }

  std::cout << "Actual type name: " << type_name << '\n';
}
