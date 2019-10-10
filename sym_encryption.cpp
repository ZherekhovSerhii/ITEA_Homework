#include <iostream>

#define STR_SIZE 2048

typedef struct Key {
  size_t lines;
  size_t columns;
};

size_t str_len(const char *begin) {
  if (begin == nullptr || *begin == '\0')
    return 0;

  size_t length = 0;
  while (*begin++ != '\0')
    ++length;

  return length;
}

char *str_cpy(const char *orig, char *copy, size_t length) {
  char *copied_str_begin = copy;
  size_t counter = 0;
  while (counter < length) {
    *copy = *orig;
    ++orig;
    ++copy;
    ++counter;
  }
  return copied_str_begin;
}

char *encrypt(char *str, size_t lines, size_t columns) {
  size_t table_size = lines * columns;
  size_t len = str_len(str);
  if ((lines * columns < len) || (table_size > STR_SIZE) || (*str == '\0'))
    return "\0";

  char *s = new char[table_size]{};
  size_t counter = 0, i = 0, j = 0;
  while (counter < len) {
    if (!(i < lines)) {
      i = 0;
      ++j;
    }
    *(s + i * columns + j) = *(str + counter);
    ++i;
    ++counter;
  }

  str = str_cpy(s, str, table_size);
  return str;
}

char *decrypt(char *str, size_t lines, size_t columns) {
  size_t table_size = lines * columns;
  if ((table_size > STR_SIZE) || (*str == '\0'))
    return "\0";

  char *s = new char[table_size];

  size_t counter = 0, i = 0, j = 0;
  while (counter < table_size) {
    if (!(i < lines)) {
      i = 0;
      ++j;
    }
    *(s + counter) = *(str + i * columns + j);
    ++i;
    ++counter;
  }

  str = str_cpy(s, str, table_size);
  return str;
}

int main(int argc, char *argv[]) {
  char *str = new char[STR_SIZE]{};
  std::cout << "Write something you wanna encrypt:" << std::endl;
  std::cin >> str;
  Key key{};
  std::cout << "\nEnter two numbers for crypt key:\n";
  std::cout << "1: ";
  std::cin >> key.lines;
  std::cout << "2: ";
  std::cin >> key.columns;
  std::cout << key.lines << " " << key.columns << "\n\n";

  str = encrypt(str, key.lines, key.columns);
  std::cout << "Encrypted str: \n" << str << "\n";
  str = decrypt(str, key.lines, key.columns);
  std::cout << "Decrypted str: \n" << str << "\n";

  return 0;
}