#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    map<string, size_t> word_map;
    string word;
    while (cin >> word)
        ++word_map[word];
    for (auto p : word_map)
        cout << p.first << " occurs " << p.second << (p.second > 1 ? " times " : " time ") << endl;
    return 0;
}
