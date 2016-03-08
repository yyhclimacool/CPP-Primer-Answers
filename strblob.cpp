#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class StrBlob{
public:
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> &il);
        bool empty() const { return data->empty();}
        size_type size() const { return data->size(); }
        void push_back(const string &str){ data->push_back(str); }
        void pop_back();
        string &front();
        const string &front() const;
        string &back();
        const string &back() const;
        size_type get_count() const { return data.use_count(); }
private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()){};

StrBlob::StrBlob(initializer_list<string> &il):data(make_shared<vector<string>>(il)){};

void StrBlob::check(size_type i, const string &str) const{
        if(i >= data->size())
                throw out_of_range(str);
}

void StrBlob::pop_back(){
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
}

string &StrBlob::front(){
        check(0, "front on empty StrBlob");
        return data->front();
}
const string &StrBlob::front() const {
        check(0, "const front on empty StrBlob");
        return data->front();
}

string &StrBlob::back(){
        check(0, "back on empty StrBlob");
        return data->back();
}

const string &StrBlob::back() const {
        check(0, "const back on empty StrBlob");
        return data->back();
}

int main(){
        initializer_list<string> il = {"hello", "how", "you", "doing"};
        StrBlob blob(il);
        {
                StrBlob b1 = blob;
                cout << b1.get_count() <<endl;
        }
        cout << blob.get_count() << endl;
}