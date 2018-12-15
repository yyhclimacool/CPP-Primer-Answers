#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <string>
#include <set>

#include "folder.h"

class Folder;

class Message {
public:
    friend class Folder;
    friend void swap(Message &, Message &);
    public:
    explicit Message(const std::string &s = std::string()) : content(s) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

private:
    private:
    std::string content;
    std::set<Folder *> folders;
    void add_to_folders(const Message &);
    void remove_from_folders(const Message &);
};

void swap(Message &, Message &);

#endif // _MESSAGE_H
