#include <iostream>

using namespace std;

template<size_t, size_t> class Screen;
template<size_t W, size_t H>
ostream &operator<<(ostream &, const Screen<W, H> &);

template<size_t W, size_t H>
class Screen {
  friend ostream &operator<< <W, H>(ostream &, const Screen<W, H> &);
public:
  Screen() = default;
//private:
  string content;
  size_t width = W;
  size_t height = H;
};

template<size_t W, size_t H>
ostream &operator<<(ostream &os, const Screen<W, H> &s) {
  os << s.width << ", " << s.height << ", ";
  os << s.content;
  return os;
}

int main() {
  Screen<24, 80> s;
  cout << s << endl;
}
