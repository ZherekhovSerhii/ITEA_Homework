#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>

void swap(int16_t &a, int16_t &b) {
  int16_t tmp = a;
  a = b;
  b = tmp;
}

void bubble_sort(int16_t arr[], size_t arr_size,
                 std::function<bool(int16_t, int16_t)> comp) {
  while (arr_size > 1) {
    for (size_t i = 0; i < arr_size - 1; ++i) {
      if (comp(arr[i], arr[i + 1]))
        swap(arr[i], arr[i + 1]);
    }
    --arr_size;
  }
}

void quick_sort(int16_t arr[], size_t left, size_t right,
                std::function<bool(int16_t, int16_t)> comp) {
  size_t i = left, j = right;
  int p = arr[(left + right) / 2];

  while (i <= j) {
    while (comp(p, arr[i]))
      ++i;
    while (comp(arr[j], p))
      --j;
    if (i <= j) {
      swap(arr[i], arr[j]);
      ++i;
      --j;
    }
  }

  if (left < j)
    quick_sort(arr, left, j, comp);
  if (i < right)
    quick_sort(arr, i, right, comp);
}

int main(int argc, char *argv[]) {
  constexpr size_t ARR_SIZE = 2048;
  constexpr int16_t INT16_T_MAX_BORDER = std::numeric_limits<int16_t>::max();
  constexpr int16_t INT16_T_MIN_BORDER =
      std::numeric_limits<int16_t>::min() / 2;
  int16_t arr[ARR_SIZE];

  srand(static_cast<unsigned int>(time(0)));
  for (size_t i = 0; i < ARR_SIZE; ++i)
    arr[i] = (rand() % INT16_T_MAX_BORDER) + INT16_T_MIN_BORDER;
  unsigned int start_time = clock();
  quick_sort(arr, 0, ARR_SIZE - 1, [](int16_t a, int16_t b) { return a > b; });
  unsigned int end_time = clock();
  unsigned int search_time = end_time - start_time;
  std::cout << "quick sort time: " << search_time << "\n";

  for (size_t i = 0; i < ARR_SIZE; ++i)
    arr[i] = (rand() % INT16_T_MAX_BORDER) + INT16_T_MIN_BORDER;
  start_time = clock();
  bubble_sort(arr, ARR_SIZE, [](int16_t a, int16_t b) { return a > b; });
  end_time = clock();
  search_time = end_time - start_time;
  std::cout << "bubble sort time: " << search_time << "\n";

  return 0;
}