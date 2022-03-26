#include <string>
#include <new>

#include "Zombie.hpp"

int main() {
  {
    Zombie zombieOnStack("Stack");
    Zombie *zombieOnHeap = newZombie("Heap");
    zombieOnStack.announce();
    zombieOnHeap->announce();
    {
      randomChump("Block");
    }
    delete zombieOnHeap;
  }
  system("leaks zombie");
  return 0;
}
