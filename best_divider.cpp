#include <bitset>
#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  constexpr uint16_t LOW_LIM = std::numeric_limits<uint16_t>::min();
  constexpr uint16_t UP_LIM = std::numeric_limits<uint16_t>::max();
  std::cout << "Enter number from " << LOW_LIM << " to " << UP_LIM
            << " to find the best divider:" << std::endl;

  std::cout << "Number: ";
  uint32_t num;
  std::cin >> num;
  if ((num < LOW_LIM) || (num > UP_LIM)) {
    std::cout << "Invalid value. Try again" << std::endl;
    return 0;
  }

  const uint16_t HALF_OF_NUM = num / 2;
  uint16_t best_divider = 0;
  uint16_t best_divider_sum = 0;
  for (int i = 1; i <= num; ++i) {
    if ((i > HALF_OF_NUM) && (i < num)) {
      continue;
    }

    if (num % i == 0) {
      uint16_t tmp_num = i;

      uint16_t sum = 0;
      while (tmp_num != 0) {
        sum += tmp_num % 10;
        tmp_num /= 10;
      }

      std::cout << "i= " << i << " sum= " << sum << std::endl;

      if (sum >= best_divider_sum) {
        best_divider = i;
        best_divider_sum = sum;
      }
    }
  }

  std::cout << "best divider is: " << best_divider << std::endl;
  return 0;
}
