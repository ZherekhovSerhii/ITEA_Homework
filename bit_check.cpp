#include <bitset>
#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  constexpr uint32_t LOW_LIM_NUM = std::numeric_limits<uint32_t>::min();
  constexpr uint32_t UP_LIM_NUM = std::numeric_limits<uint32_t>::max();
  const uint16_t LOW_LIM_BIT = 1;
  const uint16_t UP_LIM_BIT = 32;
  std::cout << "Enter number from " << LOW_LIM_NUM << " to " << UP_LIM_NUM
            << " and bit number from 1 to 32:" << std::endl;

  std::cout << "Number: ";
  uint32_t num;
  std::cin >> num;
  if ((num < LOW_LIM_NUM) || (num > UP_LIM_NUM)) {
    std::cout << "Invalid value. Try again" << std::endl;
    return 0;
  }

  std::cout << "Bit: ";
  uint16_t bit;
  std::cin >> bit;
  if ((bit < LOW_LIM_BIT) || (bit > UP_LIM_BIT)) {
    std::cout << "Invalid value. Try again" << std::endl;
    return 0;
  }

  uint32_t tmp_num = num;
  tmp_num >>= bit - 1;

  std::cout << std::bitset<32>(num) << std::endl;
  if ((tmp_num & 1) == 1) {
    std::cout << "bit is setted!!!";
  }
  return 0;
}
