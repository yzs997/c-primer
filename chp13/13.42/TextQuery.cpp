#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
#include <algorithm>
#include <cstring>
#include <iterator>

using namespace std;

TextQuery::TextQuery(ifstream &ifs) : input(new StrVec)
{
	size_t line_no = 0;
	for (string line; std::getline(ifs, line); ++line_no)
	{
		input->push_back(line);
		istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			auto &nos = result[word];
			if (!nos)
				nos.reset(new set<size_t>);
			nos->insert(line_no);	
		}
	}
}

QueryResult TextQuery::query(const std::string &s) const
{
	static shared_ptr<set<size_t>> nodata(new std::set<size_t>);
	auto found = result.find(s);
	if (found == result.end())
		return QueryResult(s, nodata, input);
	else
		return QueryResult(s, found->second, input);

}

