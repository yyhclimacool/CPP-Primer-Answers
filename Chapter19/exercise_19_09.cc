#include <iostream>
#include <typeinfo>
#include <string>

class Base {
  friend bool operator==(const Base &, const Base &); 
  public:
  Base(int i) : ival_(i) {}
  ~Base() = default;
  protected:
  virtual bool equal(const Base &rhs) const {
    return ival_ == rhs.ival_;
  }
  int ival_;
  private:
};

class Derived : public Base {
  public:
    Derived(int i, std::string s) : Base(i), sval_(s) {}
    ~Derived() = default;
  protected:
    virtual bool equal(const Base &rhs) const {
      const Derived &ref_d = dynamic_cast<const Derived &>(rhs);  
      return sval_ == ref_d.sval_ && ival_ == ref_d.ival_;
    }
  private:
    std::string sval_;
};

bool operator==(const Base &lhs, const Base &rhs) {
  return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main() {
  Base b1(2);
  Base b2(2);
  if (b1 == b2) 
    std::cout << "OK" << std::endl;
  else
    std::cout << "ERROR" << std::endl;
  Derived d1(2, "fine");
  Derived d2(2, "fine");
  Derived d3(2, "diff");
  if (d1 == d2) 
    std::cout << "OK" << std::endl;
  else 
    std::cout << "ERROR" << std::endl;
  if (d1 == d3) 
    std::cout << "ERROR" << std::endl;
  else 
    std::cout << "OK" << std::endl;
}
