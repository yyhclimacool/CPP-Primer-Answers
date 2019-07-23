#include <iostream>
#include <string>
#include <set>

using namespace std;

class Message {
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
private:
    string contents;
    set<Folder *> folders;

    void add_to_folders(Message &m) {
        for (auto & f : m.folders)
            f->addMsg(this);
    }

    void remove_from_folders() {
        for (auto & f : m.folders)
            f->remMsg(this);
    }
};
