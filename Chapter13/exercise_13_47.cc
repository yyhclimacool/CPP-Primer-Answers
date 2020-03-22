#include <iostream>
#include <memory>
#include <string.h>
#include <iterator>
#include <algorithm>

using namespace std;

class String {
    friend ostream &operator<<(ostream &os, const String &s);
public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *s);
    String(const String &rhs) {
        cout << "Calling " << __func__ << endl;
        auto res = alloc_n_copy(rhs.begin(), rhs.end());
        elements = res.first;
        cap = first_free = res.second;
    }
    String &operator=(const String &rhs) {
        cout << "Calling " << __func__ << endl;
        auto res = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = res.first;
        first_free = cap = res.second;
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
    String str("fine by me");
    cout << str << endl;
    String str2(str);
    String str3;
    str3 = str;
}
