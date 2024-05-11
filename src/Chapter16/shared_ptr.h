#include <iostream>

template<typename T>
class shared_ptr {
public:
  using DeleteFunc = void(*)(T *);

  shared_ptr(T *ptr = nullptr, DeleteFunc d = nullptr)
    : ptr_(ptr), count_ptr_(new size_t(ptr_ != nullptr)), deleter_(d) {}

  shared_ptr(const shared_ptr &other)
    : ptr_(other.ptr_), count_ptr_(other.count_ptr_), deleter_(other.deleter_) {
      ++*count_ptr_;
  }

  shared_ptr(shared_ptr &&other) noexcept
    : shared_ptr() {
      swap(other);
  }

  shared_ptr &operator=(shared_ptr sp) {
    swap(sp);
     return *this;
  }

  ~shared_ptr() {
    if (!ptr_) return;
    if (--*count_ptr_ == 0) {
      deleter_ ? deleter_(ptr_) : delete ptr_;
      delete count_ptr_;
    }
    ptr_ = nullptr;
    deleter_ = nullptr;
  }
  
  void swap(shared_ptr &other) noexcept  {
    using std::swap;
    swap(ptr_, other.ptr_);
    swap(count_ptr_, other.count_ptr_);
    swap(deleter_, other.deleter_);
  }

  T *get() const  noexcept { return ptr_; }
  T &operator*() const noexcept { return *get(); }
  T *operator->() const noexcept { return get(); }
  void reset(T *p = nullptr, DeleteFunc d = nullptr) {
    shared_ptr tmp(p, d);
    swap(tmp);
  }
  size_t use_count() const noexcept { return *count_ptr_; }
  explicit operator bool () const noexcept { return ptr_ != nullptr; }
private:
  T *ptr_ = nullptr;
  size_t *count_ptr_ = nullptr;
  DeleteFunc deleter_ = nullptr;
};
