#ifndef _FOLDER_H
#define _FOLDER_H

#include <set>

#include "message.h"

class Message;

class Folder {
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    size_t num_of_messages() const { return messages.size(); }

    void addMsg(Message *);
    void rmvMsg(Message *);
private:
    std::set<Message *> messages;
    void link_to_messages(const Folder &);
    void dislink_to_messages(const Folder &);
};

#endif // _FOLDER_H
