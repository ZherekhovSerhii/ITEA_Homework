#ifndef LIST_H
#define LIST_H

template <typename T> struct list_el {
public:
  T field;
  list_el *next = nullptr;
  list_el *prev = nullptr;
};

template <typename T> class List {
public:
  List() = default;

  ~List() {
    while (l_begin != nullptr) {
      list_el<T> *next = l_begin->next;
      delete l_begin;
      l_begin = next;
    }
  }

  List(const List &l_) {
    for (list_el<T> *it = l_.l_end; it != nullptr; it = it->prev) {
      push_front(it->field);
    }
  }

  List &operator=(const List &l_) {
    if (this == &l_)
      return *this;

    while (l_begin != nullptr) {
      list_el<T> *next = l_begin->next;
      delete l_begin;
      l_begin = next;
    }

    l_end = l_begin;

    for (list_el<T> *it = l_.l_end; it != nullptr; it = it->prev) {
      push_front(it->field);
    }

    return *this;
  }

  list_el<T> *begin() const { return l_begin; }

  list_el<T> *end() const { return l_end; }

  const T front() const {
    if (l_begin != nullptr)
      return l_begin->field;
  }

  const T back() const {
    if (l_end != nullptr)
      return l_end->prev->field;
  }

  size_t size() const { return count; }

  bool empty() const { return (size == 0) ? true : false; }

  list_el<T> *push_front(T value) {
    list_el<T> *node = new list_el<T>;
    node->field = value;
    if (l_begin != nullptr)
      l_begin->prev = node;
    node->next = l_begin;
    l_begin = node;

    if (count == 0)
      l_end = node;

    ++count;

    return l_begin;
  }

  list_el<T> *push_back(T value) {
    list_el<T> *node = new list_el<T>;
    node->field = value;
    if (l_end != nullptr)
      l_end->next = node;
    node->prev = l_end;
    l_end = node;

    if (count == 0)
      l_begin = node;

    ++count;

    return l_end;
  }

  void emplace_front(T value) { l_begin->field = value; }

  void emplace_back(T value) { l_end->field = value; }

  const list_el<T> *emplace(list_el<T> *pos, T value) {
    if (pos == nullptr)
      return pos;

    pos->field = value;
    return pos;
  }

  list_el<T> *delete_front() {
    if (count <= 0)
      return nullptr;

    list_el<T> *next = l_begin->next;
    delete l_begin;
    l_begin = next;
    if (l_begin != nullptr)
      l_begin->prev = nullptr;

    --count;

    return l_begin;
  }

  list_el<T> *delete_back() {
    if (count <= 0)
      return nullptr;
    if (count == 1)
      return delete_front();

    list_el<T> *prev = l_end->prev;
    delete l_end;
    l_end = prev;
    if (l_end != nullptr)
      l_end->next = nullptr;

    --count;

    return l_end;
  }

  list_el<T> *delete_element(list_el<T> *pos) {
    if (pos == nullptr)
      return pos;

    list_el<T> *del_node = find(pos);

    if (del_node != nullptr) {
      if (del_node == l_begin)
        return delete_front();
      if (del_node == l_end)
        return delete_back();

      list_el<T> *prev_node = del_node->prev;
      list_el<T> *next_node = del_node->next;
      prev_node->next = next_node;
      next_node->prev = prev_node;
      delete del_node;
      --count;
      return prev_node;
    } else
      return nullptr;
  }

  list_el<T> *insert(list_el<T> *pos, T value) {
    if (pos == nullptr)
      return pos;

    list_el<T> *prev_node = find(pos);
    list_el<T> *next_node = prev_node->next;

    if (prev_node != nullptr) {
      if (prev_node == l_end)
        return push_back(value);

      list_el<T> *node = new list_el<T>;
      node->field = value;
      node->prev = prev_node;
      node->next = next_node;
      prev_node->next = node;
      next_node->prev = node;
      ++count;
      return node;
    } else
      return nullptr;
  }

  list_el<T> *find(T value) {
    if (count <= 0)
      return nullptr;

    for (list_el<T> *it = l_begin; it != nullptr; it = it->next)
      if (it->field == value)
        return it;

    return nullptr;
  }

  list_el<T> *find(const list_el<T> *node) {
    if (count <= 0)
      return nullptr;

    for (list_el<T> *it = l_begin; it != nullptr; it = it->next)
      if (it == node)
        return it;

    return nullptr;
  }

  void print() const {
    for (list_el<T> *it = l_begin; it != nullptr; it = it->next) {
      std::cout << it->field << std::endl;
    }
  }

public:
  list_el<T> *l_end = nullptr;
  list_el<T> *l_begin = l_end;
  size_t count = 0;
};

#endif LIST_H
