#include <map>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    map<string, size_t> word_map;
    string word;
    while (cin >> word)
    {
        for (char &c : word)
                c = tolower(c);
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        ++word_map[word];
    }
	for (auto p : word_map)
		cout << p.first << " occurs " << p.second << (p.second > 1 ? " times " : " time ") << endl;
    getchar();
    return 0;
}
