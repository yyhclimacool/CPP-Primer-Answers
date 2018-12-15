#include "folder.h"

Folder::Folder(const Folder &f) : messages(f.messages) {
    link_to_messages(f);
}

Folder &Folder::operator=(const Folder &rhs) {
    dislink_to_messages(*this);
    messages = rhs.messages;
    link_to_messages(*this);
    return *this;
}

Folder::~Folder() {
    dislink_to_messages(*this);
}

void Folder::addMsg(Message *m) {
    messages.insert(m);
    m->folders.insert(this);
}

void Folder::rmvMsg(Message *m) {
    messages.erase(m);
    m->folders.erase(this);
}

void Folder::link_to_messages(const Folder &f) {
    for (auto &m : f.messages) {
        m->folders.insert(this);
    }
}

void Folder::dislink_to_messages(const Folder &f) {
    for(auto &m : f.messages) {
        m->folders.erase(this);
    }
}
