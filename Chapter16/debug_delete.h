#ifndef DEBUG_DELETE_H
#define DEBUG_DELETE_H

#include <iostream>

class DebugDelete {
public:
  DebugDelete(std::ostream &o = std::cerr) : os(o) {}
  template<typename T> void operator()(T *p) {
    os << "debug delete pointer" << std::endl;
    delete p;
  }
private:
  std::ostream &os;
};

#endif // DEBUG_DELETE_H
