#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

class DefaultDeleter{
public:
  template<typename T> void operator()(T *p) { delete p; }
};

template<typename T, typename D = DefaultDeleter>
class unique_ptr {
public:
  unique_ptr(T *p = nullptr, const D &d = D())
    : ptr_(p), deleter_(d) {}

  unique_ptr(const unique_ptr &) = delete;
  unique_ptr &operator=(const unique_ptr &) = delete;

  unique_ptr(unique_ptr &&other) noexcept 
    : ptr_(other.ptr_),
      deleter_(std::move(other.deleter_)) {

    other.ptr_ = nullptr;
  }

  unique_ptr &operator=(unique_ptr &&other) noexcept {
    if (this != &other) {
      reset(other.ptr_, other.deleter_);
      other.ptr_ = nullptr;
    }
    return *this;
  }

  unique_ptr &operator=(std::nullptr_t) noexcept {
    deleter_(ptr_);
    return *this;
  }

  ~unique_ptr() noexcept {
    deleter_(ptr_);
  }

  void swap(unique_ptr &other) noexcept {
    using std::swap;
    swap(ptr_, other.ptr_);
    swap(deleter_, other.deleter_);
  }

  void reset(T *p = nullptr, const D &d = DefaultDeleter()) {
    deleter_(ptr_);
    ptr_ = p;
    deleter_ = d;
  }

  T *release() noexcept {
    T *tmp = ptr_;
    ptr_ = nullptr;
    return tmp;
  }

  T* get() const noexcept { return ptr_; }
  D& get_deleter() noexcept { return deleter_; }
  const D& get_deleter() const noexcept { return deleter_; }
  explicit operator bool() const noexcept { return ptr_ != nullptr; }
  T& operator*() const { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }
  T& operator[](size_t i) const { return ptr_[i]; }

private:
  T *ptr_;
  D deleter_;
};

#endif // UNIQUE_PTR_H
