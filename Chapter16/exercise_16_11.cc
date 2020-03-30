#include <iostream>
#include <string>

using namespace std;

template<typename T> class ListItem;

// 有内存泄漏，不安全，仅作为示例
template<typename T> class List {
public:
  List() : front(nullptr), end(nullptr) {}
  List(ListItem<T> &, ListItem<T> &);
  List(const List &) = default;
  List &operator==(const List &);
  ~List() = default;

  // 没有使用，因此不会实例化，因此可以不定义
  void insert(ListItem<T> *ptr, T value);
private:
  ListItem<T> *front, *end;
};

template <typename T>
class ListItem {
public:
  ListItem(const T &val) : val_(val), next(nullptr) {}
  T getvalue() const { return val_; }
  void append(ListItem &rhs) {
    next = &rhs;
  }
private:
  T val_;
  ListItem *next;
};

template<typename T>
List<T>::List(ListItem<T> &first, ListItem<T> &last)
  : front(&first), end(&last) {}

template<typename T>
List<T> &List<T>::operator==(const List &rhs) {
  front = rhs.front;
  end = rhs.end;
}

int main() {
  ListItem<string> item1("No.1");
  ListItem<string> item2("No.2");
  ListItem<string> item3("No.3");

  item1.append(item2);
  item2.append(item3);

  List<string> slst(item1, item3);
}
