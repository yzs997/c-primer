#pragma once

#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	//exercise 13.5
	HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
private:
	std::string *ps;
	int i;
};
