#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

void delete_one_author(std::multimap<string, set<string>> &authors, const string &author) {
    cout << "Initially: " << endl;
    std::for_each(authors.cbegin(), authors.cend(), [](const std::multimap<string, set<string>>::value_type &v) {
        cout << v.first << " ";
    });
    cout << endl;
    auto res = authors.equal_range(author);
    authors.erase(res.first, res.second);
    cout << "After erase " << author << endl;
    std::for_each(authors.cbegin(), authors.cend(), [](const std::multimap<string, set<string>>::value_type &v) {
        cout << v.first << " ";
    });
    cout << endl;
}

int main() {
    std::multimap<string, set<string>> authors = {
        {"Alan de boton", {"aaa", "bbb", "ccc"}},
        {"Alan lu", {"ddd", "eee", "fff"}}
    };

    delete_one_author(authors, "Alan lu");
    delete_one_author(authors, "No name");
}
