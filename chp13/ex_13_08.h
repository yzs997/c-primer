#pragma once

#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {} //exercise 13.5
	HasPtr &operator=(const HasPtr &rhs) // exercise 13.8
	{									 
		if (this != &rhs)
		{
			delete ps;
			ps = new std::string(*rhs.ps);
			i = rhs.i;
		}
		return *this;
	}
private:
	std::string *ps;
	int i;
};
