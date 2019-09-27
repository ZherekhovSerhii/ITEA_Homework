#include <iostream>

#define SWAP(a, b)                                                             \
  b += a;                                                                      \
  a = b - a;                                                                   \
  b -= a

int main(int argc, char *argv[]) {
  constexpr uint16_t SIZE = 256;
  char mass[SIZE] = "";

  std::cout << "Enter the string: ";
  std::cin >> mass;

  uint16_t full_size = 0;
  for (; mass[full_size] != '\0';) {
    ++full_size;
  }

  const uint16_t HALF_OF_SIZE = full_size / 2;

  for (uint16_t i = 1; i <= HALF_OF_SIZE; ++i) {
    SWAP(mass[i - 1], mass[full_size - i]);
  }

  std::cout << "Edited string: " << mass;
  return 0;
}