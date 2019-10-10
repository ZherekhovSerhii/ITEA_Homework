#include <ctime>
#include <functional>
#include <iostream>

constexpr size_t ARR_SIZE = 512;

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

void uint_quick_sort(unsigned int arr[], size_t left, size_t right) {
  size_t i = left, j = right;
  unsigned int p = arr[(left + right) / 2];

  while (i <= j) {
    while (arr[i] < p)
      ++i;
    while (arr[j] > p)
      --j;
    if (i <= j) {
      swap(arr[i], arr[j]);
      ++i;
      --j;
    }
  }

  if (left < j)
    uint_quick_sort(arr, left, j);
  if (i < right)
    uint_quick_sort(arr, i, right);
}

void d_quick_sort(double arr[], size_t left, size_t right) {
  size_t i = left, j = right;
  double p = arr[(left + right) / 2];

  while (i <= j) {
    while (arr[i] < p)
      ++i;
    while (arr[j] > p)
      --j;
    if (i <= j) {
      swap(arr[i], arr[j]);
      ++i;
      --j;
    }
  }

  if (left < j)
    d_quick_sort(arr, left, j);
  if (i < right)
    d_quick_sort(arr, i, right);
}

void ch_bubble_sort(char arr[], size_t arr_size) {
  while (arr_size > 1) {
    for (size_t i = 0; i < arr_size - 1; ++i) {
      if ([](char arr_i, char arr_i_1) { return arr_i > arr_i_1; }(arr[i],
                                                                   arr[i + 1]))
        swap(arr[i], arr[i + 1]);
    }
    --arr_size;
  }
}

int main(int argc, char *argv[]) {
  constexpr unsigned int UINT_T_MAX_BORDER =
      std::numeric_limits<unsigned int>::max();
  unsigned int uint_arr[ARR_SIZE];
  srand(time(0));
  for (size_t i = 0; i < ARR_SIZE; ++i)
    uint_arr[i] = rand() % UINT_T_MAX_BORDER;
  uint_quick_sort(uint_arr, 0, ARR_SIZE - 1);
  for (size_t i = 0; i < ARR_SIZE; ++i)
    std::cout << uint_arr[i] << " ";

  std::cout << "\n\n";

  constexpr double DOUBLE_T_MIN_BORDER = std::numeric_limits<double>::min();
  double d_arr[ARR_SIZE];
  for (size_t i = 0; i < ARR_SIZE; ++i)
    d_arr[i] = DOUBLE_T_MIN_BORDER + ((double)rand() / RAND_MAX);
  d_quick_sort(d_arr, 0, ARR_SIZE - 1);
  for (size_t i = 0; i < ARR_SIZE; ++i)
    std::cout << d_arr[i] << " ";

  std::cout << "\n\n";

  char ch_arr[ARR_SIZE];
  for (size_t i = 0; i < ARR_SIZE; ++i)
    ch_arr[i] = 48 + rand() % 75;
  ch_bubble_sort(ch_arr, ARR_SIZE);
  for (size_t i = 0; i < ARR_SIZE; ++i)
    std::cout << ch_arr[i] << " ";

  return 0;
}