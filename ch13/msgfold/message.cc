#include "message.h"

Message::Message(const Message &rhs) : content(rhs.content), folders(rhs.folders) {
    add_to_folders(rhs);
}

Message &Message::operator=(const Message &m) {
    remove_from_folders(*this);
    content = m.content;
    folders = m.folders;
    add_to_folders(m);
    return *this;
}

Message::~Message() {
    remove_from_folders(*this);
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.rmvMsg(this);
}

void Message::add_to_folders(const Message &msg) {
    for (auto &f : msg.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_folders(const Message &m) {
    for (auto &f : m.folders) {
        f->rmvMsg(this);
    }
}

void swap(Message &lhs, Message &rhs) {
    for (auto &f : lhs.folders) {
        f->rmvMsg(&lhs);
    }
    for (auto &f : rhs.folders) {
        f->rmvMsg(&rhs);
    }
    std::swap(lhs.content, rhs.content);
    std::swap(lhs.folders, rhs.folders);
    for (auto &f : lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto &f : rhs.folders) {
        f->addMsg(&rhs);
    }
}
