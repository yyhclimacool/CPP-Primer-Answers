#include <string>
#include <iostream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <string.h>

using namespace std;

class StrVec {
    friend void swap(StrVec &lhs, StrVec &rhs);
public:
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const std::initializer_list<string> &il);
    StrVec(const StrVec &);
    // 只声明不定义也是可以的，编译通过。
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(const StrVec &);
    StrVec &operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const string &);
    size_t size() const { return first_free - element; }
    size_t capacity() const { return cap - element; }
    void reserve(size_t );
    void resize(size_t );
    string *begin() const { return element; }
    string *end() const { return first_free; }

private:
    static allocator<string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void free();
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void reallocate();
    string *element;
    string *first_free;
    string *cap;
};

void swap(StrVec &lhs, StrVec &rhs) {
    using std::swap;
    swap(lhs.element, rhs.element);
    swap(lhs.first_free, rhs.first_free);
    swap(lhs.cap, rhs.cap);
}

allocator<string> StrVec::alloc = allocator<string>();

void StrVec::push_back(const string &s) {
    cout << "Calling " << __func__ << endl;
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    cout << "Calling " << __func__ << endl;
    auto data = alloc.allocate(e - b);
    return make_pair(data, uninitialized_copy(b, e, data));
}

void StrVec::free() {
    if (element) {
        cout << "Calling " << __func__ << endl;
        //for (auto q = first_free; q != element; )
        //    alloc.destroy(--q);
        std::for_each(element, first_free, [](string p) { alloc.destroy(&p); });
        alloc.deallocate(element, cap - element);
        element = first_free = cap = nullptr;
    }
}

void StrVec::reallocate() {
    cout << "Calling " << __func__ << endl;
    auto newsize = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newsize);
    auto data = newdata;
    auto elem = element;
    for (int i = 0; i != size(); ++i)
        alloc.construct(data++, std::move(*elem++));
    free();
    element = newdata;
    first_free = data;
    cap = element + newsize;
}

StrVec::StrVec(const std::initializer_list<string> &il) {
    cout << "Calling --- " << __func__ << endl;
    auto newdata = alloc_n_copy(std::begin(il), std::end(il));
    element = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &v) {
    cout << "Calling " << __func__ << endl;
    auto res = alloc_n_copy(v.begin(), v.end());
    element = res.first;
    first_free = cap = res.second;
}

StrVec::StrVec(StrVec &&rhs) noexcept 
    : element(rhs.element),
      first_free(rhs.first_free),
      cap(rhs.cap) {
    cout << "Calling move constructor" << endl;
    // 将源对象置为有效状态
    // 意味着可以安全的析构源对象，可以对源对象调用size, empty,可以对源对象赋值.
    rhs.element = rhs.first_free = rhs.cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &v) {
    cout << "Calling " << __func__ << endl;
    auto newdata = alloc_n_copy(v.begin(), v.end());
    free();
    element = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    cout << "Calling move operator=" << endl;
    if (this != &rhs) { // 保证自赋值也是安全的
        free();
        element = rhs.element;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.element = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    cout << "Calling " << __func__ << endl;
    free();
}

void StrVec::reserve(size_t n) {
    cout << "Calling " << __func__ << endl;
    if (n > capacity()) {
        auto newdata = alloc.allocate(n);
        auto data = newdata;
        auto elem = element;
        for (int i = 0; i != size(); ++i)
            alloc.construct(data++, std::move(*elem++));
        free();
        element = newdata;
        first_free = data;
        cap = element + n;
    }
}

void StrVec::resize(size_t n) {
    cout << "Calling " << __func__ << endl;
    if (n < size()) {
        auto dest = element + n;
        while (first_free != dest) {
            alloc.destroy(--first_free);
        }
    } else if (n > size()) {
        auto data = alloc.allocate(n);
        auto dest = data;
        auto elem = element;
        for (int i = 0; i < size(); ++i) 
            alloc.construct(dest++, std::move(*elem++));
        free();
        while (dest != (element + n))
            alloc.construct(dest++, "");
        element = data;
        first_free = cap = dest;
    }
}

/***************************************************************/

class String {
    friend ostream &operator<<(ostream &os, const String &s);
public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *s);
    String(const string &s) {
        cout << "Calling constructor with std::string object" << endl;
        auto res = alloc_n_copy(s.c_str(), s.c_str() + s.size());
        elements = res.first;
        cap = first_free = res.second;
    }
    String(const String &rhs) {
        cout << "Calling copy constructor" << endl;
        auto res = alloc_n_copy(rhs.begin(), rhs.end());
        elements = res.first;
        cap = first_free = res.second;
    }
    String(String &&rhs) 
        : elements(rhs.elements),
          first_free(rhs.first_free),
          cap(rhs.cap) {
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    String &operator=(const String &rhs) {
        cout << "Calling operator=" << endl;
        auto res = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = res.first;
        first_free = cap = res.second;
        return *this;
    }
    String &operator=(String &&rhs) {
        if (this != &rhs) {
            free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;

            rhs.elements = rhs.first_free = rhs.cap = nullptr;
        }
        return *this;
    }
    ~String() {
        free();
    }

    void free() {
        if (elements) {
            while (first_free != elements)
                alloc.destroy(--first_free);
            alloc.deallocate(elements, cap - elements);
        }
    }

    size_t size() const { return first_free - elements; }
    bool empty() const { return first_free == elements; }
    size_t capacity() const { return cap - elements; }

    char *begin() { return elements; }
    const char *begin() const { return elements; }
    char *end() { return first_free; }
    const char *end() const { return first_free; }
private:
    pair<char *, char *> alloc_n_copy(const char *start, const char *end) {
        char *newdata = alloc.allocate(end - start);
        char *st = newdata;
        char *res = std::uninitialized_copy(start, end, st);
        return {newdata, res};
    }
private:
    static std::allocator<char> alloc;
    char *elements;
    char *first_free;
    char *cap;
};

std::allocator<char> String::alloc;

ostream &operator<<(ostream &os, const String &s) {
    std::copy(s.elements, s.first_free, ostream_iterator<char>(os));
    return os;
}

String::String(const char *s) {
    char *data = alloc.allocate(strlen(s));
    char *start = data;
    auto res = uninitialized_copy(s, s + strlen(s), start);
    elements = data;
    first_free = cap = res;
}

int main() {
    StrVec svec;
    for (size_t i = 0; i != 100; ++i) {
        svec.push_back(to_string(i));
    }

    StrVec svec2(svec);
    StrVec svec3;
    svec3 = svec2;
    svec3.resize(12);

    StrVec svec4{"fine", "by", "me"};
    std::copy(svec4.begin(), svec4.end(), ostream_iterator<string>(cout, "|"));
    cout << endl;
}
