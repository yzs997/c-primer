#pragma once

#include <string>
#include <vector>
#include <iostream>

class X
{
public:
	X(std::string s = std::string()) : p_string(new std::string(s)), i(0)
	{
		std::cout << "X()" << std::endl;
	}
	X(const X &rhs) : p_string(new std::string(*rhs.p_string)), i(rhs.i)
	{ 
		std::cout << "X(cosnt X &rhs)" << std::endl;
	}
	X &operator=(const X &rhs)
	{
		if (this != &rhs)
		{
			delete p_string;
			p_string = new std::string(*rhs.p_string);
			i = rhs.i;
		}
		std::cout << "X &operator=(const X &rhs)" << std::endl;
		return *this;
	}
	~X()
	{
		delete p_string;
		std::cout << "~X()" << std::endl;
	}
private:
	std::string *p_string;
	int i;

};
