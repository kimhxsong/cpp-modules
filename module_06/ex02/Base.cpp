#include "Base.h"

#include <random>

#include "A.h"
#include "B.h"
#include "C.h"


// 타입에 대한 uintptr_t를 만들어.

// 동적배열에 새로만듬.기반클래스 파생클래스

// static const Base* DerivedClassTable[] = {&sA, &sB, &sC};

Base::~Base() {}

Base* generate() {
  Base* randomInstance = dynamic_cast<Base*>(new Base);
  return randomInstance;
}

void identify(Base* p);
void identify(Base& p);
