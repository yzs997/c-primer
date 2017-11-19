#pragma once



#include <string>
#include <iostream>

class HasPtr;
void swap(HasPtr &lhs, HasPtr &rhs);
bool operator<(const HasPtr &lhs, const HasPtr &rhs);

class HasPtr {
	friend void swap(HasPtr &lhs, HasPtr &rhs);
	friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

public:

	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

	//exercise 13.5

	HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}

	// exercise 13.8

	HasPtr &operator=(const HasPtr &rhs)

	{

		if (this != &rhs)

		{

			delete ps;

			ps = new std::string(*rhs.ps);

			i = rhs.i;

		}

		return *this;

	}

	//exercise 13.11

	~HasPtr()

	{

		delete ps;

	}

private:

	std::string *ps;

	int i;

};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "cal void swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
}

inline 
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}
