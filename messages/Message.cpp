#include "Message.h"

void Message::save(Folder &rhs){
    folders.insert(&rhs);
    rhs.addMsg(this);
}

void Message::remove(Folder &rhs){
    folders.erase(&rhs);
    rhs.remMsg(this);
}

void Message::add_to_Folders(const Message &rhs){
    for(auto f : rhs.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders(){
    for(auto f:rhs.folders)
        f->remMsg(this);
}

Message::Message(const Message &rhs):contents(rhs.contents), folders(rhs.folders){
    add_to_Folders(*this);
}

Message::~Message(){
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs){
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(*this);
    return *this;
}

void swap(Message &lhs, Message &rhs){
    using std::swap;
     for(auto f : lhs.folders)
         f->remMsg(&lhs);
     for(auto f : rhs.folders)
         f->remMsg(&rhs);
     swap(lhs.contents, rhs.contents);
     swap(lhs.folders, rhs.folders);
     for(auto f : lhs.folders)
         f->addMsg(&lhs);
     for(auto f : rhs.folders)
         f->addMsg(&rhs);
}
