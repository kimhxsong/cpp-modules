#include <iostream>
#include <string>

#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"

int main() {
  {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
  }
  system("leaks a.out");
  return 0;
}