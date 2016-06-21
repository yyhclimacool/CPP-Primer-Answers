#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <iostream>
#include <set>
#include <string>
#include "Folder.h"

using std::string;
using std::set;

class Message{
    friend class Folder;
    friend void swap(Message &, Message &);
public:
    explicit Message(const std::string &str = ""):contents(str){}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);
private:
    string contents;
    set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};
#endif
