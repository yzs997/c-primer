#pragma once

#include <string>

class HasPtr
{
public:
    HasPtr(std::string s = std::string()) : ps(new std::string(s)), i(0){}
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i){}
    HasPtr &operator=(const HasPtr &rhs)
    {   std::string *new_ps = std::string(*rhs.ps);
        delete ps;
        ps = new_ps;
        i = rhs.i;
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
}
