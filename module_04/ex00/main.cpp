#include <iostream>
#include <string>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

// 객체의 타입이 심볼릭 상수일 때, 객체는 바디가 상수인 메서드만 호출가능하다.
int main() {
  const Animal* meta = new Animal();
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete i;
  delete j;
  return 0;
}