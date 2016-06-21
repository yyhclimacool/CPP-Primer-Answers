#ifndef _FOLDER_H_
#define _FOLDER_H_

#include <iostream>
#include <string>
#include <set>

using std::set;
using std::string;

class Folder{
public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);

    void addMsg(const Message *);
    void remMsg(const Message *);
private:
    set<Message *> messages;
};

#endif
