#include <iostream>
#include <string>

using namespace std;

template <typename elemType> 
class ListItem {
public:
  ListItem() : next_(nullptr) {}
  ListItem(elemType &value) : value_(value), next_(nullptr) {}
  ListItem(elemType &value, ListItem *next) : value_(value), next_(next) {}
  elemType value_;
  ListItem *next_;
};

template <typename elemType>
class List {
public:
  List<elemType>();
  List<elemType>(const List<elemType> &) = default;
  List<elemType> &operator=(const List<elemType> &) = default;
  ~List();
  void insert(ListItem *ptr, elemType value);
private:
  ListItem *head, *front, *end;
};

template <typename elemType>
List<elemType>() : head(new ListItem<elemType>()), front(nullptr), end(nullptr) {
}

template <typename elemType>
~List<elemType>() {
  ListItem<elemType> *item = front;
  ListItem<elemType> *n = nullptr;
  while (item) {
    n = item;
    item = item->next;
    delete n;
  }
  delete head;
}

int main() {
  List<int> ilst;
}
