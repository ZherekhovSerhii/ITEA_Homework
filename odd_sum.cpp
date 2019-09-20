#include <bitset>
#include <cstdint>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  const uint16_t LOW_LIM = 1;
  const uint16_t UP_LIM = 50;

  std::cout << "Enter number of elements you want to input from 1 to 50:"
            << std::endl;
  uint16_t num_of_elements;
  std::cin >> num_of_elements;
  if ((num_of_elements < LOW_LIM) || (num_of_elements > UP_LIM)) {
    std::cout << "Number of elements should be from 1 to 50. Try again"
              << std::endl;
    return 0;
  }

  std::cout << "Input:" << std::endl;
  uint16_t num[UP_LIM];
  uint16_t sum = 0;

  for (int i = 0; i < num_of_elements; ++i) {
    std::cin >> num[i];
    if (num[i] % 2 == 1) {
      sum += num[i];
    }
  }

  std::cout << "Output:" << std::endl;
  std::cout << sum << " --> ";
  if (num[0] % 2 == 1) {
    std::cout << num[0];
  }

  for (int i = 1; i < num_of_elements; ++i) {
    if (num[i] % 2 == 1) {
      std::cout << " + " << num[i];
    }
  }
  std::cout << " = " << sum;

  return 0;
}
