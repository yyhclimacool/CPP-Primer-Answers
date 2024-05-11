#include <string>
#include <iostream>
#include <memory>
#include <iterator>
#include <algorithm>

using namespace std;

class StrVec {
public:
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const std::initializer_list<string> &il);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
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
        for (auto q = first_free; q != element; )
            alloc.destroy(--q);
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

StrVec &StrVec::operator=(const StrVec &v) {
    cout << "Calling " << __func__ << endl;
    auto newdata = alloc_n_copy(v.begin(), v.end());
    free();
    element = newdata.first;
    first_free = cap = newdata.second;
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
