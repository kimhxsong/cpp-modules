#include <cstdint>
#include <iostream>
#include <iomanip>

#include "Data.h"

static std::ios_base::fmtflags getPresetFlags(int type) {
  static const std::ios_base::fmtflags ff1 = std::cout.hex | std::cout.showbase;
  static const std::ios_base::fmtflags ff2 = std::cout.fixed | std::cout.showpoint;
  switch (type) {
    case 1:
      return ff1;
    case 2:
      return ff2;
    default:
      break;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  Data data = {123412345.1234512345, 123412345.1234512345, 10, 'a'};
  uintptr_t raw = serializie(&data);
  Data* p_data = deserialize(raw);

  std::cout.flags(getPresetFlags(1));
  std::cout << std::setw(30) << std::left << "Data Address" << ": " << &data << '\n' <<
               std::setw(30) << std::left << "Serialized uintptr_t" << ": " << raw << '\n' <<
               std::setw(30) << std::left << "Deserialized p_data address" << ": " << p_data << '\n';

  std::cout << '\n';

  std::cout.flags(getPresetFlags(2));
  std::cout << std::setw(30) << std::left << "data.dval" << ": " << data.dval << '\n' <<
               std::setw(30) << std::left << "data.fval" << ": " << data.fval << '\n' <<
               std::setw(30) << std::left << "data.ival" << ": " << data.ival << '\n' <<
               std::setw(30) << std::left << "data.ch" << ": " << data.ch << '\n';

  std::cout << '\n';

  std::cout << std::setw(30) << std::left << "p_data->dval" << ": " << p_data->dval << '\n' <<
               std::setw(30) << std::left << "p_data->fval" << ": " << p_data->fval << '\n' <<
               std::setw(30) << std::left << "p_data->ival" << ": " << p_data->ival << '\n' <<
               std::setw(30) << std::left << "p_data->ch" << ": " << p_data->ch << '\n';
  return 0;
}