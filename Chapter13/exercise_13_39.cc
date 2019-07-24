#include <string>
#include <iostream>
#include <memory>

using namespace std;

class StrVec {
    public:
        StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
        StrVec(const StrVec &);
        StrVec &operator=(const StrVec &);
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
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return make_pair(data, uninitialized_copy(b, e, data));
}

void StrVec::free() {
    if (element) {
        for (auto q = first_free; q != element; )
            alloc.destroy(--q);
        alloc.deallocate(element, cap - element);
        element = first_free = cap = nullptr;
    }
}

void StrVec::reallocate() {
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

StrVec::StrVec(const StrVec &sv) {
    auto res = alloc_n_copy(sv.begin(), sv.end());
    element = res.first;
    first_free = cap = res.second;
}

StrVec &StrVec::operator=(const StrVec &sv) {
    auto newdata = alloc_n_copy(sv.begin(), sv.end());
    free();
    element = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void StrVec::reserve(size_t n) {
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
}

int main() {
}
