#include "shared_ptr.h"
#include "unique_ptr.h"
#include <iostream>

int main() {
  shared_ptr<int> sp(new int(42));
  shared_ptr<int> nullsp;
  nullsp = sp;
  std::cout << nullsp.use_count() << std::endl;

  unique_ptr<int> up(new int(44));
  std::cout << "content is : " << *up << std::endl;
}
