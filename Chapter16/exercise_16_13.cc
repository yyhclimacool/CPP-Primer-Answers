#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

template<typename> class BlobPtr; // 模板声明

template<typename T>
class Blob{
  friend class BlobPtr<T>;
public:
  typedef T value_type;
  using size_type = typename std::vector<T>::size_type;
  Blob() : data(std::make_shared<std::vector<T>>()) {}
  Blob(std::initializer_list<T> il);
  bool empty() const { return data->empty(); }
  size_type size() const { return data->size(); }
  void push_back(const T &rhs) {
    data->push_back(rhs);
  }
  void push_back(T &&rhs) {
    data->push_back(std::move(rhs));
  }
  void pop_back();
  T &back();
  T &front();
  const T &back() const;
  const T &front() const;
  T &operator[](size_type);
  const T &operator[](size_type) const;
private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const {
    if (i >= data->size())
      throw runtime_error(msg);
  }
};

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) 
  : data(std::make_shared<std::vector<T>>(il)) {}

template<typename T>
T &Blob<T>::front() {
  check(0, "front on empty vector");
  return data->front();
}

template<typename T>
const T &Blob<T>::front() const {
  check(0, "front on empty vector");
  return data->front();
}

template<typename T>
T &Blob<T>::back() {
  check(0, "back on empty vector");
  return data->back();
}

template<typename T>
const T &Blob<T>::back() const {
  check(0, "back on empty vector");
  return data->back();
}

template<typename T>
T &Blob<T>::operator[](size_type i) {
  check(i, "index out of range");
  return (*data)[i];
}

template<typename T>
const T &Blob<T>::operator[](size_type i) const {
  check(i, "index out of range");
  return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back() {
  check(0, "pop_back on emtpy vector");
  data->pop_back();
}

template<typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);

template<typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);

template<typename T>
class BlobPtr {
  friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
  // 这里要留一个空格，^.^
  friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<T> &b, typename Blob<T>::size_type i = 0)
    : wptr(b.data), curr(i) {}
  // 解引用运算符
  T &operator*();

  // 前置版本
  BlobPtr &operator++();
  BlobPtr &operator--();

  BlobPtr operator++(int);
  BlobPtr operator--(int);
private:
  std::shared_ptr<std::vector<T>> check(typename Blob<T>::size_type i, const std::string &msg) const;
private:
  std::weak_ptr<std::vector<T>> wptr;
  typename Blob<T>::size_type curr;
};

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr == rhs.curr && lhs.wptr.lock() == rhs.wptr.lock();
}

// 调用者保证lhs和rhs指向相同的底层数据
template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
  return lhs.curr < rhs.curr;
}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(typename Blob<T>::size_type i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret) 
    throw runtime_error("Unbound Blob");
  if (i >= ret->size())
    throw runtime_error(msg);
  return ret;
}

template<typename T>
T &BlobPtr<T>::operator*() {
  auto ret = check(curr, "operator* out of range");
  return (*ret)[curr];
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
  check(++curr, "out of range");
  return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
  check(--curr, "out of range");
  return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
  auto ret = *this;
  --*this;
  return ret;
}

using StrBlob = Blob<string>;

int main() {
  // test on Blob
  StrBlob sb{"a", "an", "the"};
  cout << sb.front() << ", " << sb.back() << endl;
  const StrBlob csb(sb);
  cout << csb.front() << ", " << csb.back() << endl;

  Blob<int> ib{1,2,3,4,5,6};
  //while(ib.size() != 0) {
  //  cout << "Pop " << ib.back() << endl;
  //  ib.pop_back();
  //}

  // test on BlobPtr
  BlobPtr<int> bptr(ib); // 实例化BlobPtr<int>和构造函数
  BlobPtr<int> bptr2(ib);
  cout << *bptr << endl; // 实例化解引用运算符
  bptr++; // 实例化后置递增
  cout << *bptr << endl;
  ++bptr2; // 实例化前置递增
  if (bptr == bptr2) {
    cout << "bptr == bptr2" << endl;
  }
  bptr2++;
  if (bptr < bptr2) {
    cout << "bptr < bptr2" << endl;
  }
}
