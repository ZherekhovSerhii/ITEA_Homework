#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  std::cout << "Enter the unsigned number from 0 to "
            << std::numeric_limits<uint32_t>::max()
            << " you want to calculate sum and average of its digits:"
            << std::endl;
  uint32_t num;
  std::cin >> num;

  uint32_t tmp_num = num;

  unsigned short sum = 0;
  unsigned short i = 0;
  while (tmp_num != 0) {
    sum += tmp_num % 10;
    tmp_num /= 10;
    ++i;
  }

  if (i == 0) {
    ++i;
  }

  std::cout << "sum = " << sum << std::endl;
  std::cout << "average = " << (sum + 0.f) / i << std::endl;
  return 0;
}
