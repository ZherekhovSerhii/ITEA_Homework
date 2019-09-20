#include <bitset>
#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  std::cout << "Enter the number from -2147447412 to 2147447412"
            << " you want to reverse" << std::endl;
  int32_t num;
  std::cin >> num;

  int32_t tmp_num = num;

  unsigned short counter = 0;
  while (tmp_num != 0) {
    tmp_num /= 10;
    ++counter;
  }

  tmp_num = num;
  int32_t num_reversed = 0;
  for (int i = counter; i > 0; --i) {
    num_reversed += (tmp_num % 10) * static_cast<int32_t>(pow(10, i - 1));
    tmp_num /= 10;
  }

  std::cout << num_reversed << std::endl;
  return 0;
}
