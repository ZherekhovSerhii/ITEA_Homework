#include "List.hpp"
#include <iostream>
#include <list>

int main(int argc, char *argv[]) {

  List<int> l1;
  l1.push_front(40);
  l1.push_back(37);
  l1.push_front(35);
  l1.push_back(20);
  l1.push_back(30);

  std::cout << "L1:\n";
  l1.print();

  List<int> l2(l1);
  l2.emplace(l2.find(40), 41);
  l2.delete_back();
  std::cout << "L2:\n";
  l2.print();

  List<int> l3;
  l3.push_back(1);
  l3.insert(l3.find(1), 2);
  l3.insert(l3.find(2), 3);
  l3.delete_element(l3.find(2));
  l3.delete_back();
  l3.delete_front();

  std::cout << "L3:\n";
  l3.print();

  // std::cout << "l_begin: " << l3.l_begin->field << " l_end: " <<
  // l3.l_end->field << "\n";

  //std::cout << "size: " << l3.size();
  return 0;
}
