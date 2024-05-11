#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <memory>

using namespace std;

class QueryResult {
  friend ostream &operator<<(ostream &os, const QueryResult &r);
public:
  QueryResult(const string &s = "") : sought(s), lines(make_shared<set<vector<string>::size_type>>()), text(make_shared<vector<string>>()) {}
  QueryResult(const string &s, shared_ptr<set<vector<string>::size_type>> l, shared_ptr<vector<string>> t)
     : sought(s), lines(l), text(t) {}
private:
  string sought;
  shared_ptr<set<vector<string>::size_type>> lines;
  shared_ptr<vector<string>> text;
};

ostream &operator<<(ostream &os, const QueryResult &r) {
  os << r.sought << " occurs " << r.lines->size() << " times:" << endl;
  for (auto idx : *(r.lines))
    os << "\t(line " << idx << ") " << (*r.text)[idx] << endl;
  return os;
}

class TextQuery {
public:
  using line_no = vector<string>::size_type;

  TextQuery(istream &is);
  QueryResult query(const string &req);
private:
  shared_ptr<vector<string>> text;
  map<string, shared_ptr<set<line_no>>> word_lines;
};

TextQuery::TextQuery(istream &is) {
  string line;
  while(getline(is, line)) {
    if (line.empty()) continue;
    text->push_back(line);
    auto ln = text->size() - 1;
    istringstream iss(line);
    string word;
    while (iss >> word) {
      if (word_lines.find(word) == word_lines.end())
        word_lines[word] = make_shared<set<line_no>>();
      word_lines[word]->insert(ln);
    }
  }
}

QueryResult TextQuery::query(const string &s) {
  if (word_lines.find(s) == word_lines.end())
    return QueryResult();
  else {
    return QueryResult(s, word_lines[s], text);
  }
}

int main() {
}
