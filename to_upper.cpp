#include <iostream>

int main(int argc, char *argv[]) {
  constexpr uint16_t dist_between_regs =
      static_cast<int>('a') - static_cast<int>('A');
  constexpr unsigned SIZE = 256;
  char mass[SIZE] = "";

  std::cout << "Enter the string: ";
  std::cin >> mass;

  for (size_t i = 0; mass[i] != '\0'; ++i) {
    if ((mass[i] >= 'a') && (mass[i] <= 'z'))
      mass[i] -= dist_between_regs;
  }
  std::cout << "Edited string: " << mass;
  return 0;
}