// #include "Base.h"

#include <iostream>
#include <new>
#include <typeinfo>
#include <iomanip>

class A {
 public:
   ~A() {}
};

class D1 : public A {
  void f() {}
};

class VA {
 public:
  virtual ~VA() {}
  virtual void f() {}
};

class D2 : public VA {};

int main() {
  std::cout.flags(std::ios_base::hex | std::ios_base::showbase);

  {
    // A *a1 = new A;
    // A *a2 = new A;
    // A a3;

    // std::cout << *(unsigned long*)a1 << '\n';
    // std::cout << *(unsigned long*)a2 << '\n';
    // std::cout << *((unsigned long*)&a3) << '\n';

    // std::cout << '\n';

    // D1 *b1 = new D1;
    // D1 b2;

    // std::cout << *(unsigned long*)b1 << '\n';
    // std::cout << *((unsigned long*)&b2) << '\n';

    // std::cout << '\n';

    // D1 *v1 = (D1*)(&a3);
    // // D2 *v2 = dynamic_cast<D2*>(&a3);
    // A *v3 = dynamic_cast<A*>(&b2);

    // std::cout << *(unsigned int*)v1 << '\n';
    // // std::cout << v2 << '\n';
    // std::cout << *(long*)v3 << 'n';
  
  }
  std::cout << '\n';


    VA *a1 = dynamic_cast<VA*>(new VA);
    std::cout << **(long****)a1 << std::endl;

    VA *p = (new D2);
    std::cout << **(long****)p << std::endl;

  //   VA *a2 = new VA;
  //   VA a3;

  //   std::cout << *(unsigned long*)a1 << '\n';
  //   std::cout << *(unsigned long*)a2 << '\n';
  //   std::cout << *((unsigned long*)&a3) << '\n';

  //   std::cout << '\n';

  //   D2 *b1 = new D2;
  //   D2 b2;

  //   std::cout << *(unsigned long*)b1 << '\n';
  //   std::cout << *((unsigned long*)&b2) << '\n';

  //   std::cout << '\n';

  //   VA *a4 = new VA;
  //   D2 *v1 = (D2*)(&a3);
  //   // D2 *v2 = dynamic_cast<D2*>(&a3);
  //   D2 *v4 = static_cast<D2*>(a4);
  //   VA *v3 = dynamic_cast<VA*>(&b2);

  //   std::cout << &v1 << '\n';
  //   std::cout << v4 << '\n';
  //   std::cout << &v3 << '\n';

  //   std::cout << '\n';

  //   a1 = &b2;
  //   void*** RTTI = (void***)&v3;

  //   //RTTI
  //   std::cout << "\nRTTI[0]: " << RTTI[0] << '\n';
  //   std::cout << RTTI[0][0] << "\n";
  //   std::cout << RTTI[0][1] << "\n";
  //   std::cout << RTTI[0][2] << "\n";
  //   std::cout << RTTI[0][3] << "\n";
    
  //   std::cout << RTTI[0][0] << '\n';
  //   std::cout << std::endl;

  //   //vtable;
  //   void ***vtable;

  //   vtable = (void***)RTTI[1];
  //   std::cout << "\nRTTI[0]: " << vtable[0] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][0] << '\n';
  //   std::cout << std::setw(8) << "- " << vtable[0][1] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][2] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][3] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][4] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][5] << "\n\n";

  //   vtable = (void***)RTTI[0][3];
  //   std::cout << "\nRTTI[0][3]: " << vtable[0] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][0] << '\n';
  //   std::cout << std::setw(8) << "- " << vtable[0][1] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][2] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][3] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][4] << "\n";
 
  //   std::cout << std::setw(8) << "- " << vtable[0][5] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][6] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][7] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][8] << "\n";
  //   std::cout << std::setw(8) << "- " << vtable[0][9] << "\n";

  //   std::cout << "\nRTTI[1]: " << RTTI[1] << '\n';
  //   std::cout << RTTI[1][0] << "\n";
  //   std::cout << RTTI[1][1] << "\n";
  //   std::cout << RTTI[1][2] << "\n";
  //   std::cout << RTTI[1][3] << "\n";


  //   std::cout << "\nRTTI[2]: " << RTTI[2] << '\n';
  //   std::cout << RTTI[2][0] << "\n";
  //   std::cout << RTTI[2][1] << "\n";
  //   std::cout << RTTI[2][2] << "\n";
  //   std::cout << RTTI[2][3] << "\n";
  //   std::cout << RTTI[2][4] << "\n";

  //   std::cout << "\nRTTI[3]: " << RTTI[3] << '\n';
  //   std::cout << RTTI[3][0] << "\n";
  //   std::cout << RTTI[3][1] << "\n";

  //   std::cout << "\nRTTI[4]: " << RTTI[4] << '\n';
  //   std::cout << RTTI[4][0] << "\n";
  //   std::cout << RTTI[4][1] << "\n";
  //   std::cout << RTTI[4][2] << "\n";
  //   std::cout << RTTI[4][3] << "\n";
  //   // std::cout << p_rtti[1] << '\n';/
  //   // std::cout << *(unsigned long*)v2 << '\n';
  //   // std::cout << (unsigned long*)v3[0] << '\n';
  // }



  // std::cout.flags(0);
  // std::cout << '\n';

  // std::cout << sizeof(A) << '\n';
  // std::cout << sizeof(D1) << '\n';
  // std::cout << sizeof(VA) << '\n';
  // std::cout << sizeof(D2) << '\n';
  // D2 d;
  // std::cout << std::hex << static typeid(d).hash_code();
}
