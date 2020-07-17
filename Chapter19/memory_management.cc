#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

class Base {
public:
  static void *operator new(size_t);
  static void *operator new(size_t, const nothrow_t &);
  static void *operator new(size_t, const string &);
  static void operator delete(void *) noexcept;
  static void operator delete(void *, const nothrow_t &) noexcept;

  Base(int i) : ival(i) {}

  int ival;
};

void *Base::operator new(size_t s) {
  cout << "calling Base::operator new(size_t) ..." << endl;
  if (void *memptr = malloc(s))
    return memptr;
  else throw std::bad_alloc();
}

void *Base::operator new(size_t sz, const string &msg) {
  cout << "calling Base::operator new(size_t, const string &) with msg:" << msg << endl;

  if (void *memptr = malloc(sz))
    return memptr;
  else throw std::bad_alloc();
}

void *Base::operator new(size_t sz, const nothrow_t &n) {
  (void)n;
  cout << "calling Base::operator new(size_t, const nothrow_t &) ..." << endl;
  return malloc(sz);
}

void Base::operator delete(void *p) noexcept {
  cout << "calling Base::operator delete(void *) ..." << endl;
  free(p);
}

void Base::operator delete(void *p, const nothrow_t &n) noexcept {
  cout << "calling Base::operator delete (void *, const nothrow_t &) ..." << endl;
  (void)n;
  free(p);
}

int main() {
  Base *p = new Base(42);
  delete p;
  Base *p2 = new (nothrow) Base(42);
  delete p2;

  Base *p3 = new ("new new!") Base(42);
  delete p3;
}
