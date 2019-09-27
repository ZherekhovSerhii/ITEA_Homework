#include <iostream>

int main(int argc, char *argv[]) {
  constexpr unsigned SIZE = 256;
  char mass[SIZE] = "";

  std::cout << "Enter the string: ";
  std::cin >> mass;

  std::cout << "Is digit: ";
  for (size_t i = 0; mass[i] != '\0'; ++i) {
    if ((mass[i] >= '0') && (mass[i] <= '9'))
      std::cout << mass[i] << " ";
  }
  return 0;
}