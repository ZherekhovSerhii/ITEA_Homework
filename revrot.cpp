#include <iostream>

template <typename T> void swap(T &a, T &b) {
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

uint16_t cube(uint16_t num) { return num * num * num; }

void reverse(char *begin, char *end) {
  while (begin < end) {
    swap(*begin++, *--end);
  }
}

void rotate(char *begin, char *end) {
  char ch = *begin;
  while (begin != end) {
    *begin = *(begin + 1);
    ++begin;
  }
  *(end - 1) = ch;
}

void rev_or_rot_check(char *begin, char *end) {
  char *s = begin;
  int sum = 0;
  while (s != end) {
    sum += cube(*s - '0');
    ++s;
  }

  (sum % 2) ? rotate(begin, end) : reverse(begin, end);
  return;
}

char *revrot(char *str, size_t sz) {
  if (sz <= 0 || *str == '\0')
    return "";

  char *s = str;
  size_t len = 0;
  while (*s != '\0') {
    if ('0' > *s || *s > '9')
      return "";
    ++len;
    ++s;
  }
  if (len < sz)
    return "";

  len /= sz;
  for (size_t i = 0; i < len; ++i)
    rev_or_rot_check((str + i * sz), (str + i * sz + sz));

  *(str + len * sz) = '\0';
  return str;
}

int main(int argc, char *argv[]) {
  constexpr size_t SIZE = 256;
  char str[SIZE];
  std::cout << "Input the string to revrot it: \n";
  std::cin >> str;

  size_t sz = 0;
  std::cout << "Input the size of block: \n";
  std::cin >> sz;

  std::cout << "The revroted string is: \n";
  std::cout << revrot(str, sz) << "\n";

  return 0;
}