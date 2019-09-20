#include <bitset>
#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  const uint16_t LOW_LIM = 1;
  const uint16_t UP_LIM = 10;

  std::cout << "Enter number of elements you want to input from 1 to 10:"
            << std::endl;
  uint16_t num_of_elements;
  std::cin >> num_of_elements;
  if ((num_of_elements < LOW_LIM) || (num_of_elements > UP_LIM)) {
    std::cout << "Number of elements should be from 1 to 10. Try again"
              << std::endl;
    return 0;
  }

  uint16_t num[UP_LIM];
  for (int i = 0; i < num_of_elements; ++i) {
    std::cin >> num[i];
  }

  uint16_t sum = 0;
  for (int i = 0; i < num_of_elements; ++i) {
    uint16_t tmp_num = num[i];

    while (tmp_num != 0) {
      sum += tmp_num % 10;
      tmp_num /= 10;
    }
  }

  if (sum % 3 == 0) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
