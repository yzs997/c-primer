#include <string>

#pragma once

class HasPtr
{
public:
	HasPtr(const std::string s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
	HasPtr &operator=(const HasPtr &rhs);
	~HasPtr();
private:
	std::string *ps;
	int i;
	std::size_t *use;
};

inline
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

inline
HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}
