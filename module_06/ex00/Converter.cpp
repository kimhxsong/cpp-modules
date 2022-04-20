#include <cstdint>

#include <iostream>
#include <string>

struct Data {
  double dval;
  float fval;
  int ival;
  char ch;d

};

uintptr_t serializie(Data* ptr) {
  
}

Data* deserialize(uintptr_t ) {

}




int main(int argc, char* argv[]) {
  uintptr_t raw;
  Data data;
  Data* p_data;
  
  raw = serializie(&data);
  p_data = deserialize(raw);
  std::cout << setw(15) << "Data Address: " << &data << '\n';
  std::cout << setw(15) << "Serialized uintptr_t: " << raw << '\n';
  std::cout << setw(15) << "Deserialized p_data address: " << p_data << '\n';
  return 0;
}