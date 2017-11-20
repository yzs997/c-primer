#pragma once

#include <iostream>
#include <memory>
#include <set>

#include "StrVec.h"

class QueryResult;

std::ostream &print(std::ostream&, const QueryResult&);

class QueryResult
{
	friend std::ostream &print(std::ostream&, const QueryResult&);
public:
	QueryResult(const std::string &s, std::shared_ptr<std::set<size_t>> set, std::shared_ptr<StrVec> v)
		: word(s), nos(set), input(v) {}
private:
	std::string word;
	std::shared_ptr<std::set<size_t>> nos;
	std::shared_ptr<StrVec> input;
};
	
