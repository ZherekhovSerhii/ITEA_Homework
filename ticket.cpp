#include <bitset>
#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  std::cout << "Enter the 6-digit ticket number" << std::endl;
  uint32_t num;
  std::cin >> num;

  {
    uint32_t tmp_num = num;

    unsigned short i = 0;
    while (tmp_num != 0) {
      tmp_num /= 10;
      i++;
    }
    if (i > 6) {
      std::cout << "This number is not six-digit. Try again" << std::endl;
      return 0;
    }
  }

  uint32_t tmp_num = num;
  unsigned short suml = 0;
  unsigned short sumr = 0;
  unsigned short i = 0;
  tmp_num = num;
  while (tmp_num != 0) {
    if (i < 3) {
      sumr += tmp_num % 10;
    } else {
      suml += tmp_num % 10;
    }
    tmp_num /= 10;
    ++i;
  }

  if (suml == sumr) {
    std::cout << "You won!!!" << std::endl;
  } else {
    std::cout << "You lose!!!" << std::endl;
  }

  return 0;
}
