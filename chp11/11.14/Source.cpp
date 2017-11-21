#include <utility>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	string birthday;
	vector<pair<string, string>> vec;
	while (cin >> name >> birthday)
		vec.push_back(pair<string, string>(name, birthday));
	for (auto p : vec)
		cout << p.first << '\t' << p.second << endl;
	getchar();
	return 0;


}