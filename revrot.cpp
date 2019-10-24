#include <iostream>

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

uint64_t cube(uint16_t num) { return num * num * num; }

void reverse(char *begin, char *end) {
  if (begin == nullptr || end == nullptr)
    return;

  while (begin < end) {
    swap(*begin++, *--end);
  }
}

void rotate(char *begin, char *end) {
  if (begin == nullptr || end == nullptr)
    return;

  char ch = *begin;
  while (begin != end) {
    *begin = *(begin + 1);
    ++begin;
  }
  *(end - 1) = ch;
}

char *revrot(char *str, size_t sz) {
  if (sz <= 0 || *str == '\0' || str == nullptr)
    return str;

  size_t len = strlen(str);
  if (len < sz) {
    *str = '\0';
    return str;
  }

  len /= sz;
  for (size_t i = 0; i < len; ++i) {
    char *begin = (str + i * sz);
    char *end = begin + sz;

    int sum = 0;
    for (char *it = begin; it != end; ++it) {
      if ('0' > *it || *it > '9') {
        *str = '\0';
        return str;
      };
      sum += cube(*it - '0');
    }

    if (sum % 2 > 0)
      rotate(begin, end);
    else
      reverse(begin, end);
  }

  *(str + len * sz) = '\0';
  return str;
}

int main(int argc, char *argv[]) {
  constexpr size_t SIZE = 256;
  char str[SIZE]{};
  std::cout << "Input the string to revrot it: \n";
  std::cin >> str;

  size_t sz = 0;
  std::cout << "Input the size of block: \n";
  std::cin >> sz;

  char *res = revrot(str, sz);
  if (strncmp(res, "", 1)) {
    std::cout << "The revroted string is: \n";
    std::cout << res << "\n";
  } else
    std::cout << "The revroted string is empty! \n";

  return 0;
}
