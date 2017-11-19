#include <set>
#include <string>
#pragma once

class Message;
class Folder;
void swap(Message &lhs, Message &rhs);

class Message
{
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const std::string &str = "") : contents(str) {}
	Message(const Message&);
	Message &operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
private:
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }
};

inline
Message::Message(const Message &rhs) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(rhs);
}

inline
Message &Message::operator=(const Message &rhs) : contents(rhs.contents), folers(rhs.folders)
{
	remove_from_Folders();
	add_to_Folders(rhs);
	return *this;
}
inline
Message::~Message()
{
	remove_from_Folders();
}

inline
void Message::save(Folder &f)
{
	folders.insert(f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

inline
void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : lhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}
