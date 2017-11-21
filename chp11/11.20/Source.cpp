#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	map<string, size_t> map_word_count;
	string word;
	while (cin >> word)
	{
		auto p = map_word_count.insert({ word, 1 });
		if (!p.second)
			++p.first->second;
	}
	for (auto p : map_word_count)
		cout << p.first << '\t' << p.second << endl;
	getchar();
	return 0;
}