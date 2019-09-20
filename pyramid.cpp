#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  std::cout << "Enter the number of elements" << std::endl;
  uint16_t num;
  std::cin >> num;

  if (num == 0) {
    return 0;
  }

  if (num % 2 == 0) {
    ++num;
  }

  const uint16_t HALF_OF_NUM = num / 2;

  for (int i = 0; i < HALF_OF_NUM; ++i) {
    for (int j = 0; j < HALF_OF_NUM; ++j) {
      if (j >= (HALF_OF_NUM - i)) {
        std::cout << "*";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "*";
    for (int j = HALF_OF_NUM - 1; j >= 0; --j) {
      if (j >= (HALF_OF_NUM - i)) {
        std::cout << "*";
      } else {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < num; ++i) {
    std::cout << "*";
  }
  return 0;
}
