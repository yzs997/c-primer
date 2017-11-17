#pragma once

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <exception>

using std::vector;
using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::initializer_list;
using std::out_of_range;
using std::runtime_error;
using std::make_shared;


class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;

	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	StrBlob(const StrBlob &rhs) : data(make_shared<vector<string>>(*rhs.data)) {}
	StrBlob &operator=(const StrBlob &rhs)
	{
		data = make_shared<vector<string>>(*rhs.data);
	}

	size_type size() const { return data->size(); }
	bool empty() const { return data->size(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	string &front()
	{
		check(0, "front	_back on empty StrBlob");
		return data->front();
	}
	string &back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	const string &front() const
	{
		check(0, "front	_back on empty StrBlob");
		return data->front();
	}
	const string &back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	StrBlobPtr begin() const
	{
		return StrBlobPtr(*this);
	}
	StrBlobPtr end() const
	{
		return StrBlobPtr(*this, data->size());
	}
private:
	shared_ptr<vector<string>> data;
private:
	void check(size_type i, const string &msg) const
	{
		if (i >= size())
			throw out_of_range(msg);
	}
};

class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(const StrBlob &_strblob, size_t sz = 0) : wptr(_strblob.data), curr(sz) {}
	bool operator!=(const StrBlobPtr &rhs) { return curr != rhs.curr; }
	string &deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	StrBlobPtr &incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
private:
	size_t curr;
	weak_ptr<vector<string>> wptr;
private:
	shared_ptr<vector<string>> check(size_t i, const string &msg) const
	{
		auto ret = wptr.lock();
		if (!ret)
			throw runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())
			throw out_of_range(msg);
		return ret;
	}

};
