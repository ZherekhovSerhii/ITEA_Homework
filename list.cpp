#include "List.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  List<int> l1;
  l1.add(40);
  l1.add(30);
  l1.insert(35, 1);

  List<int> l2;
  l2.add(789);
  l2.add(79);
  l2 = l1;

  std::cout << "L1:\n";
  l1.print();
  std::cout << "L2:\n";
  l2.print();

  return 0;
}