#include <set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main()

{

	unordered_map<string, size_t> unordered_map_word_count;
	string word;
	while (cin >> word)

		++unordered_map_word_count[word];

	for (auto p : unordered_map_word_count)

		cout << p.first << " occurs " << p.second << (p.second > 1 ? " times " : " time ") << endl;
	getchar();
	return 0;

}