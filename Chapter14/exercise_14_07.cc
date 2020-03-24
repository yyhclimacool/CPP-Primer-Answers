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

    ~String() {
        if (elements) {
            while (first_free != elements)
                alloc.destroy(--first_free);
            alloc.deallocate(elements, cap - elements);
        }
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
}
