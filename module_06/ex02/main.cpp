// #include "Base.h"

#include <cstdint>

#include <typeinfo>
#include <iostream>
#include <new>

// class base {
//   public:
//     virtual ~base() {}
// };

// class derived : public base {};


// void fun(derived *derived) {
//   std::cout << "d\n";
// }

// void fun(base *base) {
//   std::cout << "b\n";
// }

// #include "A.h"
class A {
 public:
  virtual ~A() {}
};

class B : public A {};

int main() {
    A* m3 = new A;
    A* m2 = new A;
    B* m4 = (B*)m3;
    A* m = new B;
    A;
    unsigned long ***mVtable = (unsigned long ***)&m;
    printf("Derived VTABLE: %p\n", **mVtable);
    printf("First entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][0]);
    printf("Second entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][1]);
    printf("Third entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][2]);

    mVtable = (unsigned long ***)&m2;
    printf("Derived VTABLE: %p\n", **mVtable);
    printf("First entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][0]);
    printf("Second entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][1]);
    printf("Third entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][2]);

    mVtable = (unsigned long ***)&m3;
    printf("Derived VTABLE: %p\n", **mVtable);
    printf("First entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][0]);
    printf("Second entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][1]);
    printf("Third entry of Derived VTABLE: %p\n", (void*) mVtable[0][0][2]);

    mVtable = (unsigned long ***)&m4;
    printf("Derived VTABLE: %p\n", **mVtable);
    // printf("Address of FCT: %p\n", (void*) &assignableFct1);
}

