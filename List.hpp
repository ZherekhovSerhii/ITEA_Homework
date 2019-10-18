#pragma once
#ifndef LIST_H
#define LIST_H

template <typename T> struct list_el {
  T field;
  list_el *next;
};

template <typename T> class List {
private:
  list_el<T> *head = nullptr;

public:
  List() {}

  List &operator=(const List &l_) {
    if (this == &l_)
      return *this;

    clear();

    list_el<T> *p = nullptr;
    list_el<T> *p_added = nullptr;
    list_el<T> *p_prev = nullptr;
    while (p_added != l_.head) {
      p = l_.head;
      while (p != p_added) {
        p_prev = p;
        p = p->next;
      }
      p_added = p_prev;
      add(p_added->field);
    }

    return *this;
  }

  void print() {
    list_el<T> *p = head;
    while (p != nullptr) {
      std::cout << p->field << "\n";
      p = p->next;
    }
  }

  void clear() {
    while (head != nullptr) {
      list_el<T> *next_el = head->next;
      delete head;
      head = next_el;
    }
  }

  void add(int value) {
    list_el<T> *new_el = new list_el<T>;
    new_el->field = value;
    new_el->next = head;
    head = new_el;
  }

  void insert(int value, size_t pos) {
    if (len() < pos) {
      std::cout << "ERROR: ELEMENT ISNT EXIST\n";
      return;
    }

    if (pos == 0) {
      add(value);
      return;
    }

    list_el<T> *new_el = new list_el<T>;
    new_el->field = value;

    list_el<T> *p = head;
    for (size_t i = 0; i < pos - 1; ++i)
      p = p->next;

    new_el->next = p->next;
    p->next = new_el;
  }

  void del(size_t pos) {
    if (len() <= pos) {
      std::cout << "ERROR: ELEMENT ISNT EXIST\n";
      return;
    }

    if (pos == 0) {
      list_el *next_el = head->next;
      delete head;
      head = next_el;
      return;
    }

    list_el<T> *prev_el = head;
    for (size_t i = 0; i < pos - 1; ++i)
      prev_el = prev_el->next;

    list_el<T> *del_el = prev_el->next;
    prev_el->next = prev_el->next->next;
    delete del_el;
  }

  int get(size_t pos) {
    if (len() <= pos) {
      std::cout << "ERROR: ELEMENT ISNT EXIST\n";
      return NULL;
    }

    list_el *cur_el = head;
    for (size_t i = 0; i < pos; ++i)
      cur_el = cur_el->next;
    return cur_el->field;
  }

  size_t len() {
    size_t len = 0;
    list_el<T> *p = head;
    while (p != nullptr) {
      p = p->next;
      ++len;
    }
    return len;
  }

  ~List() {
    while (head != nullptr) {
      list_el<T> *next_el = head->next;
      delete head;
      head = next_el;
    }
  }
};
#endif LIST_H