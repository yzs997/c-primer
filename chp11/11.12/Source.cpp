#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main()
{
	string s;
	int i;
	vector<pair<string, int>> vec;
	while (cin >> s >> i)
		vec.push_back(pair<string, int>(s, i));
	for (auto p : vec)
		cout << p.first << '\t' << p.second << endl;
	getchar();
	return 0;
}
