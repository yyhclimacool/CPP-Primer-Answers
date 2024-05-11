#include <iostream>
#include <string>
#include <set>

using namespace std;

class Message;

class Folder {
public:
    void addMsg(const Message &);
    void remMsg(const Message &);
};

class Message {
    friend class Folder;
public:
    Message(const std::string &s = "")
        : contents_(s) {}
    Message(const Message &rhs)
        : contents_(rhs.contents_),
          folders_(rhs.folders_){
        add_to_folders(rhs);
    }
    Message &operator=(const Message &rhs) {
        remove_from_folders();
        contents_ = rhs.contents_;
        folders_ = rhs.folders_;
        add_to_folders(rhs);
        return *this;
    }
    ~Message() {
        remove_from_folders();
    }

    std::string &contents() {
        return contents_;
    }

    const std::string &contents() const {
        return contents_;
    }

    void save(Folder *f) {
        folders_.insert(f);
        f->addMsg(*this);
    }

    void remove(Folder *f) {
        folders_.erase(f);
        f->remMsg(*this);
    }
private:
    void add_to_folders(const Message &m) {
        for (auto &f : m.folders_)
            f->addMsg(*this); // NOT f->addMsg(&m);
    }

    void remove_from_folders() {
        for (auto &f : folders_)
            f->remMsg(*this);
    }
private:
    std::string contents_;
    std::set<Folder *> folders_;
};

void Folder::addMsg(const Message &m) {
    cout << "Folder:" << this << " Add    Message:" << &m << " with contents:" << m.contents() << endl;
}
void Folder::remMsg(const Message &m) {
    cout << "Folder:" << this << " Remove Message:" << &m << " with contents:" << m.contents() << endl;
}

int main() {
    Folder inbox, outbox, trash;
    Message recruiter("Welcome to harvard");
    Message summer_camp("Welcome to Summer Camp");
    recruiter.save(&inbox);
    recruiter.save(&outbox);
    summer_camp.save(&outbox);
    summer_camp.save(&trash);

    Message new_forward_msg(recruiter);
}
