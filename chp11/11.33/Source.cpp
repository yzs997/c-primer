#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

map<string, string> build_map(ifstream&);
void word_transform(ifstream&, ifstream&);
const string &transform(const string&, const map<string, string>&);

int main()
{
	ifstream ifs_rule("rule.txt");
	ifstream ifs_text("text.txt");
	if (ifs_rule && ifs_text)
		word_transform(ifs_rule, ifs_text);
	else
		cerr << "can't find the documents" << endl;
	getchar();
	return 0;
}

void word_transform(ifstream &ifs_rules, ifstream &ifs_input)
{
	auto map_trans = build_map(ifs_rules);
	string string_line;
	while (getline(ifs_input, string_line))
	{
		istringstream iss_line(string_line);
		string string_word;
		bool bool_firstword = true;
		while (iss_line >> string_word)
		{
			if (bool_firstword)
				bool_firstword = false;
			else
				cout << " ";
			cout << transform(string_word, map_trans);
		}
		cout << endl;
	}
}

map<string, string> build_map(ifstream &ifs_rules)
{
	map<string, string> map_transform;
	string string_abbr;
	string string_full;
	while (ifs_rules >> string_abbr && getline(ifs_rules, string_full))
	{
		if (string_full.size() > 1)
			map_transform[string_abbr] = string_full.substr(1);
		else
			throw runtime_error("no rule for " + string_abbr);
	}
	return map_transform;
}

const string &transform(const std::string &string_word, const map<string, string> &map_trans)
{
	auto it_map = map_trans.find(string_word);
	if (it_map != map_trans.end())
		return it_map->second;
	else
		return string_word;
}
