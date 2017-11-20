#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>

#include "StrVec.h"

class QueryResult;

class TextQuery
{
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<StrVec> input;
	std::map<std::string, std::shared_ptr<std::set<size_t>>> result;
};
