#include <iostream>
#include <string>
#include <set>

using namespace std;

class Folder;

class Message {
    friend class Folder;
    friend ostream &operator<<(ostream &, const Message &);
public:
    Message(const string &str = "") : contents(str) {}
    Message(const Message &m) : contents(m.contents), folders(m.folders) {
        add_to_folders(m);
    }
    Message &operator=(const Message &m) {
        remove_from_folders();
        contents = m.contents;
        folders = m.folders;
        add_to_folders(m);
        return *this;
    }
    ~Message() {
        remove_from_folders();
    }

    void save(Folder &);
    void remove(Folder &);
private:
    string contents;
    set<Folder *> folders;

    void add_to_folders(const Message &m);
    void remove_from_folders();
};

ostream &operator<<(ostream &os, const Message &m) {
    os << "Content : <" << m.contents << "> in " << m.folders.size() << " Folders";
    return os;
}

class Folder {
public:
    Folder() = default;
    void addMsg(Message *m) {
        messages.insert(m);
    }

    void remMsg(Message *m) {
        messages.erase(m);
    }
private:
    set<Message *> messages;
};

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message &m) {
    for (auto & f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_folders() {
    for (auto & f : folders)
        f->remMsg(this);
}

int main() {
    Folder f1, f2, f3, f4;
    Message m1{"message_1"};
    Message m2{"message_2"};

    m1.save(f1);
    m1.save(f2);
    m1.save(f4);

    m2.save(f2);
    m2.save(f4);

    cout << "m1 = {" <<  m1 << "}" << endl;
    cout << "m2 = {" <<  m2 << "}" << endl;
    Message m3 = m1;
    cout << "m3 = {" <<  m3 << "}" << endl;
    Message m4;
    cout << "m4 = {" <<  m4 << "}" << endl;
    m4 = m2;
    cout << "NOW m4 = {" <<  m4 << "}" << endl;
}
