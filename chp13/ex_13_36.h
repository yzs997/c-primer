#pragma once
#include <set>
#include "Message.h"

class Folder;
void swap(Folder&, Folder&);

class Folder
{
	friend class Message;
	friend void swap(Folder&, Folder&);	
public:
	Folder() = default;
	Folder(const Folder &);
	Folder& operator=(const Folder &);
	~Folder();
private:
	std::set<Message*> msgs;
private:
	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
	void add_to_Message(const Folder&);
	void remove_from_Message();
};

inline
Folder::Folder(const Folder &rhs) : msgs(rhs.msgs)
{
	add_to_Message(rhs);
}

inline
Folder &Folder::operator=(const Folder &rhs) : msgs(rhs.msgs)
{
	remove_from_Message();
	add_to_Message(rhs);
	return *this;
}

inline
Folder::~Folder()
{
	remove_from_Message();
}

inline 
void Folder::add_to_Message(const Folder &rhs)
{
	for (Message *m : rhs.msgs)
		m->folders.insert(this);
}

inline
void Folder::remove_from_Message()
{
	for (Message *m : msgs)
		m->folders.erase(this);
}

inline 
void swap(Folder &lhs, Folder &rhs)
{
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}	
