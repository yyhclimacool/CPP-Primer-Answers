#include <iostream>
#include <memory>
#include <string>

using namespace std;

template <typename T, typename ... Args>
shared_ptr<T> my_make_shared(Args && ... args) {
  return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
  shared_ptr<string> sptr;
  {
    auto ptr = my_make_shared<string>(10, 'c');
    sptr = ptr;
  }
  cout << *sptr << endl;
}
