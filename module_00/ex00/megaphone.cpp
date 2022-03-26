#include <iostream>

void megaphoneSpeak(int size, char *strarr[]) {
  if (size == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return;
  }

  for (int i = 1; i < size; ++i) {
    std::string megaString(strarr[i]);
    const size_t len = megaString.length();
    for (size_t j = 0; j < len; ++j) {
        megaString[j] = std::toupper(megaString[j]);
    }
    std::cout << megaString;
  }
  std::cout << std::endl;
}

#ifndef TEST

int main(int argc, char *argv[]) {
  megaphoneSpeak(argc, argv);
  return 0;
}

#endif
