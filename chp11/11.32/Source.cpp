#include <map>
#include <string>
#include <utility>
#include <iostream>
#include <set>

using namespace std;

int main()
{
	std::multimap<string, string> multimap_author{

		{ "alan", "DMA" },

		{ "pezy", "LeetCode" },

		{ "alan", "CLRS" },

		{ "wang", "FTP" },

		{ "pezy", "CP5" },

		{ "wang", "CPP-Concurrency" }

	};
	set<string> set_author;
	for (auto p : multimap_author)
		set_author.insert(p.first);
	for (auto s : set_author)
	{
		auto it = multimap_author.find(s);
		auto count = multimap_author.count(s);
		while (count)
		{
			cout << it->first << " " << it->second << endl;
			++it;
			--count;
		}
	}
	getchar();
	return 0;
}