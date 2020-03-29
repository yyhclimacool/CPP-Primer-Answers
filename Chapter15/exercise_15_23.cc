#include <iostream>
#include <string>

using namespace std;

class Base {
public:
  Base() = default;
  virtual ~Base() {}
  virtual int fcn() { return 0;}
};

class D1 : public Base {
public:
  D1() = default;
  virtual ~D1() {}
  int fcn(int) { return 1;}
  virtual int fcn() override { return 42; }
  virtual void f2() {}
};

class D2 : public D1 {
public:
  D2() = default;
  virtual ~D2() {}
  int fcn(int) { return 2;}
  int fcn() { return 3;}
  void f2() {}
};

int main() {
  Base bobj;
  D1 d1obj;
  D2 d2obj;

  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
  bp1->fcn(); // Base::fcn()
  bp2->fcn(); // Base::fcn() -> D1::fcn()
  bp3->fcn(); // D2::fcn()

  D1 *d1p = &d1obj;
  D2 *d2p = &d2obj;
  //bp2->f2(); // ERROR: Base has no f2()
  d1p->f2(); // D1::f2()
  d2p->f2(); // D2::f2()

  Base *p1 = &d2obj;
  D1 *p2 = &d2obj;
  D2 *p3 = &d2obj;
  (void)p1;
  //p1->fcn(42); // ERROR: Base has no fcn(int)
  p2->fcn(42); // D1::fcn(int), no virtual
  p3->fcn(42); // D2::fcn(int), no virtual
}
