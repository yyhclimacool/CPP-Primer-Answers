#include <iostream>
#include <string>
#include <set>

using namespace std;

class Message;

class Folder {
public:
    Folder(const std::string &s = "Main Folder")
        : folder_name_(s) {}
    Folder(const Folder &f);
    Folder &operator=(const Folder &f);
    ~Folder();
    void addMsg(Message *);
    void remMsg(Message *);
private:
    std::string folder_name_;
    std::set<Message *> messages_;
};

class Message {
    friend class Folder;
    friend void swap(Message &, Message &);
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
        f->addMsg(this);
    }

    void remove(Folder *f) {
        folders_.erase(f);
        f->remMsg(this);
    }
private:
    void add_to_folders(const Message &m) {
        for (auto &f : m.folders_)
            f->addMsg(this); // NOT f->addMsg(&m);
    }

    void remove_from_folders() {
        for (auto &f : folders_)
            f->remMsg(this);
    }
private:
    std::string contents_;
    std::set<Folder *> folders_;
};

void swap(Message &lhs, Message &rhs) {
    for (auto &f : lhs.folders_)
        f->remMsg(&lhs);
    for (auto &f : rhs.folders_)
        f->remMsg(&rhs);
    using std::swap;
    swap(lhs.contents_, rhs.contents_);
    swap(lhs.folders_, rhs.folders_);
    for (auto &f : lhs.folders_)
        f->addMsg(&lhs);
    for (auto &f : rhs.folders_)
        f->addMsg(&rhs);
}

void Folder::addMsg(Message *m) {
    cout << "Folder:" << this << " Add    Message:" << m << " with contents:" << m->contents() << endl;
    messages_.insert(m);
}
void Folder::remMsg(Message *m) {
    cout << "Folder:" << this << " Remove Message:" << m << " with contents:" << m->contents() << endl;
    messages_.erase(m);
}

Folder::Folder(const Folder &f)
    : folder_name_(f.folder_name_),
    messages_(f.messages_) {
    for (auto &m : messages_)
        m->folders_.insert(this);
}
Folder &Folder::operator=(const Folder &f) {
    for (auto &m : messages_)
        m->folders_.erase(this);
    folder_name_ = f.folder_name_;
    messages_ = f.messages_;
    for (auto &m : messages_)
        m->folders_.insert(this);
    return *this;
}
Folder::~Folder() {
    for (auto &m : messages_)
        m->folders_.erase(this);
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

    Folder new_temp_folder(outbox);
}
